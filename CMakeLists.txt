cmake_minimum_required(VERSION 3.14)
project(trampao-tudao CXX)

set(CMAKE_CXX_STANDARD 11)

set(PATH_SRC src)
set(PATH_COMM ${PATH_SRC}/comunicadores)
set(PATH_ESTRUTURAS ${PATH_SRC}/estruturas)

set(COMUNICADORES
    ${PATH_COMM}/Comunicador.h
    ${PATH_COMM}/Radio.h
    ${PATH_COMM}/Roteador.h
    ${PATH_COMM}/Telefone.h
    ${PATH_COMM}/TelefoneSemFio.h
    ${PATH_COMM}/Celular.h
    ${PATH_COMM}/WalkieTalkie.h
)

set(ESTRUTURAS
    ${PATH_ESTRUTURAS}/ArvoreDeBusca.h
    ${PATH_ESTRUTURAS}/ArvoreAVL.h
    ${PATH_ESTRUTURAS}/HashTable.h
    ${PATH_ESTRUTURAS}/Heap.h
)

set(ARQ_MAIN ${PATH_SRC}/main.cpp src/Utils.h src/OpcoesMenu.cpp include/OpcoesMenu.h)

include_directories(.)
include_directories(src)
include_directories(${PATH_COMM})
include_directories(${PATH_ESTRUTURAS})



add_executable(trampao-tudao ${COMUNICADORES} ${ESTRUTURAS} ${ARQ_MAIN})