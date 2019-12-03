#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <queue>

using namespace std;

class BSTree {
private:
    struct node {
        int val;
        node* left;
        node* right;
        node(int a) : val(a), left(nullptr), right(nullptr) {}
    };

    node* ROOT;

    node* makeEmpty(node* root) {
        if(root == nullptr)
            return nullptr;
        else {
            makeEmpty(root->left);
            makeEmpty(root->right);
            cout << "makeEmpty... val : " << root->val << endl;
            delete root;
        }
        return nullptr;
    }

    node* insert(node* root, int x){
        if (root == nullptr)
            root = new node(x);
        else if(x < root->val)
            root->left = insert(root->left, x);
        else if(x > root->val)
            root->right = insert(root->right, x);
        return root;
    }

    node* findMin(node* root){
        if(root == nullptr)
            return nullptr;
        else if(root->left == nullptr)
            return root;
        else
            return findMin(root->left);
    }

    node* findMax(node* root) {
        if(root == nullptr)
            return nullptr;
        else if (root->right == nullptr)
            return root;
        else
            return findMax(root->right);
    }

    node* remove(node* root, int x) {
        node* temp;
        if(root == nullptr)
            return nullptr;
        else if(x < root->val)
            root->left = remove(root->left, x);
        else if(x > root->val)
            root->right = remove(root->right, x);
        else if(root->left && root->right) {
            temp = findMin(root->right);
            root->val = temp->val;
            root->right = remove(root->right, root->val);
        } else {
            temp = root;
            if(root->left == nullptr)
                root = root->right;
            else if(root->right == nullptr)
                root = root->left;
            cout << "remove... val : " << temp->val << endl;
            delete temp;
        }

        return root;
    }

    node* find(node* root, int x) {
        if(root == nullptr)
            return nullptr;
        else if(x < root->val)
            return find(root->left, x);
        else if(x > root->val)
            return find(root->right, x);
        else
            return root;
    }

    void inlevel(node* root) {
        if (root == nullptr) return;
        queue<node *> q;
        node *temp;
        q.push(root);

        while(!q.empty()){
            temp = q.front();
            q.pop();

            cout << temp->val << ' ';
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    void inorder(node* root) {
        if(root == nullptr)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void preorder(node* root) {
        if(root == nullptr)
            return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

public:
    BSTree() { ROOT = nullptr; }

    ~BSTree() { ROOT = makeEmpty(ROOT); }

    void insert(int x) { ROOT = insert(ROOT, x); }

    void remove(int x) { ROOT = remove(ROOT, x); }

    void display() {
        inorder(ROOT);
        cout << " ### inorder print" << endl;
    }

    void levelPrint(){
        inlevel(ROOT);
        cout << " ### level print" << endl;
    }

    void search(int x) {
        node* temp = find(ROOT, x);
        if (temp)
            cout << "search rslt: " << temp->val << '\n';
        else
           cout << "search rslt: NOT contain " << '\n';
    }

    void toBalanced();

    bool isBalanced();

};


#endif
