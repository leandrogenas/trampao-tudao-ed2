#pragma once
#include <iostream>
#include "Comunicador.h"

using namespace std;

class Telefone: public Comunicador
{

private:
    string cor;
    int altura, largura;
    int volMax;

public:

    Telefone(
        Comunicador c,
        const string cor,
        const int altura,
        const int largura,
        const int volMax): Comunicador(c)
    {
        this->cor = cor;
        this->altura = altura;
        this->largura = largura;
        this->volMax = volMax;
    }

    string getCor() const { return cor; };
    int getAltura() const { return altura; };
    int getLargura() const { return largura; };
    int getVolMax() const { return volMax; };

    void setCor(const string cor){ this->cor = cor; };
    void setAltura(const int alt){ this->altura = alt; };
    void setLargura(const int larg){ this->largura = larg; };
    void setVolMax(const int vol){ this->volMax = vol; };

    void print() override
    {
        Comunicador::print();
        cout << "+--------------------------------------------------" << endl;
        cout << "|  O comunicador em questao e um telefone          " << endl;
        cout << "| - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "|  - Cor: " << getCor() << ", Dimensoes: " << getLargura() << "x" << getAltura() << endl;
        cout << "|  - Volume maximo: " << getVolMax() << endl;
        cout << "+--------------------------------------------------" << endl;
    }

};
