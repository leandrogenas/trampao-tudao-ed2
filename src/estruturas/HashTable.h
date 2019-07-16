#pragma once


#include <iostream>
#include <string>
#include <src/comunicadores/Comunicador.h>
#include <vector>

class HashTable {
 private:
  int       MAX_ITEMS;
  int       length;

  Comunicador** cadastro;

  Comunicador* lapide = new Comunicador("-1", "-1");
  
  
 public:
  // Constructor
  HashTable(int size)
  {
      MAX_ITEMS = size;
      length    = 0;

      cadastro  = new Comunicador*[size];
      for (int i = 0; i < size; i++)
          cadastro[i] = nullptr;
  }

  /*
    Retorna o numero de elementos preenchidos.
   */
  int getLength() const
    { return length; };

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


  void insertItem(Comunicador c)
  {
      int hash = c.getFingerprint(MAX_ITEMS);

      if(cadastro[hash] == nullptr){
          cadastro[hash] = new Comunicador(c);
          length++;
      }else tratarColisao(c);

  };

  void tratarColisao(Comunicador c)
  {
     int hash = c.getFingerprint(MAX_ITEMS);

     // Método da lápide
     Comunicador *aux;
     do{
        aux = cadastro[hash++];

        if(aux == nullptr)
            cadastro[hash] = &c;
     }while(aux == nullptr);
  }

  /*
    Remove uma ocorrência de account na lista.
  */
  void deleteItem(Comunicador c)
  {
      int hash = c.getFingerprint(MAX_ITEMS);
      int i = hash;
      Comunicador *aux;
      while((aux = cadastro[i++]) != lapide);

      if(aux == nullptr)
        return;

      hash = aux->getFingerprint(MAX_ITEMS);
      delete cadastro[hash];
      cadastro[hash] = nullptr;
      length--;

      reorganizarArvore(hash);
  };

  void reorganizarArvore(int j = 0)
  {
      for(int i=j; i<length; i++)
          if(cadastro[i] == lapide)
              cadastro[i + 1] = cadastro[i];
  }

  /*
    Imprime todos os elementos que estão na lista, inclusive as
    posições vazias.
   */
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

  static HashTable nova(const vector<Comunicador *> &comms, int max = 20)
  {
      HashTable hash(max);
      for(int i=0; i < comms.size() - 1; i++)
          hash.insertItem(*comms[i]);

      return hash;
  }
  
};
