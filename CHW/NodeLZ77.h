//
// Created by Stas Don on 15/03/2018.
//

#ifndef CHW_NODELZ77_H
#define CHW_NODELZ77_H

//block look like:  <offs,len,ch> example: <3,2,d>
class NodeLZ77
{
public:
    int offs;
    int len;
    char ch;

    NodeLZ77(int o, int l, char c) : offs(o), len(l), ch(c)
    {};

    NodeLZ77()
    {};

};

#endif //CHW_NODELZ77_H
