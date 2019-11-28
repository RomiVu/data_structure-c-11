#ifndef LEETCODE_H
#define LEETCODE_H
#include "tools.h"
#include <vector>

using namespace std;

class Solution {
	public:
	    int minDepth(TreeNode* root);
	    int maxDepth(TreeNode* root);

	    bool isBalanced(TreeNode* root);

		// binary search tree
		int getMinimumDifference1(TreeNode* root);

	    int getMinimumDifference2(TreeNode* root);

	    int findPairs(vector<int>& nums, int k);

		int maxCoins(vector<int>& nums);
    
};

#endif