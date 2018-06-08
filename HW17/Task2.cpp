#include "ReadWriter.h"
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h
#include <queue>
#include <set>
//Можно создавать любые классы и методы для решения задачи



using namespace std;


struct Vertex
{
    int v;
    int p;
    int key;

    Vertex(int v, int p, int key):v(v), p(p), key(key)
    {}
};

class VComparator{
public:
    bool operator()(const Vertex &l, const Vertex &r)
    {
        return l.key == r.key ? l.v < r.v: l.key < r.key;
    }
};

//class vertex_priority_queue : priority_queue<Vertex, vector<Vertex>, VComparator>
//{
//public:
//
//    bool remove(const Vertex& value) {
//        auto it = std::find(this->c.begin(), this->c.end(), value);
//        if (it != this->c.end()) {
//            this->c.erase(it);
//            std::make_heap(this->c.begin(), this->c.end(), this->comp);
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//};

vector<vector<Edge>> createGraph(int N, const vector<Edge>& edges)
{
    vector<vector<Edge>> g(N, vector<Edge>());

    for(auto edge: edges)
    {
        g[edge.A].push_back(edge);

//        Edge edge_cp = edge;
//        edge_cp.A = edge.B;
//        edge_cp.B = edge.A;
//        g[edge.B].push_back(edge_cp);
        g[edge.B].push_back(edge);
    }

    return g;
}

//void reorderEl(Vertex &v, vertex_priority_queue &pq)
//{
//}


//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ребер, каждое ребро представлено 3-мя числами (А,В,W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра,
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора ребер, передается по ссылке (&), чтобы не копировать его.
void solve(int N, int M, vector<Edge>& edges, vector<Edge>& result)
{
    vector<vector<Edge>> g = createGraph(N, edges);

    for (int j = 0; j < N - 1; ++j) {
        result.emplace_back(Edge());
    }

    vector<Vertex> vertices;
    for (int i = 0; i < N; ++i)
        vertices.emplace_back(i, -1, INT16_MAX);

    vertices[0].key = 0;

//    vertex_priority_queue pq;

    set<Vertex, VComparator> pq;

    for (int i = 0; i < N; ++i) {
        pq.insert(vertices[i]);
    }

//    for (auto it=pq.begin(); it!=pq.end(); ++it)
//        std::cout << ' ' << it->v;

    while(pq.size() != 0)
    {
        Vertex u = *next(pq.begin(), 0);
        pq.erase(u);
        for(auto edge: g[u.v])
        {
            int v_index;
            if(edge.A == u.v)
                v_index = edge.B;
            else
                v_index = edge.A;
            if(pq.find(vertices[v_index]) != pq.end()) {


                auto v = *pq.find(vertices[v_index]);

                if (edge.W < v.key) {
                    vertices[v.v].key = edge.W;
                    vertices[v.v].p = u.v;

                    pq.erase(v);
                    pq.insert(vertices[v.v]);

                    if(edge.A == u.v)
                        result[v_index - 1] = {u.v, v_index, vertices[v.v].key};
                    else
                        result[v_index - 1] = {v_index, u.v, vertices[v.v].key};
                }
            }
        }

    }

//
//    for(auto e: result)
//        cout<<e.A << " " << e.B << " " << e.W <<endl;
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