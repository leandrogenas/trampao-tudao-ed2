#pragma once
#include <iostream>
#include <cstddef>
#include "AVLSearchTree.h"

using namespace std;

void AVLSearchTree::retrieveItem(Node* tree, ItemType& item, bool& found) const
{
		if(tree = NULL || item == 0)
			found = false;
		else if(tree->label == item)
			found = true;
		else 
			if(tree->label > item)
				retrieveItem(tree->esq, item, found);
			else
				retrieveItem(tree->dir, item, found);
}

void AVLSearchTree::insertItem(Node*& tree, ItemType item, bool& isTaller)
{
	bool found = false;
	retrieveItem(tree, item, found);
	if(tree == NULL){
		tree = new Node;
		tree->fatorB = 0;
		tree->label = item;
		tree->esq = tree->dir = NULL;
		isTaller = 1;
	}
	if(item < tree->label){
		bool ins = false;
		insertItem(tree->esq, item, ins);
		if(ins)
			tree->fatorB -= 1;
		
		if(tree->fatorB == -2)
			rotacaoDireita();
		
		isTaller = (fatorB == 0) ? 0 : 1;

	}else{
		bool ins = false;
		insertItem(tree->dir, item, ins);
		IF(ins)
			
	}
}

void AVLSearchTree::deleteItem(Node*& tree, ItemType item, bool& isShorter)
{
	
}