#include "BinarySearchTreeADT.h"

struct AVLnode{
    int key;
    struct AVLnode *left, *right;
    int height;
};

class AVLTree: public BinarySearchTreeADT{
 	private:
  		void destruir(AVLnode*);
  		AVLnode* insertarNodo(int, AVLnode*);
  		bool buscarNodo(AVLnode*, int);
  		AVLnode* _root;
  		int _size;
  		int getBalance(AVLnode*);
  		int max(int,int);
  		int height(AVLnode*);
  		AVLnode* singleRightRotate(AVLnode*);
		AVLnode* singleLeftRotate(AVLnode*);
		AVLnode* doubleLeftRotate(AVLnode*);
		AVLnode* doubleRightRotate(AVLnode*);

 	public:
  		AVLTree();
  		~AVLTree();
  		void insert(int);
  		bool search(int);
  		int getSize();
  		void inorder(AVLnode*);
  		void preorder(AVLnode*);
  		AVLnode* getRoot();

};






