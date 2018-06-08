#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <utility>
using namespace std;

void quickSort(int *numbers, int l, int r)
{

    cout<<endl<<l<<" "<<r<<endl;
    int x = numbers[(r + l)/2];
    //rand()%(r-l+1) + l;
    //r;

    int i = l, j = r;

    do
    {
        while(numbers[i] < x)
            ++i;

        while(numbers[j] > x)
            --j;

        if(i <= j)
            std::swap(numbers[j--], numbers[i++]);

    }while(i <= j);

    for (int k = 0; k < 15; k++)
        cout<<numbers[k];
    cout<<endl;
    if(l < j)
        quickSort(numbers, l, j);
    if(i < r)
        quickSort(numbers, i, r);
}

int main()
{
    int *brr;
    int n;

    fstream fin;
    fin.open("input.txt",ios::in);
    if (fin.is_open())
    {
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fin.close();
    }
    quickSort(brr, 0, n - 1);
    fstream fout;
    fout.open("output.txt",ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}