#ifndef HASH_H
#define HASH_H


#include <iostream>
#include <string>
#include "account.h"


class Hash {
 private:
  int       MAX_ITEMS;
  int       length;
  /*
    A nossa estrutura interna é um array para ponteiros de Account.
   */
  Account** cadastro;
  
  
 public:
  // Constructor
  Hash(int size = 20); 

  /*
    Retorna o numero de elementos preenchidos.
   */
  int getLength() const;

  /* 
     Recebe um ponteiro para um elemento do tipo Account. Esse elemento
   Account que recebemos por parametro tem uma chave. Usamos essa chave
   para buscar um elemento em nosso banco e retornar esse elemento na
   mesma regiao de memoria, caso ele exista.

     Se o elemento nao estiver no nosso banco, entao não precisa
   alterar o parametro account, basta avisar na variavel found que o
   elemento não foi achado.
  */
  void retrieveItem(Account& account, bool& found);

  
  /*
    Insere o elemento na lista na posicao indicada pelo metodo getHash.
  */
  void insertItem(Account account);

  /*
    Remove uma ocorrência de account na lista.
  */
  void deleteItem(Account account);  

  /*
    Imprime todos os elementos que estão na lista, inclusive as
    posições vazias.
   */
  void print() const;

  
};

#endif
