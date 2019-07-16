#pragma once

#include <iostream>
#include <string>
#include <src/comunicadores/Comunicador.h>
#include <vector>
#include "account.h"

/*
  Esta classe cria uma fila de prioridade, que é uma estrutura
  logicamente vista como uma árvore, mas que internamente
  implementamos como um array. Os elementos armazenados nesta fila de
  prioridade são objetos da classe account.
 */
class Heap
{ 
 public:

  /*
    Este é um destrutor, você deverá usá-lo para apagar todos os
    elementos da Heap antes de apagar a própria Heap.
   */
  ~Heap()
  {
      for (int i = 0; i < length; i++) {
          delete cadastro[i];
      }
      delete [ ] cadastro;
  };

  /*
    Alguns métodos auxiliares. Os nomes dos métodos são
    auto-explicativos.
   */
  bool isEmpty() const { return length > 0; };
  bool isFull()  const { return length == MAX_ITEMS; };
    void print() const
    {
        cout << "===================================================" << endl;
        cout << "+----------------- inicio do print ----------------" << endl;
        for (int i = 0; i < MAX_ITEMS; i++) {
            Comunicador* c = cadastro[i];
            if (c != nullptr) c->print();
        }
        cout << "+----------------- fim do print -------------------" << endl;
        cout << "===================================================" << endl;
    };

  /*
    Alguns métodos para empilhar e desempilhar elementos da heap.
   */
  void enqueue(Comunicador c)
  {
      if(isFull())
          return;

      cadastro[length++] = &c;
      descida(length, 0);
  };


  Comunicador dequeue()
  {
      return *removerItem(cadastro[length--]);
  };

    static Heap nova(const vector<Comunicador *> &comms, int max = 20)
    {
        Heap heap(max);
        for(int i=0; i < comms.size() - 1; i++)
            heap.enqueue(*comms[i]);

        return heap;

    }

  
 private:
  /* Número máximo de elementos que podem ser alocados na nossa
     Heap.  */
  int MAX_ITEMS;
  /* Armazena o quanto do nosso array interno está realmente
   preenchido.  */
  int length;
  /* Array onde os elementos que estão na Heap serão colocados. */
  Comunicador** cadastro;

    /*
      Este primeiro construtor recebe o numero máximo de elementos que a
      heap poderá receber e inicializa uma heap vazia.
    */
    Heap(const int max = 20)
    {
        MAX_ITEMS = max;
        cadastro  = new Comunicador*[MAX_ITEMS];
        length = 0;

        for (int i = 0; i < MAX_ITEMS; i++)
            cadastro[i] = nullptr;

    };


    Comunicador* removerItem(Comunicador *c)
    {
        int f = c->getFingerprint(MAX_ITEMS);
        cadastro[f] = cadastro[length];
        descida(f, 0);

        return c;
    }



  /*
    Operações de subida e descida vistas em sala de aula. O parâmetro
    index é o índice do elemento que será movido. Em descida, este
    elemento não pode passar do índice de bottom e em subida este
    elemento não pode passar do índice de root.
   */
  void descida(int index, int bottom)
  {
    Comunicador *cTrocar = cadastro[index];

    int e = 2 * index+1;
    Comunicador *cEsq = cadastro[e];

    while(e < length){
        if((e < length - 1) && cadastro[e] < cadastro[e+1])
            e++;
        if((cEsq->getFingerprint(MAX_ITEMS) < cadastro[e]->getFingerprint(MAX_ITEMS)))
        {
            cadastro[index] = cadastro[e];
            index = e;
            e = 2 * index+1;
        }else break;
    }
    cadastro[e] = cEsq;
  };

  void subida(int root,   int index)
  {
    int p = (index - 1) / 2;
    Comunicador *cPai = cadastro[p];

    while((index > 0) && (cadastro[p]->getFingerprint(MAX_ITEMS) < cPai->getFingerprint(MAX_ITEMS))){
        cadastro[index] = cadastro[p];
        index = p;
        p = (p - 1) / 2;
    }
    cadastro[index] = cPai;

  };


};

