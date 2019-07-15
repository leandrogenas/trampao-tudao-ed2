#include "celular.h"
#include <cstring>

Celular::Celular(Telefone* tel){
        this->setMarca(tel->getMarca());
        this->setModelo(tel->getModelo());
        this->setCor(tel->getCor());
        this->setTxTransmissao(tel->getTxTransmissao());
        this->setAltura(tel->getAltura());
        this->setLargura(tel->getLargura());
        this->setVolMax(tel->getVolMax());
    }

Celular::Celular(Telefone* tel, bool possui4g, string so)
    :lte(possui4g), so(so){
        this->setMarca(tel->getMarca());
        this->setModelo(tel->getModelo());
        this->setCor(tel->getCor());
        this->setTxTransmissao(tel->getTxTransmissao());
        this->setAltura(tel->getAltura());
        this->setLargura(tel->getLargura());
        this->setVolMax(tel->getVolMax());
    }

bool Celular::possui4G() const{
    return lte;
}

string Celular::getSo() const{
    return so;
}

void Celular::setPossui4G(bool possui){
    lte = possui;
}

void Celular::setSo(string so){
    this->so = so;
}

void Celular::print(){
    this->print();
    cout << ":: Celular ::";
    cout << ": Possui 4g? ";
    if(lte)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;

    cout << ": Sistema Operacional: " << so << endl;
}

