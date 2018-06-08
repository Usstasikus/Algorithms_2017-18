#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
//void getBorders(string input, int* br, int* brs)
//{
//    int length = input.length();
////    vector<int> br(length);
//    br[0] = 0;
//    brs[0] = 0;
//
//    vector<int> indices;
//    for (int i = 1; i < length; ++i)
//    {
//        int j = br[i - 1];
//        while (j > 0 && input[i] != input[j])
//            j = br[j - 1];
//        if (input[i] == input[j])
//            ++j;
//        br[i] = j;
//
//        if(br[i] + 1 - 1 != input[i])
//            brs[i] = br[i];
//        else
//            brs[i] = brs[br[i]];
//    }
//}

//void getBorders(string input, vector<int> &br, vector<int> &brs)
//{
//    int length = input.length();
//    br[0] = 0;
//    brs[0] = 0;
//
//    vector<int> indices;
//    for (int i = 1; i < length; ++i)
//    {
//        int j = br[i - 1];
//        while (j > 0 && input[i] != input[j])
//            j = br[j - 1];
//        if (input[i] == input[j])
//            ++j;
//        br[i] = j;
//
//        if(i == length || input[br[i]] != input[i + 1])
//            brs[i] = br[i];
//        else
//            brs[i] = brs[br[i] - 1];
//    }
//}

void getBorders(string input, int* br, int* brs)
{
    int length = input.length();
    br[0] = 0;
    brs[0] = 0;

    vector<int> indices;
    for (int i = 1; i < length; ++i)
    {
        int j = br[i - 1];
        while (j > 0 && input[i] != input[j])
            j = br[j - 1];
        if (input[i] == input[j])
            ++j;
        br[i] = j;

        if(i == length || input[br[i]] != input[i + 1])
            brs[i] = br[i];
        else
            brs[i] = brs[br[i] - 1];
    }
}

vector<int> getSubstrings(string t, string p)
{

//    vector<int> br(p.size());
//    vector<int> brs(p.size());
    int *br = new int[p.size()];
    int *brs = new int[p.size()];
    getBorders(p, br, brs);

    vector<int> res;
    int n = t.size();
    int m = p.size();
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        while(q > 0 && p[q] != t[i])
            q = brs[q - 1];
        if(p[q] == t[i])
            ++q;
        if(q == m)
        {
            q = br[m - 1];
            res.push_back(i - m + 1);
        }
    }

    delete [] br;
    delete [] brs;
    return res;
}

int main()
{
    string t;
    string p;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, t);
        getline(fin, p);
        fin.close();
    }

    res = getSubstrings(t, p);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res.size() << "\n";
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        fout << *i << "\n";
    fout.close();

    return 0;
}