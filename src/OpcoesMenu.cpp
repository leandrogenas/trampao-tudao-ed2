#include "include/OpcoesMenu.h"
#include <limits>

void OpcoesMenu::limparTela()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
}

int OpcoesMenu::nivelCadastro()
{
    int escolha = 0;
    do {
        cout << "================= trampao-tudao ED II =================" << endl;
        cout << "= Cadastro de comunicadores                           =" << endl;
        cout << "= - - - - - - - - - - - - - - - - - - - - - - - - - - =" << endl;
        cout << "= Selecione uma das opcoes abaixo (-1 para voltar):   =" << endl;
        cout << "=  1. Novo comunicador                                =" << endl;
        cout << "=  2. Excluir comunicador                             =" << endl;
        cout << "=  3. Listar comunicadores                            =" << endl;
        cout << "================= trampao-tudao ED II =================" << endl;
        cout << " * Selecione a opcao desejada: ";
        cin >> escolha;

        limparTela();

        switch(escolha){
            case 1: return OPC_CAD_NOVO;
            case 2: return OPC_CAD_EXCLUIR;
            case 3: return OPC_CAD_LISTAR;
            case -1: return OPC_VOLTAR;
            default:
                cout << " !!Opcao invalida!! Tente novamente" << endl;
                limparTela();
                system("pause");
                break;
        }
    }while(escolha != 0);

    return OPC_VOLTAR;
}

int OpcoesMenu::nivel1()
{
    int escolha = 0;
    do {
        cout << "================= trampao-tudao ED II =================" << endl;
        cout << "= Visualizacao de comunicadores em diferentes         =" << endl;
        cout << "=  estruturas de dados.                               =" << endl;
        cout << "= * * * * * * * * * * * * * * * * * * * * * * * * * * =" << endl;
        cout << "=  1. Cadastro de comunicadores                       =" << endl;
        cout << "=  2. Teste hash table                                =" << endl;
        cout << "=  3. Teste arvore de busca                           =" << endl;
        cout << "=  4. Teste arvore avl                                =" << endl;
        cout << "=  5. Teste heap                                      =" << endl;
        cout << "=======================================================" << endl;
        cout << " * Selecione a opcao desejada: ";
        cin >> escolha;

        int opcCad;
        switch(escolha){
            case 1:
                if((opcCad = nivelCadastro()) == OPC_VOLTAR)
                    continue;

                return opcCad;
            case 2: return OPC_HASH;
            case 3: return OPC_ARVORE_BUSCA;
            case 4: return OPC_ARVORE_AVL;
            case 5: return OPC_HEAP;
            case -1: return OPC_VOLTAR;
            default:
                cout << " !!Opcao invalida!! Tente novamente" << endl;
                limparTela();
                system("pause");
                break;
        }

    }while(escolha != 0);

    return OPC_VOLTAR;
}