
#include "bigInt/BigIntegerAlgorithms.hh"

//#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

static string get_day(int N,int k, int m)
{
    vector<int> c(m);
//    c[0] = -1;
//    for (int i = 1; i < m; ++i)
//        c[i] = i;
//    int j = 1;
//    int step = 0;
//
//    while(j != 0 && step < k)
//    {
//        j = m - 1;
//        while(c[j] >= N - m + j)
//            --j;
//        c[j] = c[j] + 1;
//        for (int i = j + 1; i < m; ++i)
//            c[i] = c[i - 1] + 1;
//        ++step;
//
//    }
    for (int i = 0; i < m; ++i)
        c[i] = i + 1;
    for (int step = 1; step < k; ++step) {
        int i = m - 1;
        while(c[i] + m - i > N)
            --i;
        ++c[i];
        for (int j = i + 1; j < m; ++j)
            c[j] = c[j - 1] + 1;
    }
    string res;
    for(auto n: c)
        res += to_string(n) + " ";
    return res;

    
}
int main(int argc, const char * argv[]) {
        int M,N,K;
        fstream fin;
        fstream fout;
        fin.open("input.txt",ios::in);
        fout.open("output.txt",ios::out);
        if(fin.is_open()) {
            string str;
            getline(fin,str);
            N = atoi( str.c_str());
            getline(fin,str);
            K = atoi( str.c_str());
            getline(fin,str);
            M = atoi( str.c_str());
            fout << get_day(N, K, M)<< endl;
            fout.close();
            fin.close();
        }
    
    return 0;
}
