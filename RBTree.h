#ifndef __RBTREE_DEF
#define __RBTREE_DEF 0xbaba1234
#define RBBLK 0
#define RBRED 1
#include "BinarySearchTreeADT.h"
#include <bits/stdc++.h>

struct RBNode{
	int data;
	bool color;
	RBNode *l,*r,*p;
	RBNode(int &n){
		l=r=p=NULL;
		color = RBRED;
		data=n;
	}
};

using namespace std;
class RBTree:public BinarySearchTreeADT{
private:	
	int _size;
	
	RBNode *root;
	inline bool color(RBNode *);
	inline void leftRotate(RBNode *);
	inline void rightRotate(RBNode *);
	RBNode *insert(RBNode *r,RBNode *n);
	bool buscarNodo(RBNode*, int);
public:
	RBTree();
	void insert(int n);
	bool search(int n);
	int getSize();
};
#endif