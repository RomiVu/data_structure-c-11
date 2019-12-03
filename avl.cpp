#include "avl.h"

void BSTree::toBalanced(){

}

bool BSTree::isBalanced(){

}

int main(){
    BSTree t;

    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
    t.levelPrint();
    t.search(200);
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();

    return 0;
}
