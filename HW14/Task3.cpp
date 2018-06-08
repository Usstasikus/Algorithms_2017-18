#include <vector>
#include "ReadWriter3.h"

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


void fillColumns(int n,  char**& result);
void fillRows(int n,  char**& result);
int getNumberOfConstraints(const char* up, const char* down, const char* left, const char* right, int n);
void fillConstraints(const char *up, const char *down, const char *left, const char *right, int n, char **&result);
void fillUnique(int intercept, int n, char **&result);

void fillSymbolByRowID(int row_id, int n, char** result);


void createMatrix(char* up, char* down, char* left, char* right, int n, char**& result, int& rows, int& cols)
{
    rows = n * n * n;
    int constr_num = getNumberOfConstraints(up, down, left, right, n);
    cols = 2 * (n * n + constr_num) + n * n;//TODO
    result = new char*[n * n * n];
    for (int i = 0; i < rows; ++i) {
        result[i] = new char[cols];
        for (int j = 0; j < cols; ++j) {
            result[i][j] = '0';
        }
    }
    fillColumns(n, result);
    fillRows(n, result);


    fillConstraints(up, down, left, right, n, result);
    fillUnique(2*(n * n + constr_num), n, result);
}

void fillColumns(int n, char **&result)
{
    int len_columns = n * n;
    for (int b_row_intercept = 0, b_col_intercept = 0; b_row_intercept < n * n * n; b_row_intercept += n * n, b_col_intercept += n) { //вертикальный отступ большого блока
        for (int i = b_row_intercept; i < b_row_intercept + n * n; i += n) { //вертикальный отступ мальенького блока
            for (int j = 0; j < n; ++j) {
                result[i + j][b_col_intercept + j] = '1';
            }
        }
    }
}

void fillRows(int n, char **&result)
{
    int len_columns = n * n, len_rows = n * n * n;
    int col_intercept = len_columns;
    for (int k = 0; k < len_rows; k += len_columns) {
        for (int i = 0; i < len_columns; ++i) {
            result[i + k][i + col_intercept] = '1';
        }
    }
}

int getNumberOfConstraints(const char *up, const char *down, const char *left, const char *right, int n)
{
    int constr_num = 0;
    for (int i = 0; i < n; ++i) {
        if(isalpha(up[i]))
            ++constr_num;
        if(isalpha(down[i]))
            ++constr_num;
        if(isalpha(left[i]))
            ++constr_num;
        if(isalpha(right[i]))
            ++constr_num;
    }
    return constr_num;
}

void fillConstraints(const char *up, const char *down, const char *left, const char *right, int n, char **&result)
{
    int col_intercept = 2 * n * n;
    int count_up = 0, count_down = 0, count_left = 0, count_right = 0;
    for (int i = 0; i < n; ++i) {
        if(isalpha(up[i])){
            int letter = up[i] - 'A';
            result[i*n + letter][col_intercept + count_up] = '1';
            result[i*n + letter][col_intercept + count_up + 1] = '1';

            result[i*n + n - 1][col_intercept + count_up] = '1';

            result[n*n + i*n + letter][col_intercept + count_up + 1] = '1';
            count_up += 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(isalpha(down[i])){
            int letter = down[i] - 'A';
            result[n*n*n - n*n + i*n + letter][col_intercept + count_up + count_down] = '1';
            result[n*n*n - n*n + i*n + letter][col_intercept + count_up + count_down + 1] = '1';

            result[n*n*n - n*n + i*n + n - 1][col_intercept + count_up + count_down] = '1';

            result[n*n*n - 2*n*n + i*n + letter][col_intercept + count_up + count_down + 1] = '1';


            count_down += 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(isalpha(left[i])){
            int letter = left[i] - 'A';
            result[i*n*n + letter][col_intercept + count_up + count_down + count_left] = '1';
            result[i*n*n + letter][col_intercept + count_up + count_down + count_left + 1] = '1';

            result[i*n*n + n - 1][col_intercept + count_up + count_down + count_left] = '1';

            result[i*n*n + n + letter][col_intercept + count_up + count_down + count_left + 1] = '1';

            count_left += 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(isalpha(right[i])){
            int letter = right[i] - 'A';
            result[i*n*n + n*n - n + letter][col_intercept + count_up + count_down + count_left + count_right] = '1';
            result[i*n*n + n*n - n + letter][col_intercept + count_up + count_down + count_left + count_right + 1] = '1';

            result[i*n*n + n*n - 1][col_intercept + count_up + count_down + count_left + count_right] = '1';

            result[i*n*n + n*n - 2*n + letter][col_intercept + count_up + count_down + count_left + count_right + 1] = '1';

            count_right += 2;
        }
    }
}

void fillUnique(int intercept, int n, char **&result)
{
    for (int j = 0; j < n*n; ++j) {
        for (int i = 0; i < n; ++i) {
            result[j*n + i][intercept + j] = '1';
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



//Основной метод решения задачи, параметры:
//n - размер исходной задачи и результата (NxN)
//up - доп. условия сверху, содержит буквы латинского алфавита и пробелы
//down - доп. условия снизу, содержит буквы латинского алфавита и пробелы
//left - доп. условия слева, содержит буквы латинского алфавита и пробелы
//up - доп. условия справа, содержит буквы латинского алфавита и пробелы
//result - матрица решения NxN, представлено как массив строчек, содержащих символы 'А-Z' и '+', для обозначения отсутствия буквы
void solve(char* up, char* down, char* left, char* right, char** result, int n)
{
    char** matrix = nullptr;
    int rows, cols;
    createMatrix(up, down, left, right, n, matrix, rows, cols);

    Node* HeadNode = buildLinkedList(matrix, rows, cols);
    std::vector<Node*> solution(rows * cols);
    int resultSize = 0;
    resultSize = findSolution(0, HeadNode, solution, resultSize);
    for (int i = 0; i < resultSize;  ++i)
    {
        int row_id = solution[i]->rowID;
        fillSymbolByRowID(row_id, n, result);
    }


    //Можно создавать любые классы и методы для решения задачи
    //Советую разделить решение на логические блоки
}

void fillSymbolByRowID(int row_id, int n, char **result) {
    int row, column;
    char symb;
    if((row_id + 1)%n == 0)
        symb = '+';
    else
        symb = 'A' + row_id % n;

    column = (row_id/n)%n;
    row = (row_id/(n*n))%n;

    result[row][column] = symb;
}



int main() 
{
    ReadWriter rw;
    //читаем параметры
    int n = rw.readInt();

    char* up = new char[n];
    char* down = new char[n];
    char* left = new char[n];
    char* right = new char[n];

    rw.readData(up, down, left, right, n);

    //Создаем массив, но не заполняем нулями, так как в методе все равно будет заполнена каждая ячейка
    char** result = new char*[n];
    for (int i=0; i< n; i++)
        result[i] = new char[n];
    //Основной алгоритм, возвращает результат как матрицу решения, память уже выделена под result
    solve(up, down, left, right, result, n);

    //выводим результат в файл
    rw.writeInt(n);
    rw.writeResult(result, n);

    //освобождаем память
    delete[] up;
    delete[] down;
    delete[] left;
    delete[] right;

    for (int i = 0; i < n; i++)
        delete[] result[i];
    delete[] result;

    return 0;
}