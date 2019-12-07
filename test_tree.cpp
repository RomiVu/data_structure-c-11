#include "tools.h"
#include "chapter2.h"
#include "tree.h"

#include <vector>
#include <iostream>
#include <set>


using namespace std;



void printVector(vector<int> &v){
    for (auto i : v){
        cout << i << ' ';
    }
    cout << endl;
}

void inOrderPrint(TreeNode* root){
    if (root->left) inOrderPrint(root->left);
    cout << root->val << ' ' << root->ld << ' ' << root->rd << endl;
    if (root->right) inOrderPrint(root->right);
}

void preOrderPrint(TreeNode* root){
    cout << root->val << ' ' << root->ld << ' ' << root->rd << endl;
    if (root->left) preOrderPrint(root->left);
    if (root->right) preOrderPrint(root->right);
}


int main(int argc, char const *argv[])
{   
    // vector<int> v { 16, 10, 20,-1,-1,-1,22,-1,-1,-1,-1,-1,-1,-1,25};
    // vector<int> v { 16, 10, 20,-1, -1,18,22,-1,-1,-1,-1,-1,-1,21,25};
    vector<int> v { 16, 10, 20, 7, -1,-1,-1,5, -1,-1,-1,-1,-1,-1,-1, 3};

    // set<int> seen;
    TreeNode *ptr1, *method1, *ptr2, *method2;

    // for (int i=0; i<5; i++){
    //     int n = getRandomNumber(1, 30);
    //     while(seen.find(n) != seen.end()){
    //         n = getRandomNumber(1, 30);
    //     }
    //     v.push_back(n);
    //     seen.insert(n);
    // }
    TreeNode* root = genBSTviaLevel(v);

    inOrderPrint(root);
    cout << '\n';

    transformBSTtoBalanced(root);

    preOrderPrint(root);
    cout << '\n';

    method1 = searchBST(root, 16, ptr1);

    method2 = searchBSTRecursive(root, 20, ptr2);

    cout << "method1: " << method1->val << "  ptr1: " << ptr1->val << endl;
    cout << "method1: " << method2->val << "  ptr2: " << ptr2->val << endl;

    // ptr = findTheUnbalanced(root);

    // if (ptr) {
    //     cout << "FIRST UN-BALANCED NODE IS " << ptr->val << endl;
    //     if (ptr->ld > ptr->rd){

    //     } else {
    //         TreeNode *temp = ptr->right;

    //     }
    // }


   cout << "Is A balanced tree: " << isBalanced(root) << endl;

    cout << "Is A Binary Search Tree: " << isValidBST1(root) << endl;


	CloseWindow();
	return 0;
}
