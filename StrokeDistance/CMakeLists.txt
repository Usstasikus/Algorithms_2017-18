cmake_minimum_required(VERSION 3.8)
project(StrokeDistance)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Levenshtein.cpp Wagner-Fisher.cpp)
add_executable(StrokeDistance ${SOURCE_FILES})