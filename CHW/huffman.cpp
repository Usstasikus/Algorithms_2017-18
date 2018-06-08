//
// Created by Stas Don on 07/03/2018.
//

#include "huffman.h"

using namespace std;

void Huffman::huff() {
    HuffNode *left, *right, *top;
    while (min_heap.size() != 1) {
        left = min_heap.top();
        min_heap.pop();

        right = min_heap.top();
        min_heap.pop();
        top = new HuffNode(true, left->freq + right->freq, 0);

        top->left = left;
        top->right = right;

        min_heap.push(top);
    }
    setCodes(min_heap.top(), "");

}

void Huffman::setCodes(HuffNode *top, string code)
{
    if (!top->is_synt)
        codes[top->symb] = code;
    else {
        setCodes(top->left, code + "0");
        setCodes(top->right, code + "1");
    }
}


void Huffman::encode(const string &filename) {
    countSymbols(path_to_files + filename);
    huff();//запускаем кодирование символов
    readWriter.writeEncodedText(codes, path_to_files + filename, path_to_huffed + filename + ".haff");
}


void Huffman::decode(const string &filename)
{
    readWriter.writeDecodedText(path_to_huffed + filename + ".haff", path_to_dehuffed + filename + ".unhaff");
}


//void Huffman::countSymbols(const std::string &text)
void Huffman::countSymbols(const std::string &filename)
{

    map<char, int> nodes;
    fstream fin;
    fin.open(filename);
    if(fin.is_open())
    {
        char symb;
        while(fin.get(symb)) {
            if (codes.find(symb) == codes.end())//если нет такого
            {
                codes[symb] = "";//записываем в коды
                nodes[symb] = 1;//добавляем кол-во его вхождений
            } else
                nodes[symb] += 1;//увеличиваем кол-во вхождений символа
        }

        map<char, int>::const_iterator it = nodes.begin();
        while (it != nodes.end()) {
            min_heap.push(new HuffNode(false, it->second, it->first));
            ++it;
        }
        fin.close();
    }
}

void Huffman::writeDataCompression() {
    ofstream fout(path_to_route_folder + "datacompression.csv");
    fout << "file_num,compr" << endl;

    if(fout.is_open())
    {
        for(int i = 0; i < 36; ++i) {
            struct stat buf;
            string filename = (path_to_files + to_string(i + 1));
            stat(filename.c_str(), &buf);
            off_t size_original = buf.st_size;

            filename = (path_to_huffed + to_string(i + 1) + ".haff");
            stat(filename.c_str(), &buf);
            off_t size_encoded = buf.st_size;

            fout << (double)size_encoded/(double)size_original << endl;
        }
        fout.close();
    }
}

/*
 * TODO:
 * new Huffnode -> Huffnode
 */
