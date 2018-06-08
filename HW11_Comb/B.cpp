
#include "bigInt/BigIntegerAlgorithms.hh"
//#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

static void getNext(vector<int>& prev)
{
    int N = prev.size() - 1;
    int i = N;
    while(i > 1 && prev[i] < prev[i - 1])
        --i;
    int j = N;
    while(prev[j] < prev[i - 1])
        --j;
    swap(prev[i - 1], prev[j]);
    for (j = 0;  j <= (N - i + 1)/2 - 1; ++j)
        swap(prev[i + j], prev[N - j]);
}


static string get_day(int N,int k)
{
    vector<int> prev(N);
    for (int i = 0; i < N; ++i) {
        prev[i] = i + 1;
    }
    for (int i = 0; i < k - 1; ++i) {
        getNext(prev);
    }
    string res = "";
    for(auto n: prev)
    {
        res += to_string(n) + " ";
    }
    return res.substr(0, res.size() - 1);


}
int main(int argc, const char * argv[]) {

    int N,K;
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
        fout << get_day(N,K)<< endl;

        fout.close();
        fin.close();
    }

    return 0;
}