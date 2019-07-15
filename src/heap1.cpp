#include "heap.h" 
#include <cstddef>
#include <new>


Heap::Heap(int MAX_ITEMS) {
  this->MAX_ITEMS = MAX_ITEMS;
  cadastro  = new Account*[MAX_ITEMS];
  for (int i = 0; i < MAX_ITEMS; i++) {
    cadastro[i] = NULL;
  }
  length    = 0;
}

Heap::Heap(int MAX_ITEMS, Account* input, int size)
{

}


Heap::~Heap()
{
  for (int i = 0; i < length; i++) {
    delete cadastro[i];
  }
  delete [ ] cadastro;
}


Account Heap::dequeue()
{
  return NULL;
}


void Heap::enqueue(Account newItem)
{

}

bool Heap::isFull() const
{
  return length == MAX_ITEMS;
}

bool Heap::isEmpty() const
{
  return length == 0;
}

void Heap::descida(int index, int bottom)
{

}

void Heap::subida(int index, int root)
{

}

void Heap::print() const {
  std::cout << "INI" << std::endl;
  for (int i = 0; i < length; i++) {
    Account* acc = cadastro[i];    
    if (acc != NULL) { 
	std::cout << i << ":" << acc->getAccountNumber() <<", "  <<acc->getBalance() << std::endl;
      }
  }
  std::cout << "FIM" << std::endl;
}
