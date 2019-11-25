#ifndef CHAPTER2_H
#define CHAPTER2_H
#include <vector>
#include "tools.h"

using namespace std;

// recursive way 
vector<int> inOrderTraversalR(TreeNode* root);
vector<int> preOrderTraversalR(TreeNode* root);
vector<int> postOrderTraversalR(TreeNode* root);

// using stack or queue
vector<int> inOrderTraversal(TreeNode* root);
vector<int> preOrderTraversal(TreeNode* root);
vector<int> postOrderTraversal(TreeNode* root);
vector<int> levelOrderTraversal(TreeNode* root);

// binary search tree
bool isValidBST(TreeNode* root);

#endif