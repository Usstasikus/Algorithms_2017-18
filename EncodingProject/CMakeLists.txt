cmake_minimum_required(VERSION 3.8)
project(EncodingProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp huffman.cpp huffman.hpp)
add_executable(EncodingProject ${SOURCE_FILES})