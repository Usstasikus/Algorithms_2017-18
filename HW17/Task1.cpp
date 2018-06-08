#include "ReadWriter.h"
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;


void dfs (int v, vector<Edge>& edges, vector<int> &comp, vector<bool> &used, int comp_num) {
    used[v] = true;
    comp[v] = comp_num;
    for(Edge edge: edges)
    {
        if(edge.W != INT16_MAX && (edge.A == v || edge.B == v))
        {
            int to;
            if(edge.A == v)
                to = edge.B;
            else
                to = edge.A;

            if (! used[to])
                dfs(to, edges, comp, used, comp_num);
        }
    }
}

int find_comps(int N, vector<Edge>& edges, vector<int> &comp) {

    vector<bool> used(N);
    for (int i=0; i<N; ++i)
        used[i] = false;
    int comp_num  = 0;
    for (int i=0; i<N; ++i)
        if (! used[i]) {
            dfs (i, edges, comp, used, comp_num);
            ++comp_num;
        }
    return comp_num;
}



//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ребер, каждое ребро представлено 3-мя числами (А,В,W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра,
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора ребер, передается по ссылке (&), чтобы не копировать его.
void solve(int N, int M, vector<Edge>& edges, vector<Edge> &result)
{
    vector<Edge> chipedges(N);
    int num_tress = N;

    vector<bool> used(edges.size(), false);

    for (int i = 0; i < N; ++i)
        chipedges[i].W = INT16_MAX;

    while(num_tress > 1)
    {
        vector<int> comp(N, -1); //компонента для каждой вершины

        num_tress = find_comps(N, result, comp);

        for (int i = 0; i < N; ++i)
            chipedges[i].W = INT16_MAX;

        for(Edge edge: edges)
        {
            if(comp[edge.A] != comp[edge.B])
            {
                if (comp[edge.A] != -1 && edge.W < chipedges[comp[edge.A]].W)
                    chipedges[comp[edge.A]] = edge;
                if (comp[edge.B] != -1 && edge.W < chipedges[comp[edge.B]].W)
                    chipedges[comp[edge.B]] = edge;
            }
        }

        for(Edge c_edge: chipedges){
            if(c_edge.W != INT16_MAX && !used[c_edge.number]) {
                used[c_edge.number] = true;
                result.push_back(c_edge);
            }
        }
    }

    //Советую разделить решение на логические блоки
    //Можно использовать любые другие структуры, но затем скопировать ответ в структуру Edge для записи результата в файл.
    //Также можно добавить любые необходимые компараторы для предложенного класса Edge, так как все методы и поля публичные.

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