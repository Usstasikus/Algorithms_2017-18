//
//  main.cpp
//  A
//
//  Created by Данил Нечай on 02.04.2018.
//  Copyright © 2018 Данил Нечай. All rights reserved.
//

#include "bigInt/BigIntegerAlgorithms.hh"
//#include "bigInt/BigIntegerUtils2.h"
//#include "BigIntegerAlgorithms.hh"


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

static BigInteger FactTree(int n) //1
{
    BigInteger res = 1;
    for(int i = 2; i <= n; ++i)
        res *= i;
    return res;
}
static BigInteger C(int n, int k)//2
{
    int max_den = max(n - k, k);

    BigInteger numer = 1;
    for(int i = max_den + 1; i <= n; ++i)
        numer *= i;
    BigInteger den = FactTree(n - max_den);

    return numer / den;
}
static BigInteger Pair (int n)//3
{
    BigInteger ans = 1;
    for (int i = 3; i < n; i+=2)
        ans *= i;
    return ans;
}

int main(int argc, const char * argv[]) {

    int n,N,K;
    fstream fin;
    fstream fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    if(fin.is_open()) {
        string str;
        getline(fin,str);
        N = atoi( str.c_str());
        n = N;
        getline(fin,str);
        K = atoi( str.c_str());
        fout << FactTree(N)<< endl;
        fout << C(N,K)<< endl;
        fout << Pair(N)<< endl;
        fout.close();
        fin.close();
    }
    return 0;
}
