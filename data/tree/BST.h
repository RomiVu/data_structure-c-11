#ifndef BST_H
#define BST_H

#include "Node.h"
#include <string>
#include <iostream>

template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);

 public:
  BST<T>();
  ~BST<T>();

  bool isEmpty();
  bool contains(T v);
  Node<T>* findElem(T v);
  void insert(T v);
  void remove(T v);

  void preOrderPrint(std::ostream &out);
  void inOrderPrint(std::ostream &out);
  void postOrderPrint(std::ostream &out);
  void levelOrderPrint(std::ostream &out);
};


#endif
