#include "ReadWriter2.h"
#include <vector>


struct Node
{

    Node *left;
    Node *right;
    Node *up;
    Node *down;

    Node *head;//указатель на хедер столбца

    int size; //если хедер столбца, то указывает на кол-во единиц в столбце
    int rowID;// номер строки в матрице из 1 и 0
};

void deleteColumnAndRow(Node *col);
void returnColumnAndRow(Node *col);
int findSolution(int k, Node *HeadNode, std::vector<Node *> &solution, int &res_size);
Node* buildLinkedList(char **matrix, int row_num, int col_num);




//Можно создавать любые классы и методы для решения задачи
//Советую разделить решение на логические блоки с комментариями


//Основной метод решения задачи, параметры:
//matrix - матрица NxM, представленная как N массивов по строкам, в каждом по M элементов '0' или '1'
//n, m - размеры матрицы
//result - массив для вывода решения, содержит строки из матрицы,
//для него надо выделить память здесь, передается по ссылке, чтобы можно было изменить указатель и получить это значение из main
//resultSize - количество строк в результате, передается по ссылке, чтобы можно было получить значение из main
void solve(char** matrix, int n, int m, char**& result, int& resultSize)
{
    Node* HeadNode = buildLinkedList(matrix, n, m);
    std::vector<Node*> solution(n*m);
    resultSize = 0;
    resultSize = findSolution(0, HeadNode, solution, resultSize);
    result = new char*[resultSize];
    std::string str_temp = "";
    for (int i = 0; i < resultSize;  ++i)
    {
        result[i] = new char[m];
        for (int j = 0; j < m; ++j)
        {
            result[i][j] = matrix[solution[i]->rowID][j];
            str_temp +=  matrix[solution[i]->rowID][j];
        }
    }
}


void deleteColumnAndRow(Node *col)
{
    //кдаление столбца
    col->left->right = col->right;
    col->right->left = col->left;

    //удаление строки
    for (Node* node = col->down; node != col; node = node->down)
    {
        for (Node* temp = node->right; temp != node; temp = temp->right)
        {
            temp->down->up = temp->up;
            temp->up->down = temp->down;
            temp->head->size--;
        }
    }
}

void returnColumnAndRow(Node *col)
{
    //возвращщаем строку
    for (Node* node = col->up; node != col; node = node->up)
    {
        for (Node* temp = node->left; temp != node; temp = temp->left)
        {
            temp->head->size++;
            temp->down->up = temp;
            temp->up->down = temp;
        }
    }
    //возвращаем столбец
    col->left->right = col;
    col->right->left = col;
}

int findSolution(int k, Node *HeadNode, std::vector<Node *> &solution, int &res_size)
{
    //столбцов болье нет -> найдено решение
    if (HeadNode->right == HeadNode)
    {
        res_size = k;
        return k;
    }

    //Выбираем столбец с минимальным кол-вом единиц
    Node* Col = HeadNode->right;
    for (Node* temp = Col->right; temp != HeadNode; temp = temp->right)
        if (temp->size < Col->size)
            Col = temp;

    deleteColumnAndRow(Col);

    for (Node* temp = Col->down; temp != Col; temp = temp->down) {
        solution[k] = temp;
        //удаляем строки и столбцы, с 1 на пересечении
        for (Node* node = temp->right; node != temp; node = node->right)
            deleteColumnAndRow(node->head);

        //следующий шаг рекурсии
        findSolution(k + 1, HeadNode, solution, res_size);
        if(res_size != 0)
            return res_size;

        temp = solution[k];
        Col = temp->head;
        //возвращаем строки и столбцы, с 1 на пересечении
        for (Node* node = temp->left; node != temp; node = node->left)
            returnColumnAndRow(node->head);

    }

    returnColumnAndRow(Col);
}

Node *buildLinkedList(char **matrix, int row_num, int col_num)
{

    Node* HeadNode = new Node;

    Node* header = new Node;
    header->left = header;
    header->right = header;
    header->down = header;
    header->up = header;
    header->size = -1;
    header->head = header;
    Node* temp = header;

    //Создание столбцов матрицы
    for (int i = 0; i < col_num; i++)
    {
        Node* newNode = new Node;
        newNode->size = 0;
        newNode->up = newNode;
        newNode->down = newNode;
        newNode->head = newNode;
        newNode->right = header;
        newNode->left = temp;
        temp->right = newNode;
        temp = newNode;
    }

    for (int i = 0; i < row_num; i++)
    {
        Node* top = header->right;
        Node* prev = nullptr;

        for (int j = 0; j < col_num; j++, top = top->right) {
            if (matrix[i][j] == '1') {
                Node* newNode = new Node;
                newNode->rowID = i;
                if (prev == nullptr)
                {
                    prev = newNode;
                    prev->right = newNode;
                }
                newNode->left = prev;
                newNode->right = prev->right;
                newNode->right->left = newNode;
                prev->right = newNode;

                newNode->down = top;
                newNode->up = top->up;
                top->up->down = newNode;

                newNode->head = top;
                top->size++;
                top->up = newNode;
                if (top->down == top)
                    top->down = newNode;
                prev = newNode;
            }
        }
    }

    HeadNode = header;
    return HeadNode;
}


int main()
{
    ReadWriter rw;
    //читаем параметры
    int n, m;
    rw.readInts(n, m);

    char** matrix = new char*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new char[m];
    //читаем матрицу
    rw.readMatrix(matrix, n, m);

    //Память под result не выделяется здесь, так как неизвестно какое количество строк войдет в решение
    //Предлагается выделить память прямо в методе solve
    int resultSize = 0; //количество строк в решении
    char** result = nullptr;
    solve(matrix, n, m, result, resultSize);

    //выводим результат в файл
    rw.writeInts(resultSize, m);
    rw.writeMatrix(result, resultSize, m);

    //освобождаем память матрицы, которую выделяли здесь
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    //освобождаем память массива результата, которая здесь не выделялась...
    for (int i = 0; i < resultSize; i++)
        delete[] result[i];
    delete[] result;

    return 0;
}