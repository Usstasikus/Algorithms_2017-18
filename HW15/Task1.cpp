#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;

//vector<string> getList(const vector<string> &names, const vector<vector<bool>> &relations, int startIndex)
vector<string> getList( vector<string> names, const vector<vector<bool>> &relations, int startIndex)
{
    vector<string> res;
    int curr_level_num = 1, next_level_num = 0;

    vector<bool> used(names.size(), false);

    queue<int> q;
    q.push(startIndex);


    vector<string> temp;
    res.emplace_back(names[startIndex]);
    used[startIndex] = true;
    int curr = 0;
    while(!q.empty())
    {

        int next = q.front();
        q.pop();

        for (int i = 0; i <relations[next].size() ; ++i) {
            if(relations[next][i] && !used[i])
            {
                used[i] = true;
                temp.emplace_back(names[i]);
                q.push(i);
                ++next_level_num;
            }
        }

        ++curr;
        if(curr == curr_level_num)
        {
//            sort(res.end() - next_level_num, res.end() - next_level_num - curr);
            sort(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end());
            temp.clear();
            curr_level_num = next_level_num;
            next_level_num = 0;
            curr = 0;
        }
    }
    return res;

}
int main()
{
    vector<string> names = vector<string>();
    vector<vector<bool>> relations;
    int startIndex;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        string str = "";
        getline(fin, str);

        while (str != "#")
        {
            names.emplace_back(str.substr(str.find(' ') + 1));
            getline(fin, str);
        }

        relations = vector<vector<bool>>(names.size());

        for (int i = 0; i < names.size(); i++)
        {
            relations[i] = vector<bool>(names.size());
            for (int j = 0; j < names.size(); j++)
                relations[i][j] = false;
        }

        getline(fin, str);

        while (str != "#")
        {
            int a = stoi(str.substr(0, str.find(' '))) - 1;
            int b = stoi(str.substr(str.find(' '))) - 1;
            relations[a][b] = true;
            relations[b][a] = true;
            getline(fin, str);
        }

        fin >> startIndex;

        fin.close();
    }

    vector<string> res = getList(names, relations, startIndex - 1);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
        fout << res[i] << "\n";
    fout.close();

    return 0;
}