#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// template for binary search tree & avl & b-tree
template<class T>
struct TreeNode {
    T val;
    int depth;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T value) :
        val(value) ,left(nullptr), right(nullptr) {}
    TreeNode(T value, TreeNode *l, TreeNode *r) :
        val(value), left(l), right(r) {}
};



template<class T>
class BTree 
{
protected:
    TreeNode<T>* root;
    // int depth(TreeNode<T> *tree);

    void preOrderPrint(TreeNode<T> *tree) const;
    void inOrderPrint(TreeNode<T> *tree) const;
    void postOrderPrint(TreeNode<T> *tree) const;
    void levelOrderPrint(TreeNode<T> *tree) const;


    TreeNode<T>* search(TreeNode<T> *x, T target) const;
    void destroy(TreeNode<T>* &tree);

public:
    BTree();
    ~BTree();

    void print(int direction);
    void print();

    TreeNode<T>* search(T data);
    void destroy();
};

template<class T>
BTree<T>::BTree(): root(nullptr) { }
 
template<class T>
BTree<T>::~BTree() { destroy(root); }


template<class T>
void BTree<T>::preOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        cout << tree->val << ' ';
        preOrderPrint(tree->left);
        preOrderPrint(tree->right);
    }
}

template<class T>
void BTree<T>::inOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        inOrderPrint(tree->left);
        cout << tree->val << ' ';
        inOrderPrint(tree->right);
    }
}

template<class T>
void BTree<T>::postOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        postOrderPrint(tree->left);
        postOrderPrint(tree->right);
        cout << tree->val << ' ';
    }
}

template<class T>
void BTree<T>::levelOrderPrint(TreeNode<T> *tree) const{
    if (tree == nullptr) return;
    queue<TreeNode<T>*> q;
    TreeNode<T> *temp;
    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        cout << temp->val << ' ';
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

template<class T>
void BTree<T>::print(int direction){
    switch(direction){
        case 0:
            preOrderPrint(root);
            break;
        case 1:
            inOrderPrint(root);
            break;
        case 2:
            postOrderPrint(root);
            break;
        case 3:
            levelOrderPrint(root);
            break;
        default:
            inOrderPrint(root);
    }
    cout << endl;
}

template<class T>
void BTree<T>::print() {
	inOrderPrint(root);
    cout << endl;
}


template<class T>
void BTree<T>::destroy(TreeNode<T>* &tree){
	if (tree != nullptr){
		destroy(tree->left);
		destroy(tree->right);
		delete tree;
	}
}

template<class T>
void BTree<T>::destroy(){
	destroy(root);
}


#endif