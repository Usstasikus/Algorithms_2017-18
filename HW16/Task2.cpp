#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef pair<string, int> cumberbatches;

bool cumberbatchesSort(const string &r, const string &l)
{
    return r < l;
}

bool cumberbatchesGroupSort(const vector<string> &r, const vector<string> &l)
{
    return r[0] < l[0];
}

void DFS(const vector<string> &names, const vector<vector<bool>> &relations, int index, vector<int> &res, vector<bool> &used)
{
    used[index] = true;
    vector<cumberbatches> temp;

    for (int j = 0; j < relations[0].size(); ++j)
        if(relations[index][j] && !used[j])
            DFS(names, relations, j, res, used);

//    res.insert(res.begin(), index);
    res.insert(res.begin(), index);
}

vector<int> getListStraight(const vector<string> &names, const vector<vector<bool>> &relations)
{
    vector<bool> used(names.size(), false);

    vector<int> res;
    for (int i=0; i<names.size(); ++i)
        if (!used[i])
            DFS(names, relations, i, res, used);

    return res;
}

void invertRelations(vector<vector<bool>> &relations)
{
    for (int i = 0; i < relations.size(); ++i)
        for (int j = i + 1; j < relations[0].size(); ++j)
            if(relations[i][j] != relations[j][i])
                swap(relations[i][j], relations[j][i]);
}


void fillGroups(const vector<string> &names, const vector<vector<bool>> &relations, int index, vector<string> &group, vector<bool> &used)
{
    used[index] = true;
    group.emplace_back(names[index]);
    for (int j = 0; j < relations[0].size(); ++j) {
        if(relations[index][j] && !used[j])
            fillGroups(names, relations, j, group, used);

    }
}

vector<vector<string>> getList(const vector<string> &names, vector<vector<bool>> &relations)
{
    vector<vector<string>> res;
    vector<int> straight_list = getListStraight(names, relations);
    invertRelations(relations);

    vector<bool> used(names.size(), false);
    for (auto i: straight_list) {
        if (used[i])
            continue;
        vector<string> group;
        fillGroups(names, relations, i, group, used);

        sort(group.begin(), group.end());
        res.emplace_back(group);
    }
    sort(res.begin(), res.end(), cumberbatchesGroupSort);


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

        while (fin)
        {
            int a = stoi(str.substr(0, str.find(' '))) - 1;
            int b = stoi(str.substr(str.find(' '))) - 1;
            relations[a][b] = true;
            getline(fin, str);
        }

        fin.close();
    }

    vector<vector<string>> res = getList(names, relations);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            fout << res[i][j] << "\n";
        fout << "\n";
    }
    fout.close();

    return 0;
}