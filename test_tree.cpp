/*
#include <cstdlib>

int main()
{
    system("chcp 65001");

    CloseWindow();
    return 0; 
}
*/
#include "avl.h"
#include "tools.h"
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    AVLTree<int> test;

    vector<int> v = randomSample(1, 30, 10);

    for (auto i : v){
        cout << "inserting.. " << i << ' ' << '\n';
        test.insert(i);
    }

    test.print(1);
    test.print(3);
    CloseWindow();
    return 0;
}
