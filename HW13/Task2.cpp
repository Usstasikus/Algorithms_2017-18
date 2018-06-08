//
// Created by Stas Don on 22/04/2018.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <map>

using namespace std;

class CompareDist
{
public:
    bool operator()(pair<int,int> n1, pair<int,int> n2) {
        return n1.second > n2.second;
    }
};

void findShortest(const vector<vector<int>> &graph, const vector<int> &heurs, int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDist> pq;
    pq.push({0, 0});
    map<int, int> came_from;
    map<int, int> cost_from;
    came_from[start] = -1;
    cost_from[start] = 0;

    while(!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();

        if(curr.first == end)
            break;
        for(int next = 0; next < graph.size(); ++next)
        {
            if(next == curr.first || graph[curr.first][next] == -1)
                continue;
            int new_cost = cost_from[curr.first] + graph[curr.first][next];
            if (cost_from.count(next) == 0 || cost_from[next] > new_cost)
            {
                cost_from[next] = new_cost;
                int priority = new_cost + heurs[next];
                pq.push({next, priority});
                came_from[next] = curr.first;
            }
        }
    }
    ofstream fout("output.txt");

    string res = to_string(end);
    int curr = end;
    while(curr != start)
    {
        curr = came_from[curr];
        res = to_string(curr) + " " + res;
    }
    fout << res;
    fout.close();
}

int main()
{
    ifstream fin("input.txt");
    int N, start, end;
    fin >> N >> start >> end;

    vector<vector<int>> graph(N, vector<int>(N));
    vector<int> heurs(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> graph[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        fin >> heurs[i];
    }
    fin.close();

    findShortest(graph, heurs, start, end);
    return 0;
}