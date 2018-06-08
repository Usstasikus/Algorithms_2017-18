cmake_minimum_required(VERSION 3.8)
project(HW5_LZ77)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.h ReadWriter.h LZ77_Unpacking.cpp LZ77_Packing.cpp)
add_executable(HW5_LZ77 ${SOURCE_FILES})