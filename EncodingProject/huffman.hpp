//
// Created by Stas Don on 09/03/2018.
//
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include <map>

#ifndef ENCODINGPROJECT_HUFFMAN_HPP
#define ENCODINGPROJECT_HUFFMAN_HPP


struct HuffNode
{
public:
    int index;
    int freq;
    char symb;

    HuffNode *left, *right;

    HuffNode(int ind, int fr, char sb)
    {
        left = right = nullptr;
        index = ind;
        freq = fr;
        symb = sb;
    }

    ~HuffNode()
    {
        delete left;
        delete right;
    }

};

struct compare {

    bool operator()(HuffNode* l, HuffNode* r)
    {

//        if(l->freq == r->freq)
//        {
//            if(r->index <= -1)
//                return true;
//            if(l->index <= -1)
//                return false;
//            return l->index < r->index;
//        }
//        return (l->freq > r->freq);

        if(l->freq == r->freq)
        {
//            if(r->index <= -1)
//                return true;
//            if(l->index <= -1)
//                return false;
            if(l->index < 0 && r->index >= 0)
                return false;
            if(l->index >= 0 && r->index < 0)
                return true;
            if(l->index < 0 && r->index < 0)
                return l->index > r->index;
            return l->index < r->index;
        }
        return (l->freq > r->freq);
    }
};



class Huffman
{
public:
    void build();
    void addChance (int chance);
//    std::string get (int i)
//    {
//        return codes[i].first + " " + codes[i].second;
//    }

    void setCodes(HuffNode *top, std::string code);

    void huff();

    void encode(const std::string& filename);
    void decode(const std::string& filename);

private:
    void countSymbols(std::string text);
    void writeEncodedText(const std::string& text, const std::string& filename);
//    int isAlreadyAdded(char symb);

private:
    std::priority_queue<HuffNode*, std::vector<HuffNode*>, compare> min_heap;
    std::map<char, std::string> codes;

    int n = 0;
    int curr_pair = 0;
};


#endif //ENCODINGPROJECT_HUFFMAN_HPP
