#pragma once

#include <iostream>
#include "Comunicador.h"


using namespace std;

class Radio: public Comunicador
{
private:
    float fMin, fMax = 0.0;
    float volMax = 0.0;
    bool temAM = true;
    bool temFM = true;
    bool temConectorP2 = false;

public:
    Radio(Comunicador c): Comunicador(c){
        this->setFreqMin(c.getFrequencia());
        this->setFrequencia(fMin);

    }

    Radio(
        Comunicador c,
        const float fMin, const float fMax,
        const float volMax,
        const bool possuiAM, const bool possuiFM,
        const bool possuiConectorP2): Comunicador(c)
    {
        this->fMin = fMin;
        this->fMax = fMax;
        this->volMax = volMax,
        this->temAM = possuiAM;
        this->temFM = possuiFM;
        this->temConectorP2 = possuiConectorP2;
    }

    /* Getters */
    float getFreqMin(){ return fMin; }
    float getFreqMax(){ return fMax; }
    int getFrequenciaMedia(){ return (int)(fMin + fMax)/2; }
    float getVolMax(){ return volMax; }
    bool possuiAM(){ return temAM; }
    bool possuiFM(){ return temFM; }
    bool possuiConectorP2(){ return temConectorP2; }

    /* Setters */
    void setFreqMin(const float p){ this->fMin = p; }
    void setFreqMax(const float p){ this->fMax = p; }
    void setFrequencia(const float p) override
    {
        Comunicador::setFrequencia(p);
        setFreqMin(p);
    }
    void setVolMax(const float p){ this->volMax = p; }
    void setpossuiAM(const bool p){ this->temAM = p; }
    void setpossuiFM(const bool p){ this->temFM = p; }
    void setpossuiConectorP2(const bool p){ this->temConectorP2 = p; }

    virtual int getHash(int max)
    {
        float x = Comunicador::getFingerprint(max) * (getFrequenciaMedia()) + 2;
        return (int) x % max;
    }

    void print() override
    {
        Comunicador::print();
        cout << "+--------------------------------------------------" << endl;
        cout << "|  O comunicador em questao e um radio             " << endl;
        cout << "| - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "| - Freq. media de " << getFrequenciaMedia() << "hz." << endl;
        cout << "| - Varia de " << getFreqMin() << " e " << getFreqMax() << "hz" << endl;
        cout << "| - Possui volume maxima de " << getVolMax() << "db" << endl;
        cout << ((possuiAM()) ? "| - Possui AM" : "")
             << ((possuiFM()) ? "| - Possui FM" : "") << endl;
        cout << ((possuiConectorP2()) ? "| - E conector p2" : "") << endl;
        cout << "+--------------------------------------------------" << endl;
    }

};