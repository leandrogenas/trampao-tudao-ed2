#pragma once

#include "telefone.h"

class TelSemFio: public Telefone{

private:
    int alcance;
    float frequencia;
    int autonomia;

public:
    TelSemFio(Telefone*);
    TelSemFio(Telefone*, int, float, int);

    int getAlcance() const;
    float getFrequencia() const;
    int getAutonomia() const;

    void setAlcance(int);
    void setFrequencia(float);
    void setAutonomia(int);

    void print();

};

