#include "BinarySearchTreeADT.h"

struct node{
    int key;
    struct node *left, *right;
};

class BinarySearchTree: public BinarySearchTreeADT{
 	private:
  		void destruir(node*);
  		node* insertarNodo(node*, int);
  		bool buscarNodo(node*, int);
  		node* crearNodo(int);
  		node* _root;
  		int _size;

 	public:
  		BinarySearchTree();
  		~BinarySearchTree();
  		void insert(int);
  		bool search(int);
  		int getSize();
  		void inorder(node*);
  		void preorder(node*);
  		node* getRoot();
};
