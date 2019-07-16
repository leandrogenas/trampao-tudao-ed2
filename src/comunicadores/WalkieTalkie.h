#include <iostream>
#include <src/comunicadores/Comunicador.h>

using namespace std;

class WalkieTalkie: public Comunicador
{
private:
    int qtdCanais = 1;

public:

    WalkieTalkie(
        Comunicador c,
        const int qtdCanais): Comunicador(c)
    {
        this->qtdCanais = qtdCanais;
    }

    const int getQtdCanais() const { return this->qtdCanais; }

    void setQtdCanais(const int qtd){ this->qtdCanais = qtd; }

    void print() override
    {
        Comunicador::print();
        cout << "+--------------------------------------------------" << endl;
        cout << "|  O comunicador em questao e um Walkie Talkie     " << endl;
        cout << "| - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "|  - Canais: " << getQtdCanais() << endl;
        cout << "+--------------------------------------------------" << endl;
    }

};
