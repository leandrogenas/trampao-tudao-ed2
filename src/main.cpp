#include <iostream>
#include <src/estruturas/HashTable.h>
#include <cmath>
#include <functional>
#include <src/comunicadores/Radio.h>

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


int main()
{
    HashTable hash;

    string tipos[QTD_ITENS] = { ROTEADOR, COMUNICADOR, TEL_SEM_FIO, CELULAR, RADIO, TELEFONE, WALKIE_TALKIE };
    string marcas[QTD_ITENS]  = { "TP-Link", "Motorola", "Panasonic", "Black&Decker", "Apple", "Xiaomi", "LG" };
    string modelos[QTD_ITENS] = { "Archer C60", "DynaTAC", "EASA Phone System", "BDCSP18N", "iPhone 6s", "Mi Mix 2", "LG G5" };
    float frequencias[QTD_ITENS] = { DOIS_QUATROGHZ,  FREQ(4.5, 5), FREQ(0, 0), FREQ(10, 10), DOIS_QUATROGHZ, DOIS_QUATROGHZ, DOIS_QUATROGHZ };
    float txsTransmissao[QTD_ITENS] = { (float) pow(10, 6), (float) pow(10, 1), (float) pow(10, 1), (float) pow(10, 1), (float) pow(10, 5), (float) pow(10, 5), (float) pow(10, 5)  };
    float tensao[QTD_ITENS] = { 12.0, 12.0, 6.0, 5.0, 5.0, 5.0, 5.0 };
    float potencia[QTD_ITENS] = { 10.0, 7.0, 5.0, 5.0, 15.0, 12.0, 12.0 };
    float alcance[QTD_ITENS] = { 100, (float) pow(10, 3), 0.0, ALCANCE_GLOBAL(), ALCANCE_GLOBAL(), ALCANCE_GLOBAL(), ALCANCE_GLOBAL() };

    for (int i = 0; i < 7; i++)
        Comunicador c(marcas[i], modelos[i], frequencias[i], txsTransmissao[i], tensao[i], potencia[i], alcance[i]);

    Comunicador cTeste("Motorola", "Moto G5", FREQ(315, 6), 10000, 12.0, 15.0, ALCANCE_GLOBAL());

    Radio r(cTeste, 1.0, 2.0, 100, true, true, false);
    hash.insertItem((Comunicador &) r);

}
