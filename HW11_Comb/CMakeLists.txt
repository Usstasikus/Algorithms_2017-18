cmake_minimum_required(VERSION 3.9)
project(HW11_Comb)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW11_Comb
        C.cpp
        bigInt/BigInteger2.h
        bigInt/BigIntegerAlgorithms.hh
        bigInt/BigIntegerUtils2.h)