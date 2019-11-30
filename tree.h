#ifndef TREE_H
#define TREE_H
#include<vector>

//Definition for a binary tree node.
struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// generate a tree for test
TreeNode* genANBTree();

// given a interger, return all binary search trees consisting of [1,2, ... , n]
std::vector<TreeNode*> generateTrees(int n);

// generate a tree for test
TreeNode* genBSTviaLevel(const std::vector<int>& v);



#endif