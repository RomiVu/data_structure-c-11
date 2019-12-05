#ifndef BST_H
#define BST_H


template<class T>
class BSTree {
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
    TreeNode<T>* remove(TreeNode<T>* &tree, TreeNode<T> *rm);

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


#endif