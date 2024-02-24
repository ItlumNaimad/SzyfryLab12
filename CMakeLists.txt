cmake_minimum_required(VERSION 3.26)
project(Szyfrowanie)

set(CMAKE_CXX_STANDARD 17)

add_executable(Szyfrowanie main.cpp
        Szyfr.cpp
        Szyfr.h)
