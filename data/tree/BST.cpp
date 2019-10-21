#include "BST.h"
#include <iostream>
#include <queue>
#include <stack>

template <typename T>
BST<T>::BST() {
  root = nullptr;
}

template <typename T>
BST<T>::~BST() {
  
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != nullptr) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } 
    else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::inOrderPrint(std::ostream &out) {
  out << "inOrderPrint: ";
  inOrderTravesal(root, out);
  out << '\n';
}

template <typename T>
void BST<T>::preOrderPrint(std::ostream &out) {
  out << "preOrderPrint: ";
  // preOrderTravesal(root, out);
    preOrderStackTravesal(root, out);
  out << '\n';
}

template <typename T>
void BST<T>::postOrderPrint(std::ostream &out) {
  out << "postOrderPrint: ";
  postOrderTravesal(root, out);
  out << '\n';
}

template <typename T>
void BST<T>::levelOrderPrint(std::ostream &out) {
  out << "levelOrderPrint: ";
  levelOrderTravesal(root, out);
  out << '\n';
}


template <typename T>
void inOrderTravesal(Node<T>* root, std::ostream &out) {
  if(root != nullptr) {
    inOrderTravesal(root->getLeftChild(), out);
    out << root->getValue() << ' ';
    inOrderTravesal(root->getRightChild(), out);
  }
}

template <typename T>
void preOrderTravesal(Node<T>* root, std::ostream &out) {
  if(root != nullptr) {
    out << root->getValue() << ' ';
    preOrderTravesal(root->getLeftChild(), out);
    preOrderTravesal(root->getRightChild(), out);
  }
}

template <typename T>
void postOrderTravesal(Node<T>* root, std::ostream &out) {
  if(root != nullptr) {
    postOrderTravesal(root->getLeftChild(), out);
    postOrderTravesal(root->getRightChild(), out);
    out << root->getValue() << ' ';
  }
}

template <typename T>
void levelOrderTravesal(Node<T>* root, std::ostream &out) {
  std::queue<Node<T>*> assist;
  assist.push(root);
  while(!assist.empty())
  {
    if(assist.front() != nullptr) {
      out << assist.front()->getValue() << ' ';
      assist.push(assist.front()->getLeftChild());
      assist.push(assist.front()->getRightChild());
    }
    assist.pop();
  }
}

template <typename T>
void preOrderStackTravesal(Node<T>* root, std::ostream &out) {
  std::stack<Node<T>*> assist;
  Node<T>* temp;
  assist.push(root);
  while(!assist.empty()){
      out << assist.top()->getValue() << ' ';
      temp = assist.top();
      assist.pop();
      if (temp->getRightChild() != nullptr) assist.push(temp->getRightChild());
      if (temp->getLeftChild() != nullptr) assist.push(temp->getLeftChild());
  }
}



template <typename T>
bool BST<T>::isEmpty() {
  if (root == nullptr)
    return true;
  else
    return false;
}


template <typename T>
bool BST<T>::contains(T v) {
  Node<T>** curr = &root;

  while (*curr != nullptr) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } 
    else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
    else
      return true;
  }
  return false;
}


template <typename T>
Node<T>* BST<T>::findElem(T v) {
  Node<T>** curr = &root;

  while (*curr != nullptr) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } 
    else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
    else
      return *curr;
  }
  return nullptr;
}

// std::ostream& operator<< (std::ostream &out, const Node<T>* &node)
// {
//     // Since operator<< is a friend of the Point class, we can access Point's members directly.
//     out << "Tree(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")"; // actual output done here
 
//     return out; // return std::ostream so we can chain calls to operator<<
// }

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
template class BST<char>;
