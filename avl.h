#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <queue>
#include "tools.h"

using namespace std;

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
class AVLTree {
private:
    TreeNode<T>* root;
    int depth(TreeNode<T> *tree);

    void preOrderPrint(TreeNode<T> *tree) const;
    void inOrderPrint(TreeNode<T> *tree) const;
    void postOrderPrint(TreeNode<T> *tree) const;
    void levelOrderPrint(TreeNode<T> *tree) const;


    TreeNode<T>* search(TreeNode<T> *x, T target) const;
    TreeNode<T>* iterativeSearch(TreeNode<T> *x, T target) const;

    TreeNode<T>* minimum(TreeNode<T> *tree);
    TreeNode<T>* maximum(TreeNode<T> *tree);

    TreeNode<T>* insert(TreeNode<T>* &tree, T data);
    // TreeNode<T>* remove(TreeNode<T>* &tree, TreeNode<T> *deleted);

    void destroy(TreeNode<T>* &tree);

    TreeNode<T>* leftLeftRotation(TreeNode<T> *ro);
    TreeNode<T>* rightRightRotation(TreeNode<T> *ro);
    TreeNode<T>* leftRightRotation(TreeNode<T> *ro);
    TreeNode<T>* rightLeftRotation(TreeNode<T> *ro);

public:
    AVLTree();
    ~AVLTree();

    int depth();
    // direction 0:pre 1:in 2:post 3:level;
    void print(int direction);
    void print();

    T minimum();
    T maximum();

    TreeNode<T>* search(T data);
    TreeNode<T>* iterativeSearch(T data);
    void insert(T data);
    void remove(T data);
    void destroy();
};


template<class T>
AVLTree<T>::AVLTree(): root(nullptr) { }
 
template<class T>
AVLTree<T>::~AVLTree() { destroy(root); }

template<class T>
int AVLTree<T>::depth(TreeNode<T> *tree){
    return (tree) ? tree->depth : 0;
}

template<class T>
int AVLTree<T>::depth(){
    return depth(root);
}

template<class T>
void AVLTree<T>::preOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        cout << tree->val << ' ';
        preOrderPrint(tree->left);
        preOrderPrint(tree->right);
    }
}

template<class T>
void AVLTree<T>::inOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        inOrderPrint(tree->left);
        cout << tree->val << ' ';
        inOrderPrint(tree->right);
    }
}

template<class T>
void AVLTree<T>::postOrderPrint(TreeNode<T> *tree) const{
    if (tree != nullptr) {
        postOrderPrint(tree->left);
        postOrderPrint(tree->right);
        cout << tree->val << ' ';
    }
}

template<class T>
void AVLTree<T>::levelOrderPrint(TreeNode<T> *tree) const{
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
void AVLTree<T>::print(int direction){
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
void AVLTree<T>::print() { 
    inOrderPrint(root);
    cout << endl;
}

template<class T>
TreeNode<T>* AVLTree<T>::minimum(TreeNode<T> *tree){
    if (root == nullptr) 
        return nullptr;
    while(tree->left != nullptr)
        tree = tree->left;
    return tree;
}

template<class T>
TreeNode<T>* AVLTree<T>::maximum(TreeNode<T> *tree){
    if (root == nullptr) 
        return nullptr;
    while(tree->right != nullptr)
        tree = tree->right;
    return tree;
}

template<class T>
T AVLTree<T>::minimum(){
    TreeNode<T>* temp = minimum(root);
    if (temp == nullptr) return (T)nullptr;
    return temp->val;
}


template<class T>
T AVLTree<T>::maximum(){
    TreeNode<T>* temp = maximum(root);
    if (temp == nullptr) return (T)nullptr;
    return temp->val;
}

template <class T>
TreeNode<T>* AVLTree<T>::search(TreeNode<T> *x, T target) const {
    if (x == nullptr || x->val == target) 
        return x;
    if (x->val > target)
        return search(x->left, target);
    else
        return search(x->right, target);
}

template<class T>
TreeNode<T>* AVLTree<T>::search(T data){
    return search(root, data);
}

template <class T>
TreeNode<T>* AVLTree<T>::iterativeSearch(TreeNode<T> *x, T target) const {
    while(x != nullptr && x->val != target){
        if (x->val > target)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

template<class T>
TreeNode<T>* AVLTree<T>::iterativeSearch(T data){
    return iterativeSearch(root, data);
}

template<class T>
TreeNode<T>* AVLTree<T>::insert(TreeNode<T>* &tree, T data){
    if(tree == nullptr)
    {
        tree = new TreeNode<T> (data);
        if(tree == nullptr)
        {
            cout<<"ERROR: create AVLTree root failed!"<<endl;
            return  nullptr;
        }
    }
    else if(data < tree->val) {
        tree->left = insert(tree->left, data);
        if(depth(tree->left) - depth(tree->right) == 2)
        {
            if(data < tree->left->val)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        } 
    }
    else
    {
        tree->right = insert(tree->right, data);
        if(depth(tree->right) - depth(tree->left) == 2)
        {
            if(data > tree->right->val)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        } 
    }
    
    tree->depth = max(depth(tree->left), depth(tree->right)) + 1;
    
    return tree;
}

template <class T>
void AVLTree<T>::insert(T data){ insert(root, data); }


// template<class T>
// TreeNode<T>* AVLTree<T>::remove(TreeNode<T>* &tree, TreeNode<T> *deleted){
// }

// template<class T>
// void AVLTree<T>::remove(T data){
//     TreeNode<T>* romoved = search(root, data);
//     if (romoved && romoved->val == data){ 
//         remove(root, romoved);
// }

template<class T>
void AVLTree<T>::destroy(TreeNode<T>* &tree){
    if (tree != nullptr){
        destroy(tree->left);
        destroy(tree->right); 
        delete tree;
    }
}

template<class T>
void AVLTree<T>::destroy(){
    destroy(root);
}


template<class T>
TreeNode<T>* AVLTree<T>::leftLeftRotation(TreeNode<T> *ro){
    TreeNode<T>* temp;

    temp = ro->left;
    ro->left = temp->right;
    temp->right = ro;

    ro->depth = max(depth(ro->left), depth(ro->right)) + 1;
    temp->depth = max(ro->depth, depth(temp->left)) + 1;
    return temp;
}

template<class T>
TreeNode<T>* AVLTree<T>::rightRightRotation(TreeNode<T> *ro){
    TreeNode<T>* temp;

    temp = ro->right;
    ro->right = temp->left;
    temp->left = ro;

    ro->depth = max(depth(ro->left), depth(ro->right)) + 1;
    temp->depth = max(ro->depth, depth(temp->right)) + 1;
    return temp;
}

template<class T>
TreeNode<T>* AVLTree<T>::leftRightRotation(TreeNode<T> *ro){
    ro->left = rightRightRotation(ro->left);
    return leftLeftRotation(ro);
}

template<class T>
TreeNode<T>* AVLTree<T>::rightLeftRotation(TreeNode<T> *ro){
    ro->right = leftLeftRotation(ro->right);
    return rightRightRotation(ro);
}


#endif
