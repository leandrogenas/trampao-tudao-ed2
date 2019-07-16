#pragma once

#include <iostream>

using namespace std;

class Comunicador
{
private:
    string marca, modelo = "";
    float frequencia = 0.0f;
    float txTransmissao = 0.0f;
    float tensao, potencia = 0.0f;
    float alcance = 0;

protected:
public:

    Comunicador(
        const string marca, const string modelo,
        const float frequencia,
        const float txTransmissao,
        const float tensao, const float potencia,
        const float alcance)
    {
        this->marca = marca;
        this->modelo = modelo;
        this->frequencia = frequencia;
        this->txTransmissao = txTransmissao;
        this->tensao = tensao;
        this->potencia = potencia;
        this->alcance = alcance;
    }

    Comunicador(Comunicador &obj)
    {
        marca = obj.getMarca();
        modelo = obj.getModelo();
        frequencia = obj.getFrequencia();
        txTransmissao = obj.getTxTransmissao();
        tensao = obj.getTensao();
        potencia = obj.getPotencia();
        alcance = obj.getAlcance();
    }

    Comunicador(){ }

    /* Getters */
    virtual const string getMarca(){ return marca; }
    virtual const string getModelo(){ return modelo; }
    virtual const float getFrequencia(){ return frequencia; }
    virtual const float getTxTransmissao(){ return txTransmissao; }
    virtual const float getTensao(){ return tensao; }
    virtual const float getPotencia(){ return potencia; }
    virtual const float getAlcance(){ return alcance; }

    /* Setters */
    virtual void setMarca(const string p){ marca = p; }
    virtual void setModelo(const string p){ modelo = p; }
    virtual void setFrequencia(const float p){ frequencia = p; }
    virtual void setTxTransmissao(const float p){ txTransmissao = p; }
    virtual void setTensao(const float p){ tensao = p; }
    virtual void setPotencia(const float p){ potencia = p; }
    virtual void setAlcance(const float p){ alcance = p; }
    virtual string getNomeComunicador(){ return "Comunicador"; };

    virtual int getFingerprint(int max)
    {
        int y = (((int) marca[0]) + 1) * (((int) modelo[0]) + 1);
        float x = (y * getPotencia() + getAlcance());
        return (int)(x / max);
    }


    virtual void print()
    {
        cout << "==========================+=========================" << endl;
        cout << "|  Comunicador cadastrado                  " << endl;
        cout << "|- - - - - - - - - - + - - - - - - - - - - - - - - -" << endl;
        cout << "|  " << getMarca() << ", " << getModelo() << endl;
        cout << "|---------------------------------------------------" << endl;
        cout << "| - Freq: " << getFrequencia() << "hz, - Transf: " << getTxTransmissao() << "bps" << endl;
        cout << "| - Tensao: " << getTensao() << "v, - Pot: " << getPotencia() << "w" << endl;
        cout << "| - Alcance: " << getAlcance() << " metros" << endl;
    }

};
