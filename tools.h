#ifndef TOOLS_H
#define TOOLS_H
#include <vector>

void CloseWindow();

int getRandomNumber(int min, int max);


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

#endif