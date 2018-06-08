//
// Created by Lucky13 on 08.03.2018.
//

#include <iostream>
#include "LZ77.h"

using namespace std;

void LZ77::encode(const std::string &filename)
{
    int dict_buf_max = dict_size_Kb << 10, prev_buf_max  = buff_size_Kb << 10;

    string inpath = path_to_files + filename,
            outpath = path_to_LZ77ed + filename + ".lz77" + to_string(dict_size_Kb + buff_size_Kb);

    ifstream fin(inpath);
    ofstream fout(outpath);
    if(fin.is_open() && fout.is_open())
    {
        string window;
        int count = 0;
        char symb;
        while (count++ < prev_buf_max && fin.get(symb))//заполняем окно предпросмотром
            window += symb;

        int prev_buf_start = 0;//индекс начала буфера предпросмотра

        while (prev_buf_start < window.size())
        {
            NodeLZ77 nd = findMaxSubstr(window, dict_buf_max, prev_buf_start);
            int len = nd.len + 1;
            prev_buf_start += len;

            count = 0;
            char symb;
            while (count++ < len && fin.get(symb))
                window += symb;

            //если размер строки стал больше, чем рамер окна, то надо его обрезать
            if (window.size() > dict_buf_max + prev_buf_max) {
                int dif = window.size() - dict_buf_max - prev_buf_max;
                window = window.substr(dif);
                prev_buf_start -= dif;
            }

            //запись блока в файл
            fout << nd.ch
                 << (char) (nd.offs / 256) << (char) (nd.offs % 256)
                 << (char) (nd.len / 256) << (char) (nd.len % 256);
            //запись чисел в виде n = l*256 + m
        }
        fout.close();
        fin.close();
    }
}



NodeLZ77 LZ77::findMaxSubstr(string &s, int dictBuf, int currSymb)
{

    int indexSubstr = currSymb - dictBuf > 0 ? currSymb - dictBuf : 0;

    int maxLen = 0;//длина максимальной подстроки
    int maxIndexSubstr = currSymb;//индекс начала максимальной подстроки

    while (indexSubstr < currSymb) //максимальная подстрока должна начинаться в словаре
    {
        int len = 0;//длина подстроки
        while (currSymb + len < s.size() - 1 && s[indexSubstr + len] == s[currSymb + len])
            ++len;

        if (len > maxLen)//перезаписываем данные о максимальной подстроке
        {
            maxLen = len;
            maxIndexSubstr = indexSubstr;
        }

        ++indexSubstr;//следующий символ
    }
    return NodeLZ77(currSymb - maxIndexSubstr, maxLen, s[currSymb + maxLen]);
}

void LZ77::decode(const string& filename)
{
    string inpath = path_to_LZ77ed + filename + ".lz77" + to_string(dict_size_Kb + buff_size_Kb),
           outpath = path_to_deLZ77ed + filename + ".unlz77" + to_string(dict_size_Kb + buff_size_Kb);

    ifstream fin(inpath);
    ofstream fout(outpath);


    string res;
    if(fin.is_open() && fout.is_open())
    {
        int dict_buf_max = dict_size_Kb << 10;//максимальный размер буфера словаря

        char symbol;
        while(fin.get(symbol))
        {
            int offs, len;

            //чтение закодированных чисел
            char temp[2];
            fin.read(temp, sizeof(char) * 2);
            offs = (unsigned char) temp[0] * 256 + (unsigned char) temp[1];

            fin.read(temp, sizeof(char) * 2);
            len = (unsigned char) temp[0] * 256 + (unsigned char) temp[1];

            int start = res.length() - offs;
            for (int j = 0; j < len; ++j) {
                res += res[start + j];
                fout << res[start + j];
            }
            res += symbol;

            if(res.size() > dict_buf_max)
                res = res.substr(res.size() - dict_buf_max);

            fout << symbol;
        }
        fin.close();
        fout.close();
    }
    else
        throw std::ios_base::failure("file not open");

}

void LZ77::writeDataCompression() {
    ofstream fout(path_to_route_folder + "datacompression.csv");
    fout << "file_num,compr" << endl;
    if(fout.is_open())
    {
        for(int i = 0; i < 36; ++i) {
            struct stat buf;
            string filename = (path_to_files + to_string(i + 1));
            stat(filename.c_str(), &buf);
            off_t size_original = buf.st_size;

            filename = (path_to_LZ77ed + to_string(i + 1) + ".lz77" + to_string(dict_size_Kb + buff_size_Kb));
            stat(filename.c_str(), &buf);
            off_t size_encoded = buf.st_size;

            fout << (double)size_encoded/(double)size_original << endl;
        }
        fout.close();
    }
}