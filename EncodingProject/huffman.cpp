//
// Created by Stas Don on 09/03/2018.
//

#include "huffman.hpp"

using namespace std;

void Huffman::huff()
{
    HuffNode *left, *right, *top;
    while (min_heap.size() != 1) {
        left = min_heap.top();
        min_heap.pop();

        right = min_heap.top();
        min_heap.pop();
        top = new HuffNode(--curr_pair, left->freq + right->freq, 0);

        top->left = left;
        top->right = right;

        min_heap.push(top);
    }
    setCodes(min_heap.top(), "");

}

void Huffman::setCodes(HuffNode *top, string code)
{
    int index = top->index;
    if(index >= 0)
        codes[index] = code;
    else
    {
        setCodes(top->left, code + "0");
        setCodes(top->right, code + "1");
    }
}

void Huffman::build()
{
    // запускает алгоритм (после того как были добавлены все элементы)
    huff();
}

void Huffman::addChance(int chance)
{
//    codes.emplace_back("");
//    min_heap.push(new HuffNode(n, chance));
//    n++;
    // добавляет элемент в список (дерево, все зависит от реализации)
}


void readString(std::string &s, const std::string name)
{
    std::fstream fin;
    fin.open(name, std::ios::in);
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");

    std::getline(fin, s);
    fin.close();
}

void Huffman::encode(const string& filename)
{
    string text;
    readString(text, filename + ".tohaff");
    countSymbols(text);//записываем символы
    huff();//запускаем кодирование символов
    writeEncodedText(text, filename);
}

char stringToByte(string byte_string){
    char byte = 0;
    int multiplier = 128;
    for (int i = 0; i < 8 && i < byte_string.length(); ++i)
    {
        byte += (byte_string[i] - '0') * multiplier;
        multiplier /= 2;
    }
    return byte;
}

void Huffman::writeEncodedText(const string& text, const string& filename)
{
    fstream fout;
    fout.open(filename + ".haff");

    fout<<to_string(codes.size())<<endl;//записываем кол-во символов

    map<char, string>::const_iterator iterator = codes.begin();//итератор для записи кодов
    while(iterator != codes.end())
        fout<<iterator->first<<" "<<iterator->second<<endl;//записываем коды в файл

    string byte_string = "";

    for (int i = 0; i < text.length(); ++i)
    {
        byte_string += codes[text[i]];
        if(byte_string.length() >=8 || i == text.length() - 1){
            char byte = stringToByte(byte_string);
            fout << byte;
            if(i != text.length() - 1)
                byte_string = byte_string.substr(8, byte_string.length() - 8);
//            fout << codes[text[i]];
        }
    }//записываем текст в файл

    fout.close();//закрываем файл
}


void Huffman::decode(const std::string &filename)
{

}




void Huffman::countSymbols(string text)
{
    unsigned long int len = text.length();

    vector<HuffNode *> nodes;

    for (int i = 0; i < len; ++i)
    {
        int index;//индекс вхождения прочитанного элемента
        if(codes.find(text[i]) == codes.end())//если нет такого
        {
            codes[text[i]] =  "";//записываем в коды
            nodes.push_back(new HuffNode(nodes.size(), 1, text[i]));//добавляем кол-во его вхождений
        }
        else
            nodes[index]->freq += 1;//увеличиваем кол-во вхождений символа
    }

    n = nodes.size();

    for(int i = 0; i < n; ++i)
        min_heap.push(nodes[i]);//добавляем в кучу
}
