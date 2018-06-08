//
// Created by Stas Don on 15/04/2018.
//

//
// Created by Stas Don on 15/04/2018.
//

//
// Created by Stas Don on 15/04/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void get_camps_next(vector<int> &camps, int &last)
{
    int i = last - 1, sum = camps[last];
    while(i > 0 && camps[i - 1] <= camps[i])
    {
        sum += camps[i];
        --i;
    }
    camps[i] += 1;
    last = i + sum - 1;

    for (int j = i + 1; j <= last; ++j)
    {
        camps[j] = 1;
    }
}
void get_camps(int N)
{
    ofstream fout("output.txt");
    vector<int> camps(N, 1);
    int last = N - 1;
    for (int i = 0; i < last; ++i)
        fout << camps[i] << " ";
    fout << camps[last];
    while(last > 0)
    {
        fout << endl;
        get_camps_next(camps, last);
        for (int i = 0; i < last; ++i)
            fout << camps[i] << " ";
        fout << camps[last];
    }
    fout.close();
}


//
//void get_camps(int N)
//{
//    vector<int> camps(N, 1);
//    ofstream fout("output.txt");
//
//
//    for (int j = 0; j < N; ++j)
//        cout << "1 ";
//
//    int last = N;
//    while(true)
//    {
//        cout << endl;
//
//        int k = last - 1, sum = 0;
//        while(k > 0 && camps[k - 1] <= camps[k])
//        {
//            sum += camps[k];
//            --k;
//        }
//        ++camps[k];
//        for (int i = 0; i < k; ++i)
//            cout << camps[i] << " ";
//
//        cout << camps[k];
//
//        last =  k + sum - 1;
//        for (int i = k + 1; i <= last ; ++i)
//        {
//            cout << " 1";
//            camps[i] = 1;
//        }
//
//
//        if (last <= 0)
//            break;
//
//    }
//    fout.close();
//}
//

int main() {
    ifstream fin("input.txt");

    int N, M, k;
    fin >> N;
    get_camps(N);

//    long a = 1;
//    for (int i = 1; i <= 5; ++i) {
//        a *= (i);
//    }
//
//    for (int j = 1; j <= a; ++j) {
//        cout << get_day(5, 5, j) << endl;
//    }

    fin.close();
}