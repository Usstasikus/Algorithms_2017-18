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
    vector<int> max_saws(len);

    bool isDesc = true;
    max_saws[0] = 1;

    if (len > 1 && arr[1] != arr[0])
    {
        max_saws[1] = 2;
        if(arr[1] > arr[0])
            isDesc = false;
    }
    else
       max_saws[1] = 1;

    for (int i = 2; i < len; ++i)
    {
        if(isDesc){
            if(arr[i] > arr[i - 1] && (i == len - 1 || arr[i + 1] <= arr[i]))
            {
                max_saws[i] = max_saws[i - 1] + 1;
                isDesc = !isDesc;
            }
            else
                max_saws[i] = max_saws[i - 1];
        }
        else{
            if(arr[i] < arr[i - 1] && (i == len - 1 || arr[i + 1] >= arr[i]))
            {
                max_saws[i] = max_saws[i - 1] + 1;
                isDesc = !isDesc;
            }
            else
                max_saws[i] = max_saws[i - 1];
        }
    }
    int curr_len = 1;
    res.emplace_back(arr[0]);

    for(int i = 1; i < len; ++i)
    {
        if(max_saws[i] == curr_len)
            continue;
        res.emplace_back(arr[i]);
        ++curr_len;
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