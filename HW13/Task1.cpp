#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


bool checkPartSolution(int N, int i_curr, int j_curr, vector<pair<int, int>> &occupied)
{
    for(auto st: occupied)
    {
        if((st.first == i_curr && st.second != j_curr) ||
           (st.second == j_curr && st.first != i_curr) ||
           (st.first - st.second == i_curr - j_curr && st.first != i_curr) ||
           (st.first - (N - st.second) == i_curr - (N - j_curr) && st.first != i_curr))
            return false;
    }
    return true;
}

bool findPos(int N, int curr, vector<pair<int, int>> &occupied)
{
    for (int i = 0; i < N; ++i) {
        occupied.emplace_back(curr, i);
        if(checkPartSolution(N, curr, i, occupied))
        {
            if(curr == N - 1|| findPos(N, curr + 1, occupied))
                return true;
        }
        occupied.pop_back();
    }
    return false;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin >> N;

    vector<pair<int, int>> occupied;

    if(findPos(N, 0, occupied))
    {
        for(int i = 0; i < N; ++i)
        {
            int occ = 0;
            for(occ = 0; occ < N; ++occ)
                if(occupied[occ].first == i)
                    break;
            occ = occupied[occ].second;
            int j = 0;
            while(j < occ)
            {
                fout << 0;
                ++j;
            }
            fout << 1;
            ++j;
            while(j < N)
            {
                fout << 0;
                ++j;
            }
            fout << endl;


        }
    }


    return 0;
}