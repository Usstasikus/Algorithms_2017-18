#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Node.h"
class ReadWriter
{
private:

    std::fstream fin;
    std::fstream fout;

public:

    ~ReadWriter()
    {
        fin.close();
        fout.close();
    }

    ReadWriter()
    {
        fin.open("input.txt", std::ios::in);
        fout.open("output.txt", std::ios::out);
    }

    //read 1 line
    void readString(std::string& s)
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        std::getline(fin, s);
    }

    //Write string
    void writeString(std::string& s)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        fout << s;
    }

    //Write encoded string, format:
    //n
    //offs len ch offs len ch ...
    //Example:
    //3
    //0 0 a 0 0 b 1 1 c
    void writeCode(std::vector<Node>& v)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        fout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++)
            fout << v[i].offs << " " << v[i].len << " " << v[i].ch << " ";
    }

    // read 1 int value
    int readInt()
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        int n;
        fin >> n;
        return n;
    }

    //read data in arr, arr should be initialized before this method
    void readCode(Node* arr, int n)
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
            arr[i] = Node(offs, len, ch);
        }
    }


};