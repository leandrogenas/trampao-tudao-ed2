#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
 private:
  double balance;
  int accountNumber;
  
 public:
  Account(int accountNumber = 0.0, double balance = 0.0);
  int getAccountNumber() const;
  double getBalance() const;
  void setBalance(double balance);
  void credit(double amount);
  void debit(double amount);
  void print() const;

  /*
    Abaixo eu adicionei dois novos métodos.

    1 - "const Account &obj": esse é um "copy constructor", que é um
    construtor que cria um objeto inicializando com outro da mesma
    classe que foi criado anteriormente. Usamos o copy constructor
    para (i) inicializar um objeto a partir de outro, (ii) Copiar um
    objeto para passá-lo como argumento a uma função, (iii) Copiar um
    objeto para retornar de uma função e (iv) Copiar um objeto para
    retornar de um container.

    Se você não definir um copy constructor, o compilador do C++
    criará um para você por default que fará uma cópia de todos os
    membros. Esse copy constructor funcionará muito bem para a grande
    maioria dos casos, exceto quando existem ponteiros. Nesses casos,
    você deverá criar um copy constructor explicitamente e alocar
    recusos de forma dinâmica.

    Neste exemplo, não precisamos do construtor de cópia explícito,
    mas ele foi colocado para você ir logo se acostumando.
  */




  Account(const Account &obj);
  /*
    2 - "int getHash(int max_number) const;": este é o método que
    indicará a posição de um dado elemento na hash.
   */


  int  getHash(int max_number) const;
};

#endif

