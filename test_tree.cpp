/*
#include <cstdlib>

int main()
{
    system("chcp 65001");

    CloseWindow();
    return 0; 
}
*/
#include "binarytree.h"
#include "avl.h"
#include "tools.h"
#include <vector>
#include <iostream>

using namespace std;

enum INSTRUCTUON
{
    PRINT_PRE, // 0
    PRINT_IN,  // 1
    PRINT_POST, // 2
    PRINT_LEVEL,
    INSERT,    // 4
    DESTORY,   // 5
    FIND,  // 6
    EXIT // 7
};

int main(int argc, char const *argv[])
{
    AVLTree<int> t;

    vector<int> v = randomSample(1, 30, 5);

    for (auto i : v){
        cout << "inserting.. " << i << ' ' << '\n';
        t.insert(i);
    }


    int input, temp;
    TreeNode<int> *ptr;
    while(true){
        cin >> input;
        INSTRUCTUON ins { static_cast<INSTRUCTUON>(input) };
        switch (ins){
            case PRINT_PRE:
                t.print(0);
                break;
            case PRINT_IN:
                t.print(1);
                break;
            case PRINT_POST:
                t.print(2);
                break;
            case PRINT_LEVEL:
                t.print(3);
                break;
            case INSERT:
                cout << "Enter a interger: "; 
                cin >> temp;
                t.insert(temp);
                break;
            case DESTORY:
                t.destroy();
                break;
            case FIND:
                cin >> temp;
                ptr = t.search(temp);
                if (ptr != nullptr && ptr->val == temp){
                    cout << "searched successfully\n";
                }
                break;
            case EXIT:
                cout << "terminatinating...\n";
                t.destroy();
                CloseWindow();
                return 0;
                break;
            default:
                cin.clear();
        }
        cout << "\n - - - - - ENTER INSTRUCTUON - - - - - - "; 
        cin.clear();
    }

    t.destroy();
    CloseWindow();
    return 0;
}
