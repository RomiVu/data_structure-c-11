#include "BST.h"
#include "tool.h"
#include <iostream>
#include <vector>


int main() {
  BST<int>* bst = new BST<int>();
  // if(bst->isEmpty())
  // 	std::cout << "empty as tree is just created now.\n";
  std::vector<int> data {6,4,10,2,5,7,12};
  for (auto i=data.begin();i != data.end(); ++i)
  	bst->insert(*i);
  // bst->insert(5);
  // bst->insert(1);
  // bst->insert(3);
  // bst->insert(2);
  // bst->insert(7);
  // bst->insert(12);

  // if(bst->contains(20))

  bst->preOrderPrint(std::cout);
  bst->inOrderPrint(std::cout);
  bst->postOrderPrint(std::cout);
  bst->levelOrderPrint(std::cout);
  CloseWindow();
}
