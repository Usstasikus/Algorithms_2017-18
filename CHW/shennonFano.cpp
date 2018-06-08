//
// Created by Stas Don on 07/03/2018.
//

#include "shennonFano.h"

using namespace std;

bool cmp(const std::pair<char, int> &it1, const std::pair<char, int> &it2) {
    return it1.second > it2.second;
}

vector<pair<char, int>> ShannonFano::countSymbols(const string &source_filename, unsigned long int &n) {
    unordered_map<char, int> symbols;//словарь вхождений символов
    n = 0;
    ifstream fin(source_filename);
    if(fin.is_open()) {
        char symb;
        while(fin.get(symb)){
            ++n;
            if (symbols.find(symb) == symbols.end())
                symbols[symb] = 1;
            else
                symbols[symb] += 1;
        }
        //сортируем в порядке убывания кол-ва вхождений
        vector<pair<char, int>> vec_symbs(symbols.begin(), symbols.end());
        sort(vec_symbs.begin(), vec_symbs.end(), cmp);

        return vec_symbs;
    } else
        throw std::ios_base::failure("file not open");

}

void ShannonFano::shennonFano(int start, int end, int sum) {
    int sum_first = 0;
    int median = start;


    //проход, пока сумма первой части <= сумме второй
    while (abs(2 * (sum_first + freqs[median].second) - sum) <= abs(2 * sum_first - sum))
    {
        codes[freqs[median].first] += '0';
        sum_first += freqs[median].second;
        ++median;
    }

    //для второй части записываем коды '0'
    for (int i = median; i <= end; ++i)
        codes[freqs[i].first] += '1';

    if (median - 1 != start)
        shennonFano(start, median - 1, sum_first);
    if (median != end)
        shennonFano(median, end, sum - sum_first);

}

void ShannonFano::encode(const string &filename) {
    unsigned long int n;
    freqs = countSymbols(path_to_files + filename, n);
    shennonFano(0, freqs.size() - 1, n - 1);
    readWriter.writeEncodedText(codes, path_to_files + filename, path_to_shanned + filename + ".shan");
}

void ShannonFano::decode(const std::string &filename) {
    readWriter.writeDecodedText(path_to_shanned + filename + ".shan", path_to_deshanned +  filename + ".unshan");
}

void ShannonFano::writeDataCompression() {
    ofstream fout(path_to_route_folder+ "datacompression.csv");
    fout << "file_num,compr" << endl;

    if(fout.is_open())
    {
        for(int i = 0; i < 36; ++i) {
            struct stat buf;
            string filename = (path_to_files + to_string(i + 1));
            stat(filename.c_str(), &buf);
            off_t size_original = buf.st_size;

            filename = (path_to_shanned + to_string(i + 1) + ".shan");
            stat(filename.c_str(), &buf);
            off_t size_encoded = buf.st_size;

            fout << (double)size_encoded/(double)size_original << endl;
        }
        fout.close();
    }
}

