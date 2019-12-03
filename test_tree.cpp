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
    vector<int> v;
    set<int> seen;
    TreeNode *ptr;

    for (int i=0; i<5; i++){
        int n = getRandomNumber(1, 30);
        while(seen.find(n) != seen.end()){
            n = getRandomNumber(1, 30);
        }
        v.push_back(n);
        seen.insert(n);
    }
    TreeNode* root = generateBST(v);

    inOrderPrint(root);
    cout << '\n';

    transformBSTtoBalanced(root);

    preOrderPrint(root);
    cout << '\n';

    ptr = rotateLeft(root);

    if (ptr) {
        cout << "FIRST UN-BALANCED NODE IS " << ptr->val << endl;
        if (ptr->ld > ptr->rd){

        } else {
            TreeNode *temp = ptr->right;
        }
    }


   cout << "Is A balanced tree: " << isBalanced(root) << endl;

    cout << "Is A Binary Search Tree: " << isValidBST1(root) << endl;


	CloseWindow();
	return 0;
}
