//
// Created by Stas Don on 15/03/2018.
//

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sys/stat.h>

#include "NodeLZ77.h"
#include "ReadWriter.h"

class LZ77 {

public:


    LZ77() :dict_size_Kb(4), buff_size_Kb(1),
            path_to_route_folder( "../resources/LZ775/" ),
            path_to_LZ77ed( path_to_route_folder +"Encoded/" ),
            path_to_deLZ77ed( path_to_route_folder + "Decoded/" )

    {};

    /// \param d_size_Kb - размер словаря в Кб
    /// \param b_size_Kb - размер буфера предпросмотра в Кб
    LZ77(int d_size_Kb, int b_size_Kb) :dict_size_Kb(d_size_Kb), buff_size_Kb(b_size_Kb),
                                        path_to_route_folder( "../resources/LZ77" + std::to_string(d_size_Kb + b_size_Kb) + "/"),
                                        path_to_LZ77ed( path_to_route_folder + "Encoded/" ),
                                        path_to_deLZ77ed( path_to_route_folder + "Decoded/" )
    {};

    /// Архивация файла с помощью алгоритма LZ77
    /// \param filename - имя файла для архивации
    void encode(const std::string& filename);


    /// Разархивация файла с помощью алгоритма LZ77
    /// \param filename - имя файла для разархивации
    void decode(const std::string& filename);

//    int getDictSize(){ return dict_size_Kb;}
//    void setDictSize(int d_size_Kb){ dict_size_Kb = d_size_Kb;}
//
//    int getBuffSize(){ return buff_size_Kb;}
//    void setBuffSize(int b_size_Kb){ buff_size_Kb = b_size_Kb;}
    void writeDataCompression();


private:
    NodeLZ77 findMaxSubstr(std::string &s, int dictBuf, int currSymb);

public:
    const std::string path_to_route_folder;

private:
    int buff_size_Kb;//размер словаря в Кб
    int dict_size_Kb;//размер буфера предпросмотра в Кб
    ReadWriter readWriter;
    const std::string path_to_files = "../resources/toencode/";
    const std::string path_to_LZ77ed;
    const std::string path_to_deLZ77ed;
};

#ifndef CHW_LZ77_H
#define CHW_LZ77_H

#endif //CHW_LZ77_H
