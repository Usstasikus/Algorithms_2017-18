#include "ReadWriter.h"
#include "MergeSort.h"

using namespace std;

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read length from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}

//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
//Задача реализовать методы, можно добавлять любые свои методы
void MergeSort::sort(int *arr, int length)
{
    MergeSort::divide_and_merge(arr, 0, length - 1);
}


void MergeSort::merge(int* arr, int first, int second, int end)
{
    int len_arr1 = second - first + 1;
    int len_arr2 = end - second;

    int *arr1 = new int[len_arr1];
    int *arr2 = new int[len_arr2];

    int i = 0, j = 0;

    for(i = 0; i < len_arr1; i++)
        arr1[i] = arr[i + first];
    for(i = 0; i < len_arr2; i++)
        arr2[i] = arr[i + second + 1];

    int curr_ind = first;
    i = 0;
    j = 0;

    while(i < len_arr1 && j < len_arr2){
        if(arr1[i] > arr2[j])
            arr[curr_ind++] = arr2[j++];
        else
            arr[curr_ind++] = arr1[i++];
    }

    while(i < len_arr1)
        arr[curr_ind++] = arr1[i++];
    while(j < len_arr2)
        arr[curr_ind++] = arr2[j++];

    delete [] arr1;
    delete [] arr2;
}


void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    if (left < right){
        int m = (left + right)/2;
        MergeSort::divide_and_merge(arr, left, m);
        MergeSort::divide_and_merge(arr, m + 1, right);
        MergeSort::merge(arr, left, m, right);
    }
}