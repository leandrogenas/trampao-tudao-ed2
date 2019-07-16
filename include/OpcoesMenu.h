#pragma once

#define OPC_VOLTAR       0x00
#define OPC_CAD_NOVO     0x01
#define OPC_CAD_LISTAR   0x02
#define OPC_CAD_EXCLUIR  0x04
#define OPC_HASH         0x10
#define OPC_ARVORE_AVL   0x20
#define OPC_ARVORE_BUSCA 0x40
#define OPC_HEAP         0x80

#include <iostream>

using namespace std;

class OpcoesMenu
{
private:
    int opcaoSel;

    int nivelCadastro();
public:
    OpcoesMenu(): opcaoSel(OPC_VOLTAR) { }

    void limparTela();
    int nivel1();
};

