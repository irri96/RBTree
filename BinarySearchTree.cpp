#include <bits/stdc++.h>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
	_root = NULL;
	_size = 0;
}

void BinarySearchTree::destruir(node *nodo){
	if(nodo->left!=NULL){
		destruir(nodo->left);
	}
	if(nodo->right!=NULL){
		destruir(nodo->right);
	}
	free(nodo);
}

BinarySearchTree::~BinarySearchTree(){
	destruir(_root);
}

node* BinarySearchTree::crearNodo(int item){
	_size++;
    node* temp = (node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

node* BinarySearchTree::insertarNodo(node* node, int key){
	if (node == NULL) return crearNodo(key);
	//cout<<"   "<<node->key<<endl;
    if (key < node->key){
    	if(node->left == NULL)
        	node->left  = insertarNodo(node->left, key);
    	else insertarNodo(node->left,key);
    }
    else if (key > node->key){
    	if(node->right==NULL)
        node->right = insertarNodo(node->right, key);
    	else insertarNodo(node->right, key);

    }
}


void BinarySearchTree::insert(int val){	
	if(_size == 0){
		_size++;
		_root = (node*)malloc(sizeof(node));
		_root->left = _root->right = NULL;
		_root->key = val;
	}
	else insertarNodo(_root,val);
}


bool BinarySearchTree::buscarNodo(node* node, int key){
	if (node == NULL || key == node->key){
        return node!=NULL;
    }
    else if (key < node->key){
        //printf("Nodo buscado es menor\n");
        return buscarNodo(node->left, key);
    }
    else if (key > node->key){
        //printf("Nodo buscado es mayor\n");
        return buscarNodo(node->right, key);
    }
}

bool BinarySearchTree::search(int val){
	if(_size == 0) return false;
	return buscarNodo(_root,val);
}

int BinarySearchTree::getSize(){
	return _size;
}

node* BinarySearchTree::getRoot(){
	return _root;
}

void BinarySearchTree::inorder(node* node){
	if (node != NULL){
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

void BinarySearchTree::preorder(node* node){
	if (node != NULL){
		printf("%d ", node->key);
        inorder(node->left);
        inorder(node->right);
    }
}


