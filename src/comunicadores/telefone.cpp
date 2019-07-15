#include "telefone.h"
#include <cstring>
#include <iostream>

using namespace std;

Telefone::Telefone(){ }

Telefone::Telefone(string marca, string modelo, string cor, int alt, int larg, int volMax)
    :marca(marca), modelo(modelo), cor(cor), altura(alt), largura(larg), volMax(volMax)
    { }


string Telefone::getMarca() const{
    return marca;
}

string Telefone::getModelo() const{
    return modelo;
}

string Telefone::getCor() const{
    return cor;
}

float Telefone::getTxTransmissao() const{
    return txTransmissao;
}

int Telefone::getAltura() const{
    return altura;
}

int Telefone::getLargura() const{
    return largura;
}

int Telefone::getVolMax() const{
    return volMax;
}

void Telefone::setMarca(string marca){
    this->marca = marca;
}

void Telefone::setModelo(string modelo){
    this->modelo = modelo;
}

void Telefone::setCor(string cor){
    this->cor = cor;
}

void Telefone::setTxTransmissao(float tx){
    txTransmissao = tx;
}

void Telefone::setAltura(int alt){
    altura = alt;
}

void Telefone::setLargura(int larg){
    largura = larg;
}

void Telefone::setVolMax(int vmax){
    volMax = vmax;
}

void Telefone::print(){
    std::cout << ":: Telefone :: " << std::endl;
    std::cout << ": Marca: " << marca << std::endl;
    std::cout << ": Modelo: " << modelo << std::endl;
    std::cout << ": Cor: " << cor << std::endl;
    std::cout << ": Tx Transmissão: " << txTransmissao << std::endl;
    std::cout << ": Altura: " << altura << std::endl;
    std::cout << ": Largura: " << largura << std::endl;
    std::cout << ": Vol Max: " << volMax << std::endl << std::endl;
}
