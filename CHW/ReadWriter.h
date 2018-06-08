//
// Created by Stas Don on 07/03/2018.
//

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include "NodeLZ77.h"

#ifndef CHW_READWRITER_H
#define CHW_READWRITER_H


class ReadWriter
{
private:

    std::fstream fin;
    std::fstream fout;

public:
//    //read 1 line
//    void readString(std::string &s, const std::string name);
//
//
//    //Write string
//    void writeString(std::string &s, const std::string name);
//    // read 1 int value
//    int readInt();

    /// Перевод из байта в строку
    /// \param byte_signed - байт
    /// \return - строковое представление байта
    std::string byteToString(char &byte_signed, char amount = 8);

    /// Перевод из строки в байт
    /// \param byte_string - строковое представление байта
    /// \return - байт
    unsigned char stringToByte(std::string &byte_string);


//    int byteArrayToInt(char *bytes);

    /// Чтение текста из файла
    /// \param s - адрес чтения
    /// \param name - имя файла для чтения
    void readText(std::string &s, const std::string name);

    /// Чтение закодированного файла (алгоритмами Хаффмана или Шеннона-Фано) и заполняет словарь кодов
    /// \param text - закодированный текст
    /// \param decoding_map - словарь кодов
    /// \param unused_bites - кол-во неиспользуемых бит в конце файла
    /// \param filename - имя файла для чтения
    void readEncodedText(std::string &text,  std::unordered_map<std::string, char> &decoding_map, int &unused_bites, const std::string &filename);

    /// Чтение закодированного файла (алгоритмом LZ77)
    /// \param n - кол-во блоков
    /// \param filename - имя файла для чтения
    /// \return массив блоков
    NodeLZ77* readEncodedText(int &n, const std::string &filename);

    /// Запись строкового представления байтов в файл
    /// \param byte_string - строковое представления байтов
    /// \param fout - имя файла для записи
    void writeBytes( std::string &byte_string, std::fstream &fout);

    /// Запись закодированного файла (алгоритмами Хаффмана или Шеннона-Фано)
    /// \param codes - словарь кодов
    /// \param text - текст файла
    /// \param filename - имя файла для записи
//    void writeEncodedText(std::unordered_map<char, std::string> &codes, const std::string& source_text_filename, const std::string& filename);
    void writeEncodedText(std::unordered_map<char, std::string> &codes, const std::string& source_text_filename, const std::string& filename);

    /// Запись декодированного текста
    /// \param text - закодированный текст
    /// \param decoding_map - словарь кодов
    /// \param unused_bites - кол-во неиспользуемых бит в конце файла
    /// \param filename - имя файла для записи
//    void writeDecodedText(const std::string &text, std::unordered_map<std::string, char> &decoding_map, const std::string &filename);
    void writeDecodedText(const std::string &encoded_text_filename, const std::string &filename);

    /// Запись закодированного файла (алгоритмом LZ77)
    /// \param nodes - массив блоков
    /// \param filename - имя файла для записи
    void writeEncodedText(const std::vector<NodeLZ77> &nodes, const std::string &filename);
//    void writeNumberAndText(const int &n, const std::string &text, const std::string &filename);

    /// Запись текста в файл
    /// \param text - текст
    /// \param filename - имя файла для записи
    void writeText(const std::string &text, const std::string &filename);

    void readCode(NodeLZ77* arr, int n);
};

#endif //CHW_READWRITER_H
