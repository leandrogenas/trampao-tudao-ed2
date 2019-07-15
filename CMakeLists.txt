cmake_minimum_required(VERSION 3.14)
project(Trabalhos-ED2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(trampao-tudao
        src/comunicadores/celular.h
        src/comunicadores/comunicador.h
        src/comunicadores/Estoquezao.h
        src/comunicadores/radio.h
        src/comunicadores/roteador.h
        src/comunicadores/telefone.h
        src/comunicadores/telSemFio.h
        src/arvore.cpp
        src/avl.cpp
        src/comunicadores/celular.cpp
        src/comunicadores/comunicador.cpp
        src/hash.cpp
        src/heap.cpp
        src/main.cpp
        src/comunicadores/radio.cpp
        src/comunicadores/roteador.cpp
        src/comunicadores/telefone-sem-fio.cpp
        src/comunicadores/telefone.cpp)
