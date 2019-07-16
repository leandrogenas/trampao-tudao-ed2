#pragma once

#include "Telefone.h"

class Celular: public Telefone{

private:
    bool lte;
    string so;

public:
    Celular(Telefone*);
    Celular(Telefone*, bool, string);

    string getSo() const;
    bool possui4G() const;

    void setSo(string);
    void setPossui4G(bool);

    void print();

};
