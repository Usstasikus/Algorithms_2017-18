
#include "bigInt/BigIntegerAlgorithms.hh"
//#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

static void print(vector<int> &raz)
{
    for(auto n: raz)
        cout << n << " ";
    cout << endl;
}
static void getNext(int N, vector<int> &raz, int m, int t, int &step, int k, unordered_set<int> &used)
{

    for (int i = 1; i <= N; ++i) {
        if(step == k)
            return;
        if(used.find(i) == used.end())
        {
            used.insert(i);
            raz[t] = i;
            if(t < m - 1)
                getNext(N, raz, m, t + 1, step, k, used);
            else{
                if(++step == k) {
                    return;
                }
            }
            used.erase(i);
        }
    }
}

static string get_day(int N,int k, int m)
{
    unordered_set<int> used;

    vector<int> raz(m);
    int step = 0;
    getNext(N, raz, m, 0, step, k, used);
    string res;
    for(auto n: raz)
        res += to_string(n) +  " ";
    return res.substr(0, res.size() - 1);
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
