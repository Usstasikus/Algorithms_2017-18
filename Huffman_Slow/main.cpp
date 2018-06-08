
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;


class Huffman
{
public:

    void build()
    {
        // запускает алгоритм (после того как были добавлены все элементы)
        huff(n);
    }
    void addChance (int chance)
    {
        codes.push_back("");
        freqs.push_back(chance);
        n++;
      // добавляет элемент в список (дерево, все зависит от реализации)
    }
    string get (int i)
    {
        return codes[i];
    }

    void init(){

    }

    void huff(int n)
    {
        if(n == 2)
        {
            codes[0] = "1";
            codes[1] = "0";

        }
        else
        {
            int q = freqs[n - 2] + freqs[n - 1];
            int j = up(n, q);
            huff(n - 1);
            down(n, j);

        }

    }

    int up(int n, int q)
    {
        int i = n - 1;
        while (i > 0 && freqs[i - 1] < q)
        {
            freqs[i] = freqs[i - 1];
            --i;
        }
        freqs[i] = q;
        return i;
    }

    void down(int n, int j)
    {
        string code = codes[j];
        for (int i = j; i < n - 2; i++){
            codes[i] = codes[i + 1];
        }
        codes[n - 2] = code + "1";
        codes[n - 1] = code + "0";
    }
    vector<int> freqs;
    vector<string> codes;
    int n = 0;
};

int main() {

    int n;
    Huffman * huff = new Huffman();
    fstream fin;
        fin.open("input.txt",ios::in);
        if(fin.is_open()) {
            fin >> n;
            for (int i = 0; i < n; i++) {
                int x;
                fin >> x;
               huff->addChance (x);
            }
    
            fin.close();
       
        huff->build();
        fstream fout;
        fout.open("output.txt",ios::out);
            for (int i = 0; i < n; i++){
                fout << huff->get(i) << (i==n-1?"":" ");
                }
        fout.close();
        delete huff;
            
        }
  
        return 0;

}


