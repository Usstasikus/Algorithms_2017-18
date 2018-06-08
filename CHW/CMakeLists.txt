cmake_minimum_required(VERSION 3.8)
project(CHW)
set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp
        huffman.cpp  huffman.h
        ReadWriter.cpp ReadWriter.h
        shennonFano.cpp shennonFano.h NodeLZ77.h
        LZ77.cpp LZ77.h)
add_executable(CHW ${SOURCE_FILES})