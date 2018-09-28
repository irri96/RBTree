#include <bits/stdc++.h>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree(){
	_root = NULL;
	_size = 0;
}

void AVLTree::destruir(AVLnode *nodo){
	if(nodo->left!=NULL){
		destruir(nodo->left);
	}
	if(nodo->right!=NULL){
		destruir(nodo->right);
	}
	delete (nodo);
}

AVLTree::~AVLTree(){
	if(_root!=NULL) destruir(_root);
}

int AVLTree::height(AVLnode *N) { 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 

int AVLTree::max(int a, int b){ 
    return (a > b)? a : b; 
} 

int AVLTree::getBalance(AVLnode *N){ 
	if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
AVLnode* AVLTree::singleRightRotate(AVLnode* t){
    AVLnode* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right))+1;        
    u->height = max(height(u->left), t->height)+1;
    return u;
}

AVLnode* AVLTree::singleLeftRotate(AVLnode* t){
    AVLnode* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right))+1;
    u->height = max(height(t->right), t->height)+1 ;
    //imprimirWeas(u);
    return u;
}

AVLnode* AVLTree::doubleLeftRotate(AVLnode* t){
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

AVLnode* AVLTree::doubleRightRotate(AVLnode* t){
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}


/*void AVLTree::imprimirWeas(AVLnode* t){
    if(t == NULL){
        return;
    }
    printf("Nodo actual: key = %d\t",t->key);
    if(t->left == NULL){
        printf("Left = NULL\t");
    }
    else{
        printf("Left = %d\t",t->left->key);
    }
    if(t->right == NULL){
        printf("Right = NULL\t");
    }
    else{
        printf("Right = %d\t",t->right->key);
    }
}*/

AVLnode* AVLTree::insertarNodo(int x, AVLnode* t){

    //imprimirWeas(t);

    if(t == NULL){
        t = new AVLnode;
        t->key = x;
        t->height = 0;            
        t->left = t->right = NULL;
        
    }

    else if(x < t->key){
           
        t->left = insertarNodo(x, t->left);
        if(height(t->left) - height(t->right) == 2){
            if(x < t->left->key){
                
                t = singleRightRotate(t);
            }
            else{
                
                t = doubleRightRotate(t);
            }
        }
    }
    else if(x > t->key){
       
        t->right = insertarNodo(x, t->right);
        if(height(t->right) - height(t->left) == 2){
            if(x > t->right->key){
                
                t = singleLeftRotate(t);
            }
            else{
                
                t = doubleLeftRotate(t);
            }
        }
    }
    t->height = max(height(t->left), height(t->right))+1;
    return t;
}

void AVLTree::preorder(AVLnode *root){ 
    if(root != NULL){ 
        printf("%d ", root->key); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

void AVLTree::inorder(AVLnode *root){ 
    if(root != NULL){ 
        inorder(root->left);
        printf("%d ", root->key);  
        inorder(root->right); 
    } 
}

AVLnode* AVLTree::getRoot(){
	return _root;
}

int AVLTree::getSize(){
	return _size;
}

void AVLTree::insert(int val){
	if(_size == 0){
		_size++;
		_root = new AVLnode;
		_root->left = _root->right = NULL;
		_root->key = val;
        _root->height = 0;
	}
    else {
        _root = insertarNodo(val,_root);
    }
}

bool AVLTree::search(int val){
	if(_size == 0) return false;
	return buscarNodo(_root,val);
}

bool AVLTree::buscarNodo(AVLnode* N, int key){
	if (N == NULL || key == N->key){
        return N!=NULL;
    }
    else if (key < N->key){
        return buscarNodo(N->left, key);
    }
    else if (key > N->key){
        return buscarNodo(N->right, key);
    }
}
