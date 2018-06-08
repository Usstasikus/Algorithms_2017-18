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
    string res = "";

    for (int i = 0; i < xlen; ++i)
    {
        string new_res = "";
        int curr_symb_x = i;
        int last_found_y = 0;

        while (last_found_y < ylen && x[curr_symb_x] != y[last_found_y])//смотрим, есть ли первый элемент
            ++last_found_y;
        if(last_found_y == ylen)//если нет первого элемента - пропускаем итерацию
            continue;


        while (curr_symb_x < xlen)
        {
            int curr_symb_y = last_found_y;
            while (curr_symb_y < ylen && x[curr_symb_x] != y[curr_symb_y])
                ++curr_symb_y;
            if(curr_symb_y < ylen){
                new_res += x[curr_symb_x];
                last_found_y = ++curr_symb_y;
            }
            ++curr_symb_x;
        }

        if(res.length() < new_res.length())
            res = new_res;
    }

    //сборка строки

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