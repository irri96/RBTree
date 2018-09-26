#ifndef BST_H
#define BST_H


class BinarySearchTreeADT {

 public:
  virtual void insert(int) = 0;
  virtual bool search(int) = 0;
  virtual int getSize() = 0;
};

#endif
