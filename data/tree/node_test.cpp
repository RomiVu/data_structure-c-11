#include "Node.h"
#include "tool.h"
#include <string>
#include <iostream>

using std::string;


int main() {
  Node<string>* ns = new Node<string>(string("hello world!"));
  Node<int>* ni = new Node<int>(5);
  Node<double>* nd = new Node<double>(3.1459);
  Node<char>* chr = new Node<char>('d');

  std::cout << ns->getValue()<< std::endl;
  std::cout << ni->getValue()<< std::endl;
  std::cout << nd->getValue()<< std::endl;
  std::cout << chr->getValue()<< std::endl;

  CloseWindow();
  return 0;
}
