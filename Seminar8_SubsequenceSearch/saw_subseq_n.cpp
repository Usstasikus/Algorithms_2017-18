//
// Created by Stas Don on 12/03/2018.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;


vector<int> lis(int* arr, int len)
{
    vector<int> res;
    bool isDesc = true;
    res.emplace_back(arr[0]);
    if (len > 1 && arr[1] != arr[0])
    {
        res.emplace_back(arr[1]);
        if(arr[1] > arr[0])
            isDesc = false;
    }
    for (int i = 2; i < len; ++i)
    {
        if(isDesc){
            if(arr[i] > arr[i - 1] && (i == len - 1 || arr[i + 1] <= arr[i]))
            {
                res.emplace_back(arr[i]);
                isDesc = !isDesc;
            }
        }
        else{
            if(arr[i] < arr[i - 1] && (i == len - 1 || arr[i + 1] >= arr[i]))
            {
                res.emplace_back(arr[i]);
                isDesc = !isDesc;
            }
        }
    }
    return res;
}

int main()
{
    int len;
    int* arr = nullptr;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> len;
        arr = new int[len];
        for (int i = 0; i < len; i++)
            fin >> arr[i];
        fin.close();
    }

    res = lis(arr, len);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
        fout << res[i] << " ";
    fout.close();

    return 0;
}