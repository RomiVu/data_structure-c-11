#ifndef TREE_H
#define TREE_H
#include<vector>

//Definition for a binary tree node.
struct TreeNode {
	 int val, ld, rd;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr), ld(0), rd(0) {}
};

// generate a tree for test
TreeNode* genANBTree();

// given a interger, return all binary search trees consisting of [1,2, ... , n]
std::vector<TreeNode*> generateTrees(int n);

// generate a tree for test
TreeNode* genBSTviaLevel(const std::vector<int>& v);


// generate a balanced BST from random vector
TreeNode* generateBST(const std::vector<int>& v);

// insert into a balanced BST to keep it sorted and balanced
void insertBST(TreeNode* root, int element);

void transformBSTtoBalanced(TreeNode* root);

TreeNode* findTheUnbalanced(TreeNode *root);

#endif