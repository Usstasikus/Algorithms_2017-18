cmake_minimum_required(VERSION 3.8)
project(SkiPi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ReadWriter.h Solver.h Student_and_Ski.h)
add_executable(SkiPi ${SOURCE_FILES})