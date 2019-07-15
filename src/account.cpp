#include <iostream>
#include <iomanip>
#include <src/include/account.h>

using namespace std;


Account::Account(int no, double b) : accountNumber(no), balance(b) {

}


void Account::print() const {
  cout << fixed << setprecision(2);
  cout << "A/C no: " << accountNumber << " Balance=R$" << balance << endl;
}


int Account::getAccountNumber() const {
  return accountNumber;
}


double Account::getBalance() const {
  return balance;
}


void Account::setBalance(double b) {
  balance = b;
}

void Account::credit(double amount) {
  if (amount > 0) {
    balance += amount;
  }
}


void Account::debit(double amount) {
  if (amount < balance) {
    balance -= amount;
  }
}

/*
  Implemente uma função de hash que apenas devolve um valor no
  intervalo 0 .. max_number.
 */
int  Account::getHash(int max_number) const{
    return accountNumber % max_number;
}


/*
  O construtor de cópia precisa apenas copiar os atributos.
 */
Account::Account(const Account &obj) {
  accountNumber = obj.getAccountNumber();
  balance = obj.getBalance();
}
