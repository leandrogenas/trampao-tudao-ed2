#pragma once


#include <iostream>
#include <string>
#include <src/comunicadores/Comunicador.h>
#include "account.h"


class HashTable {
 private:
  int       MAX_ITEMS;
  int       length;
  /*
    A nossa estrutura interna é um array para ponteiros de Account.
   */
  Comunicador** cadastro;
  
  
 public:
  // Constructor
  HashTable(int size = 20)
  {
      MAX_ITEMS = size;
      cadastro  = new Comunicador*[size];

      /*
         É sempre interessante garantir que os valores serão inicializados com NULL.
       */
      for (int i = 0; i < size; i++) {
          cadastro[i] = nullptr;
      }
      length    = 0;
  }

  /*
    Retorna o numero de elementos preenchidos.
   */
  int getLength() const { return length; };

  /* 
     Recebe um ponteiro para um elemento do tipo Account. Esse elemento
   Account que recebemos por parametro tem uma chave. Usamos essa chave
   para buscar um elemento em nosso banco e retornar esse elemento na
   mesma regiao de memoria, caso ele exista.

     Se o elemento nao estiver no nosso banco, entao não precisa
   alterar o parametro account, basta avisar na variavel found que o
   elemento não foi achado.
  */
  void retrieveItem(Comunicador& c, bool& found)
  {
      int hash = c.getFingerprint(MAX_ITEMS);

      found = false;
      if(cadastro[hash] != nullptr){
          c = *cadastro[hash];
          found = true;
      }
  };

  
  /*
    Insere o elemento na lista na posicao indicada pelo metodo getHash.
  */
  void insertItem(Comunicador c)
  {
      int hash = c.getFingerprint(MAX_ITEMS);
      cout << "hash " << hash << endl;
      if(cadastro[hash] == nullptr){
          cadastro[hash] = new Comunicador(c);
          length++;
      }else{
          std::cout << "Colisão" << std::endl;
      }
  };

  /*
    Remove uma ocorrência de account na lista.
  */
  void deleteItem(Comunicador c)
  {
      int hash = c.getFingerprint(MAX_ITEMS);

      delete cadastro[hash];
      cadastro[hash] = nullptr;
      length--;
  };

  /*
    Imprime todos os elementos que estão na lista, inclusive as
    posições vazias.
   */
  void print() const
  {
      std::cout << "+----------------- inicio do print ----------------" << std::endl;
      for (int i = 0; i < MAX_ITEMS; i++) {
          Comunicador* acc = cadastro[i];
          if (acc != nullptr) {
              acc->print();
          }
      }
      std::cout << "===================================================" << std::endl;
      std::cout << "+----------------- fim do print -------------------" << std::endl;
  };

  
};
