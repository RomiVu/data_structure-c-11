#ifndef CHAPTER2_H
#define CHAPTER2_H
#include "tools.h"
#include "tree.h"

#include <vector>


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
bool isValidBST1(TreeNode* root);


// find largest element in a binary tree
int findLargestBT(TreeNode* root, int current);
int findSmallestBT(TreeNode* root, int current);

// balanced tree
int maxDepth(TreeNode* root);
bool isBalanced(TreeNode* root);

#endif