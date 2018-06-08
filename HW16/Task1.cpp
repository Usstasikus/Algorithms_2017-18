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

typedef pair<string, int> clothing;

bool clothingSort(const clothing &r, const clothing &l)
{
    return r.first != l.first ? r.first > l.first : r.second > l.second;
}

void DFS(const vector<string> &names, const vector<vector<bool>> &relations, stack<int> &st, vector<string> &res, vector<bool> &used)
{
    int index = st.top();
    st.pop();
    if(used[index])
        return;

    used[index] = true;
    vector<clothing> temp;

    for (int j = 0; j < relations[0].size(); ++j)
        if(relations[index][j])
            temp.emplace_back(names[j], j);

    sort(temp.begin(), temp.end(), clothingSort);//сортировка детей

    for(auto c: temp)
        st.push(c.second);
    for (int i = 0; i < temp.size(); ++i)
        DFS(names, relations, st, res, used);//обход детей

    res.insert(res.begin(), names[index]);//записываем вершину в начало списка


}

vector<string> getList(const vector<string> &names, const vector<vector<bool>> &relations)
{
    vector<clothing> zero_entries;
    for (int j = 0; j < relations[0].size(); ++j)//поиск истоков
    {
        bool is_zero = true;
        for (int i = 0; i < relations.size(); ++i)
            if(relations[i][j] == true)
                is_zero = false;
        
        if(is_zero)
            zero_entries.emplace_back(names[j], j);
    }
    sort(zero_entries.begin(), zero_entries.end(), clothingSort);//сортировка истоков

    stack<int> st;
    for(auto c: zero_entries)
        st.push(c.second);

    vector<bool> used(names.size(), false);

    vector<string> res;

    while(!st.empty())
        DFS(names, relations, st, res, used);

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

    vector<string> res = getList(names, relations);

    fstream fout;

    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
        fout << res[i] << "\n";
    fout.close();
    return 0;
}