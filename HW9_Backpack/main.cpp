#include "ReadWriter.h"
//string, iostream included in "ReadWriter.h"
#include <vector>
using namespace std;


bool good(int i, int j, int n, int m)
{
    return (i >= 0) && (j >= 0) && (i < n) && (j < m);
}
//Можно добавлять любые вспомогательные методы и классы для решения задачи.
long long lazyRec(int i, int j, vector<vector<long long>> &field, const int &N, const int &M)
{
    long long dr = 0, dl = 0, ru = 0, rd = 0;

    if(good(i, j, N, M)) {
        if (field[i][j] == -1) {
            field[i][j] = lazyRec(i - 2, j - 1, field, N, M)
                          + lazyRec(i - 2, j + 1, field, N, M)
                          + lazyRec(i - 1, j - 2, field, N, M)
                          + lazyRec(i + 1, j - 2, field, N, M);
        }
    }
    else
        return 0;
    return field[i][j];

}
//Задача реализовать этот метод
//param N - количество строк (rows) доски
//param M - количество столбцов (columns) доски
//return - количество способов попасть в правый нижний угол доски (клетка N-1, M-1, если считать что первая клетка 0,0)
long long solve(int N, int M)
{
    vector<vector<long long>> field(N, vector<long long>(M, -1));
    field[0][0] = 1;
    return lazyRec(N - 1, M - 1, field, N, M);;
}

int main(int argc, const char * argv[])
{
    ReadWriter rw;

    int N = rw.readInt(); //количество строк (rows)
    int M = rw.readInt(); //количество столбцов (columns)
    //решение
    long long res = solve(N, M);
    //результат в файл
    rw.writeLongLong(res);

    return 0;
}
