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


void get_pizza(long N, long M, long k)
{
    vector<long> pizzas(M, 0);
    pizzas[0] = N;

    stack<long> ids;

    long curr = -1;
    for (long i = 0; i < k - 1; ++i)
    {
        if(curr + 1 < M - 1)
            ids.push(curr + 1);
        else
        {
            long temp = pizzas[curr + 1];
            pizzas[curr + 1] = 0;
            pizzas[ids.top() + 1] += temp;
        }

        curr = ids.top();

        pizzas[curr] -= 1;
        if(pizzas[curr] == 0)
            ids.pop();

        pizzas[curr + 1] += 1;
    }

    ofstream fout("output.txt");
    for (int j = 0; j < M - 1; ++j) {
        fout << pizzas[j] << " ";
    }
    fout << pizzas[M - 1];
    fout.close();
}


int main() {
    ifstream fin("input.txt");

    long N, M, k;
    fin >> N >> M >> k;
    get_pizza(N, M, k);

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