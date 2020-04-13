#include "binarytree.h"
#include "tools.h"
#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <queue>

using namespace std;


template<class T>
class AVLTree : public BTree<T>
{
private:
//     TreeNode<T>* root;
//     int depth(TreeNode<T> *tree);

//     TreeNode<T>* search(TreeNode<T> *x, T target) const;
//     TreeNode<T>* iterativeSearch(TreeNode<T> *x, T target) const;

//     TreeNode<T>* minimum(TreeNode<T> *tree);
//     TreeNode<T>* maximum(TreeNode<T> *tree);

    TreeNode<T>* insert(TreeNode<T>* &tree, T data);
//     TreeNode<T>* remove(TreeNode<T>* &tree, TreeNode<T> *rm);

//     TreeNode<T>* leftLeftRotation(TreeNode<T> *ro);
//     TreeNode<T>* rightRightRotation(TreeNode<T> *ro);
//     TreeNode<T>* leftRightRotation(TreeNode<T> *ro);
//     TreeNode<T>* rightLeftRotation(TreeNode<T> *ro);

public:
//     int depth();

//     T minimum();
//     T maximum();

//     TreeNode<T>* search(T data);
//     TreeNode<T>* iterativeSearch(T data);
    void insert(T data);
//     void remove(T data);
};
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
        // if(depth(tree->left) - depth(tree->right) == 2)
        // {
        //     if(data < tree->left->val)
        //         tree = leftLeftRotation(tree);
        //     else
        //         tree = leftRightRotation(tree);
        // } 
    }
    else
    {
        tree->right = insert(tree->right, data);
        // if(depth(tree->right) - depth(tree->left) == 2)
        // {
        //     if(data > tree->right->val)
        //         tree = rightRightRotation(tree);
        //     else
        //         tree = rightLeftRotation(tree);
        // } 
    }
    
    tree->depth = max(depth(tree->left), depth(tree->right)) + 1;
    
    return tree;
}

template <class T>
void AVLTree<T>::insert(T data){ insert(root, data); }


/* 
template<class T>
int AVLTree<T>::depth(TreeNode<T> *tree){
    return (tree) ? tree->depth : 0;
}

template<class T>
int AVLTree<T>::depth(){
    return depth(root);
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
TreeNode<T>* AVLTree<T>::remove(TreeNode<T>* &tree, TreeNode<T> *rm){
    if (tree == nullptr || rm == nullptr ) return nullptr;
    if (tree->val > rm->val) 
    {
        tree->left = remove(tree->left, rm);
        if(depth(tree->right) - depth(tree->left) == 2)
        {
            if(depth(tree->right->left) < depth(tree->right->right)) 
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }

    }
    else if (tree->val < rm->val)
    {
        tree->right = remove(tree->right, rm);
        if(depth(tree->left) - depth(tree->right) == 2)
        {
            if(depth(tree->left->left) < depth(tree->left->right)) 
                tree = leftRightRotation(tree);
            else
                tree = leftLeftRotation(tree);
        } 
    }
    else
    {
        if (rm->left != nullptr && rm->right != nullptr)
        {
            if(depth(tree->left)>depth(tree->right))
            {
                TreeNode<T> *max = maximum(tree->left);
                tree->val = max->val;
                tree->left = remove(tree->left, max);
            }
            else
            {
                TreeNode<T> *min = minimum(tree->right);
                tree->val = min->val;
                tree->right = remove(tree->right, min); 
            }
        }
        else
        {
            TreeNode<T> *tmp = tree;
            tree = (tree->left!=nullptr) ? tree->left : tree->right;
            delete tmp;
        }

    }
    
    return tree;

}

template<class T>
void AVLTree<T>::remove(T data){
    TreeNode<T>* rm = search(root, data);
    if (rm != nullptr && rm->val == data){ 
        cout << "has found the node want to be deleted.\n";
        remove(root, rm);
    }
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
*/

#endif
