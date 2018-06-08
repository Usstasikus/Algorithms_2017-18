//
// Created by Stas Don on 19/03/2018.
//

//
// Created by Stas Don on 07/03/2018.
//

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "ReadWriter.h"

using namespace std;



void ReadWriter::readText(std::string &s, const std::string name)
{
    fin.open(name, std::ios::in);
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");
    char symb;
    while(fin.get(symb)){
        s += symb;
    }
    fin.close();
}

unsigned char ReadWriter::stringToByte(string &byte_string)
{
    int multiplier = 128;
    unsigned char byte = 0;

    for (int i = 0; i < 8  && i < byte_string.length(); ++i)
    {
        byte += (byte_string[i] - '0') * multiplier;
        multiplier /= 2;
    }


    return byte;
}

void ReadWriter::writeBytes(string &byte_string, fstream &fout){
    unsigned char byte = 0;
    do
    {
        byte = stringToByte(byte_string);

        if(byte_string.length() >= 8)
            byte_string = byte_string.substr(8, byte_string.length() - 8);
        fout << byte;

    }while(byte_string.length() >= 8);
}

string ReadWriter::byteToString(char &byte_signed, char amount){
    unsigned char byte = byte_signed;
    string res;
    for (int i = 0; i < amount; ++i, byte = byte << 1)
        res += std::to_string(byte / 128);

    return res;
}

void ReadWriter::writeEncodedText(unordered_map<char, string> &codes, const string& source_text_filename, const string& filename)
{
    fstream fout;
    fout.open(filename, std::ios::out);
    if (fout.is_open())
    {
        fout << to_string(0) << '\n';//оставляем место для длины неиспользуемых конечных битов
        fout << to_string(codes.size()) << '\n';//записываем кол-во символов

        for (auto &code : codes)
            fout << code.first << code.second << '\n';//записываем коды в файл

        string byte_string = "";
        int unused_bites;

        fstream fin;
        fin.open(source_text_filename);
        if(fin.is_open()) {
            char symb;
            while (fin.get(symb))
            {
                byte_string += codes[symb];//записываем а результирующую строку битовое представление кода
                if (byte_string.length() >= 8)//если длина строки больше 8, то можно записать байты в файл
                    writeBytes(byte_string, fout);
            }//записываем текст в файл

            unused_bites = (8 - byte_string.size()) % 8;
            if (!byte_string.empty())//если остался незаписанный кусок
                fout << stringToByte(byte_string);

            fin.close();
        }
        fout.close();//закрываем файл

        fout.open(filename);
        fout << to_string(unused_bites);//записываем кол-во ненужнох бит в конце файла
        fout.close();
    }
    else
        throw std::ios_base::failure("file not open");
}

void ReadWriter::writeDecodedText(const std::string &encoded_text_filename,
                                  const std::string &filename)
{
    fout.open(filename, std::ios::out);
    if (fout.is_open())
    {
        string code;
        unordered_map<std::string, char> decoding_map;
        fstream fin;
        fin.open(encoded_text_filename);
        if (fin.is_open()) {

            string line;
            std::getline(fin, line);
            int unused_bites = stoi(line);//считываем кол-во неиспользуемых бит

            std::getline(fin, line);
            int n = stoi(line);//кол-во кодов


            for (int i = 0; i < n; i++) //считываем коды в словарь
            {
                char symb, temp;
                string code;
                fin.get(symb);

                while ((temp = fin.get()) != '\n')
                    code += temp;
                decoding_map[code] = symb;
            }

            char symb, new_symb;
            fin.get(symb);

            while (fin.get(new_symb))
            {
                string temp_string = byteToString(symb);
                for(char code_symb: temp_string)
                {
                    code += code_symb;
                    if (decoding_map.find(code) != decoding_map.end())
                    {
                        fout << decoding_map[code];
                        code = "";
                    }
                }
                symb = new_symb;
            }
            code += byteToString(symb, 8 - unused_bites);
            if (decoding_map.find(code) != decoding_map.end())
                fout << decoding_map[code];
            fin.close();
        }
        else
            throw std::ios_base::failure("file not open");

        fout.close();
    }
    else
        throw std::ios_base::failure("file not open");
}

void
ReadWriter::readEncodedText(std::string &text, std::unordered_map<std::string, char> &decoding_map, int &unused_bites, const std::string &filename) {
    fin.open(filename);
    if (fin.is_open()) {
        string line;

        std::getline(fin, line);
        unused_bites = stoi(line);//считываем кол-во неиспользуемых бит

        std::getline(fin, line);
        int n = stoi(line);//кол-во кодов


        for (int i = 0; i < n; i++) //считываем коды в словарь
        {
            char symb, temp;
            unsigned char code_len;
            string code;
            fin.get(symb);

            while ((temp = fin.get()) != '\n')
                code += temp;
            decoding_map[code] = symb;
        }

        char byte;
        while (fin.get(byte)) //считываем закодированный текст
            text += byteToString(byte);

        fin.close();
    }
    else
        throw std::ios_base::failure("file not open");
}

void ReadWriter::readCode(NodeLZ77 *arr, int n)
{
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");

    int offs, len;
    char ch;
    for (int i = 0; i < n; i++)
    {
        fin >> offs;
        fin >> len;
        fin >> ch;
        arr[i] = NodeLZ77(offs, len, ch);
    }
    fin.close();
}

NodeLZ77* ReadWriter::readEncodedText(int &n, const std::string &filename) {

    fin.open(filename, ios::in | ios::binary);
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");

    fin >> n;

    NodeLZ77* arr = new NodeLZ77[n];
    int offs, len;
    char ch;
    char temp[2];
    for (int i = 0; i < n; i++)
    {

        fin.read(temp, sizeof(char) * 2);
        offs = (unsigned char)temp[0] * 256 + (unsigned char)temp[1];

        fin.read(temp, sizeof(char) * 2);
        len = (unsigned char)temp[0] * 256 + (unsigned char)temp[1];

        fin.get(ch);
        arr[i] = NodeLZ77(offs, len, ch);
    }
    return arr;
}

void ReadWriter::writeText(const std::string &text,const std::string &filename)
{
    fout.open(filename, std::ios::out | ios::binary);
    if (fout.is_open())
    {
        fout << text;
        fout.close();
    }
    else
        throw std::ios_base::failure("file not open");
}

void ReadWriter::writeEncodedText(const std::vector<NodeLZ77> &nodes, const std::string &filename)
{
    fout.open(filename, std::ios::out | ios::binary);
    if (fout.is_open())
    {
        int n = nodes.size();
        fout << n << '\n';
        for(auto node: nodes)
        {
            fout.write(reinterpret_cast<const char *>(&node.offs), sizeof(int));
            fout.write(reinterpret_cast<const char *>(&node.len), sizeof(int));
            fout << node.ch;
        }
        fout.close();
    }
    else
        throw std::ios_base::failure("file not open");
}