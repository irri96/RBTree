/**
IMPLEMENTATION BASED ON CLRS PSEUDOCODES
*/

#include "RBTree.h"
#include <bits/stdc++.h>
using namespace std;

RBTree::RBTree(){
	_size=0;
	root = NULL;
}

void RBTree::destruir(RBNode *nodo){
	if(nodo->l!=NULL){
		destruir(nodo->l);
	}
	if(nodo->r!=NULL){
		destruir(nodo->r);
	}
	delete nodo;
}

RBTree::~RBTree	(){
	if(root!=NULL) destruir(root);
}

/**
returns color of node
NULL node is black
*/
inline bool RBTree::color(RBNode *n){
	return (n==NULL)?RBBLK:n->color;
}

RBNode *RBTree::insert(RBNode *r,RBNode *n){
	if(r==NULL){
		return n;
	}
	if(n->data < r->data){	
		r->l = insert(r->l,n);
		r->l->p = r;
	}else{	//allow repeated elements (multiset)
		r->r = insert(r->r,n);
		r->r->p = r;
	}	
	return r;
}

inline void RBTree::leftRotate(RBNode *x){
	RBNode *y=x->r;
	x->r = y->l;
	if(y->l!=NULL){
		y->l->p = x;
	}
	y->p = x->p;
	if(x->p==NULL){
		root = y;
	}else if(x==x->p->l){
		x->p->l = y;
	}else{
		x->p->r = y;
	}
	y->l = x;
	x->p = y;
}

inline void RBTree::rightRotate(RBNode *x){
	RBNode *y=x->l;
	x->l = y->r;
	if(y->r!=NULL){
		y->r->p = x;
	}
	y->p = x->p;
	if(x->p==NULL){
		root = y;
	}else if(x==x->p->r){
		x->p->r = y;
	}else{
		x->p->l = y;
	}
	y->r = x;
	x->p = y;
}

void RBTree::insert(int n){
	RBNode *node = new RBNode(n);
	_size++;
	root = insert(root,node);
	//standard bst insert
/*	RBNode *y = NULL;
	RBNode *x = root;
	while(x!=NULL){
		y = x;
		if(n < x->data){
			x = x->l;
		}else{
			x = x->r;
		}
	}
	node->p = y;
	if(y==NULL){
		root = node;
	}else if(n<y->data){
		y->l = node;
	}else{
		y->r = node;
	}
	int nrot = 0;
*/	//go up until node is root or parent is black
	while(node!=root && node->p->color==RBRED){	
		if(node->p == node->p->p->l){
			//uncle is on right child of grandpa
			RBNode *u = node->p->p->r;
			if(color(u)==RBRED){
				//uncle is red
				node->p->color = u->color = RBBLK;
				node->p->p->color = RBRED;
				node = node->p->p;
			}else{
				if(node == node->p->r){//LR
					node = node->p;
					leftRotate(node);
				}
				node->p->color = RBBLK;
				node->p->p->color = RBRED;
				rightRotate(node->p->p);
			} 
		}else{
			RBNode *u = node->p->p->l;
			if(color(u)==RBRED){
				node->p->color = u->color = RBBLK;
				node->p->p->color = RBRED;
				node = node->p->p;
			}else{
				if(node == node->p->l){//RL
					node = node->p;
					rightRotate(node);
				}
				node->p->color = RBBLK;
				node->p->p->color = RBRED;
				leftRotate(node->p->p);
			}
		}
	}
	root->color = RBBLK;	
}

bool RBTree::buscarNodo(RBNode* N, int key){
	//standard bst search
	if (N == NULL || key == N->data){
        return N!=NULL;
    }
    else if (key < N->data){
        return buscarNodo(N->l, key);
    }
    else if (key > N->data){
        return buscarNodo(N->r, key);
    }
}


int RBTree::getSize(){
	return _size;
}
bool RBTree::search(int val){
	if(_size == 0) return false;
	return buscarNodo(root,val);
}