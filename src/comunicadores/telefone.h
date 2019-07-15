#pragma once
#include <iostream>

using namespace std;

class Telefone{

private:
    string marca;
    string modelo;
    string cor;
    float txTransmissao;
    int altura, largura;
    int volMax;

public:
    Telefone();
    Telefone(string, string, string, int, int, int);

    string getMarca() const;
    string getModelo() const;
    string getCor() const;
    float getTxTransmissao() const;
    int getAltura() const;
    int getLargura() const;
    int getVolMax() const;

    void setMarca(string);
    void setModelo(string);
    void setCor(string);
    void setTxTransmissao(float);
    void setAltura(int);
    void setLargura(int);
    void setVolMax(int);

    void print();

};
