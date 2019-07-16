#pragma once

#include "Telefone.h"

class TelSemFio: public Telefone{

private:
    int autonomia;
    bool temBluetooth;

public:
    TelSemFio(
        Telefone t,
        const int autonomia,
        const bool bluetooth): Telefone(t)
    {
        this->autonomia = autonomia;
        this->temBluetooth = bluetooth;
    }

    bool possuiBluetooth() const { return this->temBluetooth; }
    int getAutonomia() const { return this->autonomia; }

    void setPossuiBluetooth(const bool bluetooth){ this->temBluetooth = bluetooth; }
    void setAutonomia(const int aut){ this->autonomia = aut; };

    void print() override
    {
        Telefone::print();
        cout << "+--------------------------------------------------" << endl;
        cout << "|  O comunicador em questao e um telefone sem fio  " << endl;
        cout << "| - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "|  - Autonomia: " << getAutonomia() << " dias" << endl;
        cout << "|  - Possui bluetooth? " << ((possuiBluetooth()) ? "Sim" : "Não") << endl;
        cout << "+--------------------------------------------------" << endl;
    }

};

