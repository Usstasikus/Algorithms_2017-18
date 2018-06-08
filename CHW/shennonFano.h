//
// Created by Stas Don on 15/03/2018.
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <sys/stat.h>

#include "ReadWriter.h"


#ifndef CHW_SHENNONFANO_H
#define CHW_SHENNONFANO_H
class ShannonFano
{
public:

    /// Кодировка символов алгоритмом Шеннона-Фано
    /// \param start - начало текующего отрезка
    /// \param end - конец текующего отрезка
    /// \param sum - сумма включений текующего отрезка
    void shennonFano(int start, int end, int sum);

    /// Архивация файла с помощью алгоритма Шеннона-Фано
    /// \param filename - имя файла для архивации
    void encode(const std::string& filename);

    /// Разархивация файла с помощью алгоритма Шеннона-Фано
    /// \param filename - имя файла для разархивации
    void decode(const std::string& filename);

    void writeDataCompression();
private:

    /// Подсчет вхождений элементов
    /// \param text - текст
    /// \return вектор пар (символ, кол-во вхождений)
    std::vector<std::pair<char, int>> countSymbols(const std::string &text, unsigned long int &n);

public:
    const std::string path_to_route_folder = "../resources/Shennon-Fano/";

private:
    std::vector<std::pair<char, int>> freqs;
    std::unordered_map<char, std::string> codes;
    unsigned long int n;
    ReadWriter readWriter;

    const std::string path_to_files = "../resources/toencode/";
    const std::string path_to_shanned = path_to_route_folder + "Encoded/";
    const std::string path_to_deshanned = path_to_route_folder + "Decoded/";

};
#endif //CHW_SHENNONFANO_H
