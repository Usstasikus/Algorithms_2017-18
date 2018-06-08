//
// Created by Stas Don on 22/04/2018.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void findPrime(vector<bool> &numbers)
{
    ofstream fout("output.txt");
    fout << 1 << " ";
    for (int curr = 1; curr < numbers.size(); ++curr)
    {
        if(numbers[curr] == false)
            continue;
        fout << curr + 1 << " ";

        int not_prime = curr + (curr + 1);
        while(not_prime < numbers.size() + 1)
        {
            numbers[not_prime] = false;
            not_prime += curr + 1;
        }

    }

    fout.close();
}

int main()
{
    ifstream fin("input.txt");
    int N, start, end;
    fin >> N;

    vector<bool> numbers(N, true);
    fin.close();

    findPrime(numbers);
    return 0;
}