//#include "ReadWriter.h"
////Node.h подключен в ReadWriter.h, поэтому здесь не надо
//
//using namespace std;
//
////Можно добавлять любые вспомогательные методы и классы для решения задачи.
//
////Задание реализовать метод декодирования
//void decodeLZ77(Node* arr, int n, string& res)
//{
//    res = "";
//    for (int i = 0; i < n; ++i)
//    {
//        int indexSubstr = arr[i].offs;
//        int len = arr[i].len;
//        char c = arr[i].ch;
//
//        int start = res.length() - indexSubstr;
//        for (int j = 0; j < len; ++j)
//            res += res[start + j];
//        res += c;
//    }
//}
//
//int main(int argc, const char * argv[])
//{
//    ReadWriter rw;
//
//    int n = rw.readInt();
//    Node* arr = new Node[n];
//
//    rw.readCode(arr, n);
//
//    string res = "";
//    //декодируем в строку
//    decodeLZ77(arr, n, res);
//    //записываем ответ в файл
//    rw.writeString(res);
//
//    delete[] arr;
//
//    return 0;
//}
