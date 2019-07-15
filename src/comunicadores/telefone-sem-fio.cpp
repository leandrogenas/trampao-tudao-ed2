#include "telSemFio.h"

TelSemFio::TelSemFio(Telefone* tel){
        this->setMarca(tel->getMarca());
        this->setModelo(tel->getModelo());
        this->setCor(tel->getCor());
        this->setTxTransmissao(tel->getTxTransmissao());
        this->setAltura(tel->getAltura());
        this->setLargura(tel->getLargura());
        this->setVolMax(tel->getVolMax());
    }

TelSemFio::TelSemFio(Telefone* tel, int alcance, float frequencia, int autonomia)
    :alcance(alcance), frequencia(frequencia), autonomia(autonomia) {
        this->setMarca(tel->getMarca());
        this->setModelo(tel->getModelo());
        this->setCor(tel->getCor());
        this->setTxTransmissao(tel->getTxTransmissao());
        this->setAltura(tel->getAltura());
        this->setLargura(tel->getLargura());
        this->setVolMax(tel->getVolMax());
    }

int TelSemFio::getAlcance() const{
    return alcance;
}

float TelSemFio::getFrequencia() const{
    return frequencia;
}

int TelSemFio::getAutonomia() const{
    return autonomia;
}

void TelSemFio::setAlcance(int alc){
    alcance = alc;
}

void TelSemFio::setAutonomia(int aut){
    autonomia = aut;
}

void TelSemFio::setFrequencia(float freq){
    frequencia = freq;
}

void TelSemFio::print(){
    this->print();
    cout << ":: Telefone sem fio ::" << endl;
    cout << ": Alcance:  " << alcance << endl;
    cout << ": Frequencia:  " << frequencia << endl;
    cout << ": Autonomia:  " << autonomia << endl;
}
