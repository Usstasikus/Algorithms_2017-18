#include "ReadWriter.h"
//iostream, fstream, string included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи
//Советую разделить решение на логические блоки


void fillColumns(int n,  char**& result);
void fillRows(int n,  char**& result);
int getNumberOfConstraints(const char* up, const char* down, const char* left, const char* right, int n);
void fillConstraints(const char *up, const char *down, const char *left, const char *right, int n, char **&result);
void fillUnique(int intercept, int n, char **&result);

//Основной метод решения задачи, параметры:
//n - размер векторов условия
//up - доп. условия сверху, содержит буквы латинского алфавита и пробелы
//down - доп. условия снизу, содержит буквы латинского алфавита и пробелы
//left - доп. условия слева, содержит буквы латинского алфавита и пробелы
//up - доп. условия справа, содержит буквы латинского алфавита и пробелы
///Выходные параметры:
//result - матрица ограничений для задачи, содержит символы '0' и '1', других не содержит.
//передается по ссылке, чтобы потом можно было прочитать значение из main
//rows - количество строк в матрице результата
//cols - количество столбцов в матрице результата
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


//    for (int i = 0; i < n; ++i) {
//        std::cout << up[i] << ':';
//    }
    fillConstraints(up, down, left, right, n, result);
    fillUnique(2*(n * n + constr_num), n, result);
}


void fillColumns(int n, char **&result) {
    int len_columns = n * n;
    for (int b_row_intercept = 0, b_col_intercept = 0; b_row_intercept < n * n * n; b_row_intercept += n * n, b_col_intercept += n) { //вертикальный отступ большого блока
        for (int i = b_row_intercept; i < b_row_intercept + n * n; i += n) { //вертикальный отступ мальенького блока
            for (int j = 0; j < n; ++j) {
                result[i + j][b_col_intercept + j] = '1';
            }
        }
    }
}

void fillRows(int n, char **&result) {
    int len_columns = n * n, len_rows = n * n * n;
    int col_intercept = len_columns;
    for (int k = 0; k < len_rows; k += len_columns) {
        for (int i = 0; i < len_columns; ++i) {
            result[i + k][i + col_intercept] = '1';
        }
    }
}

int getNumberOfConstraints(const char *up, const char *down, const char *left, const char *right, int n) {
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

void fillConstraints(const char *up, const char *down, const char *left, const char *right, int n, char **&result) {
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

void fillUnique(int intercept, int n, char **&result) {
    for (int j = 0; j < n*n; ++j) {
        for (int i = 0; i < n; ++i) {
            result[j*n + i][intercept + j] = '1';
        }
    }
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

    //Память здесь не выделяется, так как размер неизвестен
    char** result = nullptr;
    //Основной алгоритм, возвращает результат как матрицу 
    int rows = 0, cols = 0;
    createMatrix(up, down, left, right, n, result, rows, cols);

    //выводим результат в файл
    rw.writeInts(rows, cols);
    rw.writeMatrix(result, rows, cols);
    
    //освобождаем память
    delete[] up;
    delete[] down;
    delete[] left;
    delete[] right;

    for (int i = 0; i < rows; i++)
        delete[] result[i];
    delete[] result;

    return 0;
}