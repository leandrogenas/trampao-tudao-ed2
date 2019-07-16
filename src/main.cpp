#include <iostream>
#include <src/estruturas/HashTable.h>
#include <cmath>
#include <functional>
#include <src/comunicadores/Radio.h>
#include <include/OpcoesMenu.h>
#include <vector>
#include <src/estruturas/Heap.h>

using namespace std;


#define QTD_ITENS 7
#define TEL_SEM_FIO "tsf"
#define COMUNICADOR "comm"
#define TELEFONE "tel"
#define CELULAR "cel"
#define RADIO "radio"
#define ROTEADOR "roteador"
#define WALKIE_TALKIE "wk"

#define FREQ(X, D) ((float)({[](float x, int d){ return (float)(x * pow(10, d));};})(X, D))
#define DOIS_QUATROGHZ ((float)( 2.4 * pow(10,6)))
#define ALCANCE_GLOBAL (float)({[]{ return (float)(6.3 * pow(10, 5 + ((rand() % 100) / 1 - (rand() % 100)))); };})


void gerarComunicadoresTeste(vector<Comunicador *> &v)
{
    string marcas[QTD_ITENS]  = { "TP-Link", "Motorola", "Panasonic", "Black&Decker", "Apple", "Xiaomi", "LG" };
    string modelos[QTD_ITENS] = { "Archer C60", "DynaTAC", "EASA Phone System", "BDCSP18N", "iPhone 6s", "Mi Mix 2", "LG G5" };
    float frequencias[QTD_ITENS] = { DOIS_QUATROGHZ,  FREQ(4.5, 5), FREQ(0, 0), FREQ(10, 10), DOIS_QUATROGHZ, DOIS_QUATROGHZ, DOIS_QUATROGHZ };
    float txsTransmissao[QTD_ITENS] = { (float) pow(10, 6), (float) pow(10, 1), (float) pow(10, 1), (float) pow(10, 1), (float) pow(10, 5), (float) pow(10, 5), (float) pow(10, 5)  };
    float tensao[QTD_ITENS] = { 12.0, 12.0, 6.0, 5.0, 5.0, 5.0, 5.0 };
    float potencia[QTD_ITENS] = { 10.0, 7.0, 5.0, 5.0, 15.0, 12.0, 12.0 };
    float alcance[QTD_ITENS] = { 100, (float) pow(10, 5), 0.0, ALCANCE_GLOBAL(), ALCANCE_GLOBAL(), ALCANCE_GLOBAL(), ALCANCE_GLOBAL() };

    for (int i = 0; i < QTD_ITENS; i++)
        v.push_back(new Comunicador(marcas[i], modelos[i], frequencias[i], txsTransmissao[i], tensao[i], potencia[i], alcance[i]));

    v.erase(v.begin());
}

void testeHashTable(vector<Comunicador *> &comms)
{
    HashTable hash = HashTable::nova(comms);
    hash.print();
}

void testeHeap(vector<Comunicador *> &comms)
{
    Heap heap = Heap::nova(comms);
    heap.print();
}

int main()
{
    string tiposComm[QTD_ITENS] = {
        ROTEADOR,
        COMUNICADOR,
        TEL_SEM_FIO,
        CELULAR,
        RADIO,
        TELEFONE,
        WALKIE_TALKIE
    };

    vector<Comunicador *> comms { nullptr };
    gerarComunicadoresTeste(comms);

    OpcoesMenu menu;
    int opc = 0;
    do{
        opc = menu.nivel1();
        switch(opc){
            case OPC_HASH: testeHashTable(comms);
            case OPC_HEAP: testeHeap(comms);
            default: continue;
        }
    }while(opc != OPC_VOLTAR);

}
