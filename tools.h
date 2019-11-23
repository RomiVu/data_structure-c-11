#ifndef TOOLS_H
#define TOOLS_H


void CloseWindow();

int getRandomNumber(int min, int max);


//Definition for a binary tree node.
struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* genANBTree();

#endif