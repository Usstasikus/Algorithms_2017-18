//#include <iostream>
//#include <fstream>
//#include <string>
//#include <stdlib.h>
//#include <vector>
//
//using namespace std;
//
//string getBorders(string input)
//{
//    int length = input.length();
//    int* borders = new int[length];//массив граней
//    borders[0] = 0;
//    string res = "";
//    for(int i = 1; i < length; ++i)
//    {
//        int j = borders[i-1];
//        while (j > 0 && input[i] != input[j])//если символы не равно
//            j = borders[j-1];//спускаемся на предшедствующую грань
//        if (input[i] == input[j])//если символы совпали
//            ++j;//добавляем 1 к количеству символов грани
//        borders[i] = j;
//    }
//
//    int j = length - 1;
//
//    vector<int> indices;//массив нужных граней
//    while(borders[j] > 0)//подсчет граней в строке
//    {
//        indices.push_back(borders[j]);
//        j = borders[j] - 1;
//    }
//
//    string prev_string = "";//постепенно нарастающая строка
//    int curr_border = indices.size() - 1;//количество нужных граней
//    for(int i = 0; i < length; ++i)
//    {
//        prev_string += input[i];//наращиваем строку
//        if(i == indices[curr_border] - 1)//если дошли до конца грани
//        {
//            res += prev_string + '\n';//записываем ее в результирующую строку
//            --curr_border;
//            if(curr_border == -1)
//                break;
//        }
//    }
//
//    delete[] borders;
//    return res;
//}
//
//int main()
//{
//    string input;
//    string res;
//
//    ifstream fin;
//    fin.open("input.txt");
//    if (fin.is_open())
//    {
//        getline(fin, input);
//        fin.close();
//    }
//
//    res = getBorders(input);
//
//    fstream fout;
//    fout.open("output.txt", ios::out);
//    fout << res;
//    fout.close();
//
//    return 0;
//}
//
