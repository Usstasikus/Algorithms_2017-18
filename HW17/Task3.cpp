﻿#include "ReadWriter.h"
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h


#include <unordered_set>
//Можно создавать любые классы и методы для решения задачи

using namespace std;


//class EdgeComparator
//{
//public:
//    bool operator()
//};

bool edgeComp(const Edge &l, const Edge &r)
{
return l.W < r.W;
}

//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ребер, каждое ребро представлено 3-мя числами (А,В,W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра,
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора ребер, передается по ссылке (&), чтобы не копировать его.
void solve(int N, int M, vector<Edge>& edges, vector<Edge>& result)
{
    //Советую разделить решение на логические блоки
    //Можно использовать любые другие структуры, но затем скопировать ответ в структуру Edge для записи результата в файл.
    //Также можно добавить любые необходимые компараторы для предложенного класса Edge, так как все методы и поля публичные.

    vector<int> comp(N);
    for (int i = 0; i < N; ++i)
        comp[i] = i;

    vector<Edge> pq(edges.begin(), edges.end());
    sort(pq.begin(), pq.end(), edgeComp);
//    for(auto edge: edges)
//        pq.push(edge);

    int pos = 0;
    while(pos < M)
    {
        Edge edge = pq[pos++];

        if(comp[edge.A] != comp[edge.B])
        {
            result.emplace_back(edge);

            int old_comp = comp[edge.B], new_comp = comp[edge.A];
            for (int i = 0; i < N; ++i)
                if(comp[i] == old_comp)
                    comp[i] = new_comp;

        }
    }

}

int main()
{
    ReadWriter rw;
    //Входные параметры
    //N - количество вершин, M - количество ребер в графе
    int N, M;
    rw.read2Ints(N, M);

    //Вектор ребер, каждое ребро представлено 3-мя числами (А, В, W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра
    //Основной структурой выбран вектор, так как из него проще добавлять и удалять элементы (а такие операции могут понадобиться).
    vector<Edge> edges;
    rw.readEgdes(M, edges);

    //Основной структурой для ответа выбран вектор, так как в него проще добавлять новые элементы.
    //(а предложенные алгоритмы работают итеративно, увеличивая количество ребер входящих в решение на каждом шаге)
    vector<Edge> result;

    //Алгоритм решения задачи
    //В решение должны входить ребра из первоначального набора!
    solve(N, M, edges, result);

    //Выводим результаты
    rw.writeInt(result.size());
    rw.writeEdges(result);

    return 0;
}