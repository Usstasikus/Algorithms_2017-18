
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;


void heapify(int *numbers, int array_size, int index){
    int largest = index;
    int left = index * 2, right = left + 1;
    if (left < array_size - 1 && numbers[left] > numbers[largest])
        largest = left;
    if (right < array_size && numbers[right] > numbers[largest])
        largest = right;
    if (largest != index){
        std::swap(numbers[index], numbers[largest]);
        heapify(numbers, array_size, largest);
    }
}

void buildHeap(int *numbers, int array_size){
    for (int i = array_size/2; i >= 0 ; --i)
        heapify(numbers, array_size, i);
}

void heapSort(int *numbers, int array_size)œ
{
    buildHeap(numbers, array_size);

    for (int i = 1; i <= array_size - 1; ++i)
    {
        std::swap(numbers[0], numbers[array_size - i]);
        heapify(numbers, array_size - i, 0);
    }
}


int main() {
    int *brr;
    int n;

    fstream fin;
    fin.open("input.txt",ios::in);
    if(fin.is_open()) {
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++) {
            fin >> brr[i];
        }

        fin.close();
    }
    heapSort(brr, n);
    fstream fout;
    fout.open("output.txt",ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;

}
