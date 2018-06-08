//
// Created by Stas Don on 15/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


static string get_day(long N, long k)
{
    vector<int> prev(N);
    for (int i = 0; i < N; ++i)
        prev[i] = 1;

    long a = N;
    long curr = N;
    while(a < k)
        a *= --curr;

    --k;
    while(k > 0)
    {
        a /= (curr++);
        prev[curr - 2] += k / a;
        k %= a;
    }


//    for (int i = 0; i < k - 1; ++i)
//    {
//        int last_l = N - 1;
//
//        while(last_l > 0 && prev[last_l] == last_l + 1)
//            --last_l;
//        prev[last_l] += 1;
//        for (long j = last_l + 1; j < N; ++j)
//            prev[j] = 1;
//    }

    string res = "";
    for(auto n: prev)
    {
        res += to_string(n) + " ";
    }
    return res.substr(0, res.size() - 1);


}
static string get_day1(long N, long k)
{
    int prev[N];
    for (int i = 0; i < N; ++i)
        prev[i] = 1;

    for (int i = 0; i < k - 1; ++i)
    {
        int last_l = N - 1;

        while(last_l > 0 && prev[last_l] == last_l + 1)
            --last_l;
        prev[last_l] += 1;
        for (long j = last_l + 1; j < N; ++j)
            prev[j] = 1;
    }

    string res = "";
    for(auto n: prev)
    {
        res += to_string(n) + " ";
    }
    return res.substr(0, res.size() - 1);


}


static void get_track(long N, long k)
{
    long M = N;
    string res = "";

    --k;
//    long curr = M - 1;

    long curr = N, count = 0;
    while(k > 0)
    {
        res = " " + to_string(k%curr + 1) + res;
//        prev[curr--] = k % N + 1;
        k /= curr--;
        ++count;
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
    ofstream fout("output.txt");

    long N, k;

    fin >> N >> k;
    get_track(N, k);

//    cout << get_day(N, k);
    fin.close();
    fout.close();
}