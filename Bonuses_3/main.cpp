

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int bitap_search(string text, string pattern)
{
    unsigned long R;
    unsigned long pattern_mask[256];
    int m = pattern.size();

    if (pattern[0] == '\0')
        return -1;
    if (m > 63)
        return -2;

    R = ~1;
    for (int i = 0; i < 256; ++i)
        pattern_mask[i] = ~0;

    for (int i = 0; i < m; ++i)
        pattern_mask[pattern[i]] &= ~(1UL << i);

    for (int i = 0; text[i] != '\0'; ++i)
    {
        R |= pattern_mask[text[i]];
        R <<= 1;

        if (0 == (R & (1UL << m)))
            return (i - m) + 1;
    }

    return -1;
}
string findPattern(string t, string p)
{
    int pos = bitap_search(t, p);
    if (pos == -1)
        return "No Match"; // если нет подстроки
    else if(pos == -2)
        return "Pattern is too long!"; // если паттерн больше 63 символов!
    else
        return "Pattern found at position : " + to_string(pos); // позиция подстроки
}

int main(int argc, char **argv)
{

    int n;
    fstream fin;
    fstream fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    if(fin.is_open()) {
        string N;
        getline(fin,N);
        n = atoi( N.c_str());
        for (int i = 0; i < n; i++) {
            string t;
            string p;
            getline(fin,t);
            getline(fin,p);
            fout << findPattern(t, p) << endl;
        }
        fout.close();
        fin.close();
    }


}
