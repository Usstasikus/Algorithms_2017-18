//
// Created by Stas Don on 07/03/2018.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <sys/stat.h>

#include "ReadWriter.h"

#ifndef CHW_HUFFMAN_H
#define CHW_HUFFMAN_H


struct HuffNode
{
public:
    bool is_synt;
    int freq;
    char symb;

    HuffNode *left, *right;

    HuffNode(bool synt, int fr, char sb)
    {
        left = right = nullptr;
        is_synt = synt;
        freq = fr;
        symb = sb;
    }

    ~HuffNode()
    {
        delete left;
        delete right;
    }

};


struct compare
{
    bool operator()(HuffNode* l, HuffNode* r)
    {
        return (l->freq > r->freq);
    }
};


class Huffman
{
public:

    ///Построение дерева кодов алгоритмом Хаффмана
    void huff();

    /// Архивация файла с помощью алгоритма Хаффмана
    /// \param filename - имя файла
    void encode(const std::string& filename);

    /// Разархивация файла с помощью алгоритма Хаффмана
    /// \param filename - имя файла
    void decode(const std::string& filename);

    void writeDataCompression();

private:
    /// Подсчет вхождений элементов
    /// \param text - текст
    void countSymbols(const std::string &source_filename);
//    void countSymbols(const std::string &filename);
    void setCodes(HuffNode *top, std::string code);

//    int isAlreadyAdded(char symb);

public:
    const std::string path_to_route_folder = "../resources/Huffman/";

private:
    ReadWriter readWriter;
    std::priority_queue<HuffNode*, std::vector<HuffNode*>, compare> min_heap;
    std::unordered_map<char, std::string> codes;


    const std::string path_to_files = "../resources/toencode/";
    const std::string path_to_huffed = path_to_route_folder + "Encoded/";
    const std::string path_to_dehuffed = path_to_route_folder + "Decoded/";
};
#endif //CHW_HUFFMAN_H
