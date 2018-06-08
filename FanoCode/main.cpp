#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;


class ShannonFano
{
public:

    ~ShannonFano()
    {
        delete [] codes;
    }

    void build()
    {
        codes = new string[n];
        shennonFano(0, n - 1, sum);
    }

    void addChance(int chance)
    {
        freqs.push_back(chance);
        sum += chance;
        n++;
        // добавляет элемент в список (дерево, все зависит от реализации)
    }

    string get(int i)
    {
        return codes[i];
    }

    void shennonFano(int start, int end, int sum)
    {
        int sum_first = 0;
        int median = start;

        while (abs(2 * (sum_first + freqs[median]) - sum) < abs(2 * sum_first - sum))
        {
            codes[median] += '0';
            sum_first += freqs[median];
            ++median;
        }

        for (int i = median; i <= end; ++i)
            codes[i] += '1';
        if (median - 1 != start)
            shennonFano(start, median - 1, sum_first);
        if (median != end)
            shennonFano(median, end, sum - sum_first);

    }

    vector<int> freqs;
    string *codes;
    int sum = 0;
    int n = 0;

};


int main()
{

    int n;
    ShannonFano *shf = new ShannonFano();
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            fin >> x;
            shf->addChance(x);
        }

        fin.close();

        shf->build();
        fstream fout;
        fout.open("output.txt", ios::out);
        for (int i = 0; i < n; i++)
        {
            fout << shf->get(i) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        delete shf;

    }

    return 0;

}

