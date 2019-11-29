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

// generate a tree for test
TreeNode* genBSTviaLevel(const std::vector<int>& v);


// Chooses k unique random elements from a population sequence from its index [start, end].
std::vector<int> randomSample(int start, int end, int k);



int min(int a, int b);
int max(int a, int b);
// int abs(int a);

#endif