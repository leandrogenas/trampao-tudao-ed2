cmake_minimum_required(VERSION 3.14)
project(Trabalhos-ED2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(trampao-tudao
        src/include/Hash.h
        src/include/account.h
        src/account.cpp
        src/Hash.cpp
        src/main.cpp)
