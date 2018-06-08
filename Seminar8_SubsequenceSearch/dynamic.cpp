#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string getLCS(string &x, string &y);

string getLCS(string &x, string &y)
{
    int xlen = x.length(), ylen = y.length();
    int lengths[xlen + 1][ylen + 1];

    //зануляем нулевые элементы
    for (int i = 0; i <= xlen; ++i)
        lengths[i][0] = 0;
    for (int i = 0; i <= ylen; ++i)
        lengths[0][i] = 0;

    //считаем расстояния для префиксов
    for (int i = 1; i <= xlen; ++i)
    {
        for (int j = 1; j <= ylen; ++j)
        {
            if(x[i - 1] == y[j - 1])
                lengths[i][j] = lengths[i - 1][j - 1] + 1;
            else
                lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1]);
        }
    }

    //сборка строки
    string res = "";
    int i = xlen, j = ylen;
    while(i != 0 && j != 0){
        if(x[i - 1] == y[j - 1])
        {
            res = x[i - 1] + res;
            --i;
            --j;
        }
        else if(lengths[i - 1][j] < lengths[i][j - 1])
            --j;
        else
            --i;
    }
    return res;
}

int main()
{
    string x;
    string y;
    string res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, x);
        getline(fin, y);
        fin.close();
    }

    res = getLCS(x, y);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}