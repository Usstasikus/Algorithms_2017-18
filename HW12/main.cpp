#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


static string get_day(long N, long M, long k)
{
    int prev[M];
    for (int i = 0; i < M; ++i)
        prev[i] = 1;

    for (int i = 0; i < k - 1; ++i)
    {
        int last_l = M - 1;

        while(last_l > 0 && prev[last_l] == N)
            --last_l;
        prev[last_l] += 1;
        for (long j = last_l + 1; j < M; ++j)
            prev[j] = 1;
    }

    string res = "";
    for(auto n: prev)
    {
        res += to_string(n) + " ";
    }
    return res.substr(0, res.size() - 1);


}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N, M, k;
    fin >> N >> M >> k;
    fout << get_day(N, M, k);


    fin.close();
    fout.close();
}