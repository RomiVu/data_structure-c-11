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

	    // to understand
		int maxCoins(vector<int>& nums);

		// All nodes of complete binary tree 
		int countNodes(TreeNode* root);

		// todo
		bool find132pattern(vector<int>& nums);

		//
		vector<int> addToArrayForm(vector<int>& A, int K);

		int eraseOverlapIntervals(vector<vector<int>>& intervals);
};



vector<int> getIndexSorted(vector<int>& v, int s, int e);

#endif
