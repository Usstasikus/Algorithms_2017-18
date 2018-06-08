//
// Created by Stas Don on 15/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


static void get_track(long N, long M, long k)
{
    vector<long> prev(M);
    for (long i = 0; i < M; ++i)
        prev[i] = 1;
    string res = "";

    --k;
//    long curr = M - 1;

    long count = 0;
    while(k > 0)
    {
        ++count;
        res = " " + to_string(k%N + 1) + res;
//        prev[curr--] = k % N + 1;
        k /= N;
    }
//    for(auto n: prev)
//    {
//        res += to_string(n) + " ";
//    }

    ofstream fout("output.txt");


    fout << "1";
    for (long j = 1; j < M - count; ++j) {
        fout << " 1";
    }
    fout << res;
    fout.close() ;


}

int main() {
    ifstream fin("input.txt");

    long N, M, k;
    fin >> N >> M >> k;
    get_track(N, M, k);

//    long a = 1;
//    for (int i = 1; i <= 5; ++i) {
//        a *= (i);
//    }
//
//    for (int j = 1; j <= a; ++j) {
//        cout << get_day(5, 5, j) << endl;
//    }

    fin.close();
}