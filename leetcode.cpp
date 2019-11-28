#include "leetcode.h"
#include "tools.h"
#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

void inOrder(TreeNode* root, int &rslt, int &last){
    if (root->left) inOrder(root->left, rslt, last);
    rslt = (abs(last - root->val) < rslt) ? abs(last - root->val) : rslt;
    last = root->val;
    if (root->right) inOrder(root->right, rslt,  last);

}


int Solution::minDepth(TreeNode* root) {
	if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1+minDepth(root->right);
    if (!root->right) return 1+minDepth(root->left);
    return min(1+minDepth(root->left), 1 + minDepth(root->right));
}

int Solution::maxDepth(TreeNode* root) {
	if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1+maxDepth(root->right);
    if (!root->right) return 1+maxDepth(root->left);
    return max(1+maxDepth(root->left), 1 + maxDepth(root->right));
}


bool Solution::isBalanced(TreeNode* root) {
	 if (!root) return true;
	 if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
	 return isBalanced(root->left) && isBalanced(root->right);
    
}

// binary search tree
int Solution::getMinimumDifference1(TreeNode* root) {
	stack<TreeNode*> stk;
	set<TreeNode*> seen;
	TreeNode* ptr;
	int rslt = INT_MAX;
	int last = INT_MAX;

	stk.push(root);
    while(!stk.empty()) {
    	ptr = stk.top();
    	stk.pop();

    	if ((ptr->right == ptr->left) || (seen.find(ptr) != seen.end())) {
			rslt = (abs(ptr->val-last)<rslt) ? abs(ptr->val - last) : rslt;
			last = ptr->val;
    	} else { 
			if (ptr->right) stk.push(ptr->right);
			stk.push(ptr);
			seen.insert(ptr);
			if (ptr->left) stk.push(ptr->left);
		}
    }

    return rslt;
}


int Solution::getMinimumDifference2(TreeNode* root) {
	int rslt=INT_MAX;
	int last=INT_MAX;
	inOrder(root, rslt, last);
	return rslt;
}

bool biFindInSorted(vector<int> &v, int target, int start, int end){
	// v is sorted acending
	//  0 <= start <= end < v.size()-1 
	while (start <= end) {
    	int mid = (end + start) / 2;
		if (v[mid] < target){
			start =mid +1;
		} else if (v[mid] > target) {
            end = mid -1;
		} else {
            return true;
		}
	}

	return false;
}

int Solution::findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int target;
    int rslt=0;
    for (int i=0; i<nums.size()-1; ++i){
    	if (i != 0 && nums[i] == nums[i-1]) continue;
    	target = nums[i] + k;
        if (biFindInSorted(nums, target, i+1, nums.size()-1)) rslt++;
    }

    return rslt;
}


int calculateSum(vector<int>& nums, vector<int>& seq){
    int rslt = 0;
    int lower, low, upper, high;
    for (int i=0; i < seq.size(); ++i){
        low = seq[i]-1;
        high = seq[i]+1;

        if (i > 1) sort(seq.begin(), seq.begin()+i);

        for (int j=i-1; j >=0; j--){
            if (low == seq[j]) low--;
        }

        for (int j=0; j <= i-1; j++){
            if (high == seq[j]) high++;
        }

        lower = (low >= 0) ? nums[low] : 1;
        upper = (high < nums.size()) ? nums[high] : 1;

        rslt += nums[seq[i]] * lower * upper; 
    }

    return rslt;
}

int Solution::maxCoins(vector<int>& nums) {
	int size = nums.size();
	if (size == 0) return 0;
	if (size == 1) return nums[0];
	vector<int> seq;
	int seq_size=size-2;

	for (int i=0; i<size; ++i){
		if (nums[i] == 0) seq.push_back(i);
	}

	for (int i=0; i<size; ++i){
		if (nums[i] == 1) seq.push_back(i);
	}

	if (nums[size-1] <= 1) seq_size++;
	if (nums[0] <= 1) seq_size++;

	cout << "seq.size is " << seq.size() << " seq_size is " << seq_size << '\n'; 
	

	set<int> seen;
	while(seq.size() < seq_size){
		int index=-1;
		for (int i=1; i<size-1; ++i){
			if (nums[i] <= 1) continue;
			if (index == -1) {
				index = i;
			} else {
				if (seen.find(i) != seen.end()) {
					index = -1;
				} else {
				 	if (nums[i] < nums[index]) index = i;
				}
			}
		}
		seq.push_back(index);
		seen.insert(index);
	}

	if (seq_size < size){
		if (nums[size-1] <= 1){
			seq.push_back(0);
		} else if (nums[0] <= 1){
			seq.push_back(size-1);
		} else {
			seq.push_back((nums[0] < nums[size-1]) ? 0 : size-1);
			seq.push_back((nums[0] > nums[size-1]) ? 0 : size-1);
		}
	}

	cout << "seq vector is \n";
	for (auto i : seq) {
		cout << i << ' ';   
	}
	cout << '\n';

    return calculateSum(nums, seq);
}

vector<int> getIndexSorted(vector<int>& v, int s, int e){
	// [5, 4, 6, 7, 8, 2]
	//     s     e
	vector<int> rslt;
	int min=s;

	while(rslt.size() != (e-s+1)) {
		for (int i=s; i<=e; ++i){
			if (v[i] < v[min]) min = i;
		}

		rslt.push_back(min);
		min = rslt.back();
	}

	return rslt;
}