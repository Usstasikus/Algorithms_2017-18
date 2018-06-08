// КДЗ по дисциплине Алгоритмы и структуры данных. 2017-2018 уч.год
// Дон Станислав Ваелрианович, группа БПИ-163, дата (13.03.2018)
// Среда разработки - CLion 2017 3.4,
// Состав проекта:
//                  main.cpp,
//                  huffman.h, huffman.cpp,
//                  shennon.h, shennon.cpp,
//                  LZ77.h, LZ77.cpp
//
// Сделано:
//          Архивация алгоритмами:
//                                Хаффмана
//                                Шеннона-Фано
//                                LZ77(размер скользящего окна 5 Кб, размер словаря 4 Кб)
//                                LZ77(размер скользящего окна 10 Кб, размер словаря 8 Кб)
//                                LZ77(размер скользящего окна 20 Кб, размер словаря 16 Кб)
//          Разархивация алгоритмами:
//                                Хаффмана
//                                Шеннона-Фано
//                                LZ77(размер скользящего окна 5 Кб, размер словаря 4 Кб)
//                                LZ77(размер скользящего окна 10 Кб, размер словаря 8 Кб)
//                                LZ77(размер скользящего окна 20 Кб, размер словаря 16 Кб)
//          Отчет

#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

#include "shennonFano.h"
#include "huffman.h"
#include "LZ77.h"

using namespace std;
unsigned long int countSymbols(const string &filename, unordered_map<char, int> &symb_map)
{
    fstream fin;
    fin.open(filename);
    unsigned long int n = 0;
    if(fin.is_open())
    {
        char symb;
        while(fin.get(symb)){
            ++n;
            if(symb_map.find(symb) == symb_map.end())
                symb_map[symb] = 1;
            else
                symb_map[symb] += 1;
        }
    }
    return n;
}

void getFileSizes()
{
    ofstream fout("../resources/fsizes.csv");
    fout << "fsize" << endl;
    if(fout.is_open())
    {
        for(int i = 0; i < 36; ++i) {
            struct stat buf;
            string filename = ("../resources/toencode/" + to_string(i + 1));
            stat(filename.c_str(), &buf);
            off_t size_original = buf.st_size;

            fout << (double)size_original << endl;
        }
        fout.close();
    }
}


void countEntropy(){
    ofstream fout("../resources/entropy.csv");

    fout << "file,entropy" << endl;
    if(fout.is_open())
    {
        for(int i = 0; i < 36; ++i) {
            unordered_map<char, int> symb_map;
            unsigned long int n = countSymbols("../resources/toencode/" + to_string(i + 1), symb_map);
            double entropy = 0;
            int base = symb_map.size();
            for(auto it = symb_map.begin(); it != symb_map.end(); ++it)
            {
                long double w = it->second / (double)n;
                entropy += w * log(w) / log(base);
            }
            fout << i + 1 << "," << -entropy << endl;
        }
        fout.close();
    }
}

void symbFrequency(){

    for(int i = 0; i < 36; ++i)
    {
        ofstream fout("../resources/symbolFreqs/symbolfreqs" + to_string(i + 1) + ".csv");
        unordered_map<char, int> symb_map;
        unsigned long int n = countSymbols("../resources/toencode/" + to_string(i + 1), symb_map);
        double entropy = 0;
        int base = symb_map.size();
        int count = 0;

        fout << "symb_num,compr" << endl;
        for(auto it = symb_map.begin(); it != symb_map.end(); ++it)
        {
            long double w = it->second / (double)n;
            fout << ++count << "," << w << endl;
        }
        fout << endl;
    }
}

void experiment()
{
    fstream fout;
    long long time = 0;

    fout.open("reportHuffman", ios_base::out);
    fout << "Huffman" <<endl;
    fout << "Encoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            Huffman huff;
            auto start = chrono::high_resolution_clock::now();
            huff.encode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }

    fout << "Decoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            Huffman huff;
            auto start = chrono::high_resolution_clock::now();
            huff.decode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }

    fout.open("reportShennonFano", ios_base::out);

    fout << "Sheenon-Fano" <<endl;
    fout << "Encoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            ShannonFano sf;
            auto start = chrono::high_resolution_clock::now();
            sf.encode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }

    fout << "Decoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            ShannonFano sf;
            auto start = chrono::high_resolution_clock::now();
            sf.decode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }
    fout.close();

    fout.open("reportLZ775", ios_base::out);
    fout << "LZ775" <<endl;
    fout << "Encoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            LZ77 lz77;
            auto start = chrono::high_resolution_clock::now();
            lz77.encode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }

    fout << "Decoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            LZ77 lz77;
            auto start = chrono::high_resolution_clock::now();
            lz77.decode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }
    fout.close();

    fout.open("reportLZ7710", ios_base::out);

    fout << "LZ7710" <<endl;
    fout << "Encoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            LZ77 lz77(8, 2);
            auto start = chrono::high_resolution_clock::now();
            lz77.encode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }

    fout << "Decoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            LZ77 lz77(8, 2);
            auto start = chrono::high_resolution_clock::now();
            lz77.decode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }
    fout.close();

    fout.open("reportLZ7720", ios_base::out);
    fout << "LZ7720" <<endl;
    fout << "Encoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            LZ77 lz77(16, 4);
            auto start = chrono::high_resolution_clock::now();
            lz77.encode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }

    fout << "Decoding" <<endl;
    for(int i = 0; i < 36; i++) {
        for (int k = 0; k < 20; ++k) {
            LZ77 lz77(16, 4);
            auto start = chrono::high_resolution_clock::now();
            lz77.decode(to_string(i + 1));
            auto end = chrono::high_resolution_clock::now();
            time += chrono::duration_cast<chrono::nanoseconds>(end-start).count()/20;
        }
        fout << i + 1 << ": " << time << endl;
        time = 0;
    }

    fout.close();

}

int main()
{



    Huffman huff;
    huff.writeDataCompression();

    ShannonFano sf;
    sf.writeDataCompression();

    LZ77 lz775;
    lz775.writeDataCompression();

    LZ77 lz7710(8, 2);
    lz7710.writeDataCompression();

    LZ77 lz7720(16, 4);
    lz7720.writeDataCompression();

//    countEntropy();
//    getFileSizes();
//    symbFrequency();



    return 0;

}