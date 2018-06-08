////
//// Created by Stas Don on 22/02/2018.
////
//
//#include "ReadWriter.h"
////в ReadWriter.h все подключено (Node.h, string, vector, iostream..)
//using namespace std;
//int findMaxSubstr(string &s, int dictBuf, int currSymb, vector<Node> &res);
//
//
//// s — исходная строка
//// res - вектор троек (offs, len, ch)
//// histBufMax, prevBufMax - Макс длины буферов истории и предпросмотра
//// функция возвращает список блоков
//void encodeLZ77(string& s, vector<Node>& res, int dictBufMax, int prevBufMax)
//{
//    int dictBuf = 0;//буфер словаря
//
//    for (int i = 0; i < s.size() && s[i] != '#'; ++i)
//    {
//        int len = findMaxSubstr(s, dictBuf, i, res);
//        i += len;
//        dictBuf = min(dictBufMax, dictBuf + len + 1);
//    }
//
//    //Советую подумать о декомпозиции, не стоит писать весь код в один метод, будет неудобно отлаживать
//}
//
//int findMaxSubstr(string &s, int dictBuf, int currSymb, vector<Node> &res)
//{
//
//    int indexSubstr = currSymb - dictBuf;
//
//    int maxLen = 0;//длина максимальной подстроки
//    int maxIndexSubstr = 0;//индекс начала максимальной подстроки
//    int maxCurrSymb = 0;//индекс символа после максимальной подстроки
//
//    int buffEnd = currSymb;//конец словаря
//
//    while(indexSubstr < buffEnd) //максимальная подстрока должна начинаться в словаре
//    {
//        int len = 0;//длина подстроки
//
//        while (s[indexSubstr] == s[currSymb])
//        {
//            ++indexSubstr;
//            ++currSymb;
//            ++len;
//        }
//
//        indexSubstr -= len;
//        if(len > maxLen)//перезаписываем данные о максимальной подстроке
//        {
//            maxLen = len;
//            maxIndexSubstr = indexSubstr;
//            maxCurrSymb = currSymb;
//        }
//
//        ++indexSubstr;//следующщий символ
//        currSymb = buffEnd;//возвзращаемся назад
//    }
//    if(maxLen == 0)
//        res.emplace_back(Node(0, 0, s[currSymb]));
//    else
//        res.emplace_back(Node(buffEnd - maxIndexSubstr, maxLen, s[maxCurrSymb]));
//    return maxLen;
//
//}
//
//
//
//int main(int argc, const char* argv[])
//{
//    //Здесь предлагается задать размер окна в байтах (отдельно буфера предыстории и предпросмотра)
//    //В сумме должны образовывать столько, сколько надо в задании
//    //history buffer 3 kb
//    int histBufMax = 1024*3;
//    //preview buffer 1 kb
//    int prevBufMax = 1024;
//
//    ReadWriter rw;
//    string s = "";
//    rw.readString(s);
//
//    //Основной структурой выбран вектор, так как заранее неизвестно какое количество элементов будет записано
//    vector<Node> v;
//
//    encodeLZ77(s, v, histBufMax, prevBufMax);
//
//    rw.writeCode(v);
//    return 0;
//}