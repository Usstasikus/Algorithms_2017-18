#include "ReadWriter.h"
//vector, string, iostream included in "ReadWriter.h"

using namespace std;

void way(int i, int j, vector<vector<int>> &d_table, int* stones, vector<int> &res)
{
    if(d_table[i][j] == 0)
        return;
    else if(d_table[i][j] != d_table[i - 1][j])
    {
        res.push_back(stones[i - 1]);
        way(i - 1, j - stones[i - 1], d_table, stones, res);
    }
    else
        way(i - 1, j, d_table, stones, res);
}
//Можно добавлять любые вспомогательные методы и классы для решения задачи.

//Задача реализовать этот метод
//param N - количество камней
//param M - ограничения на вес
//param stones - массив размера N, с весами камней
//param res - вектор результатов (вес камней, которые надо взять)
void solve(int N, int W, int* stones, vector<int>& res)
{
    vector<vector<int>> d_table(N + 1, vector<int>(W + 1));

    for (int j = 0; j <= N; ++j)
        d_table[j][0] = 0;

    for (int i = 0; i <= W; ++i)
        d_table[0][W] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= W; ++j) {
            if(j - stones[i - 1] >= 0)
                d_table[i][j] = max(d_table[i - 1][j], d_table[i - 1][j - stones[i - 1]] + stones[i - 1]);
            else
                d_table[i][j] = d_table[i - 1][j];
        }
    }
    way(N, W, d_table, stones, res);


}

int main(int argc, const char * argv[])
{
    ReadWriter rw;
    int N = rw.readInt(); //камни
    int W = rw.readInt(); //ограничения на вес
    int* arr = new int[N]; //имеющиеся камни
    rw.readArr(arr, N);

    //основной структурой выбран вектор, так как заранее неизвестно какое количество камней будет взято
    vector<int> res;
    //решаем задачу
    solve(N, W, arr, res);
    int sum = 0;
    for (int i = 0; i < res.size(); i++)
        sum += res.at(i);

    //записываем ответ в файл
    rw.writeInt(sum); //итоговый вес
    rw.writeInt(res.size()); //количество взятых камней
    rw.writeVector(res); //сами камни

    delete[] arr;
    return 0;
}
