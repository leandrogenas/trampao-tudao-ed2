#include <iostream>
#include "Comunicador.h"

using namespace std;

class Roteador: public Comunicador
{
private:
    string ip = "0.0.0.0";
    int versaoFirmware = 1;
    bool suporta5GHZ = false;

public:

    Roteador(
        Comunicador c,
        const string ip,
        const int versaoFirmware,
        const bool suporta5GHZ): Comunicador(c)
    {
        this->ip = ip;
        this->versaoFirmware = versaoFirmware;
        this->suporta5GHZ = suporta5GHZ;
    }

    /* Getter */
    const string getIp(){ return ip; }
    const int getVersaoFirmware(){ return versaoFirmware; }
    const bool getSuporta5GHZ(){ return suporta5GHZ; }

    /* Setters */
    void setIp(const string ip){ this->ip = ip; }
    void setVersaoFirmware(const int versao){ this->versaoFirmware = versao; }
    void setSuporta5GHZ(const bool suporta){ this->versaoFirmware = suporta; }

    virtual int getHash(int max)
    {
        float x = Comunicador::getHash(max) * (getVersaoFirmware()) + 2;
        return (int) x % max;
    }

    void print() override
    {
        Comunicador::print();
        cout << "+--------------------------------------------------" << endl;
        cout << "|  O comunicador em questao e um roteador          " << endl;
        cout << "| - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "|  - IP: " << getIp() << endl;
        cout << "|  - Suporta 5GHZ? " << ((getSuporta5GHZ()) ? "Sim" : "Não") << endl;
        cout << "|  - Versao firmware: " << getVersaoFirmware() << endl;
        cout << "+--------------------------------------------------" << endl;
    }


};