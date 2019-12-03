#include "chapter2.h"
#include "tree.h"
#include "tools.h"
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> preOrderTraversal(TreeNode* root){
	vector<int> rslt;
	stack<TreeNode*> p;
	TreeNode* temp;

	p.push(root);
    while(!p.empty()){
    	temp = p.top();
		p.pop();

		rslt.push_back(temp->val);
		if (temp->right) p.push(temp->right);
	    if (temp->left) p.push(temp->left);
    }
    
    return rslt;
}


vector<int> postOrderTraversal(TreeNode* root){
	vector<int> rslt;
	stack<TreeNode*> p;
	TreeNode* temp;

	p.push(root);
    while(!p.empty()){
    	temp = p.top();
    	p.pop();
    	rslt.insert(rslt.begin(), temp->val);
    	if (temp->left) p.push(temp->left);
	    if (temp->right) p.push(temp->right);
    }

	return rslt;
}



vector<int> inOrderTraversal(TreeNode* root){
	vector<int> rslt;
	stack<TreeNode*> p;
	set<TreeNode*> seen;
	TreeNode* temp;

	p.push(root);
    while(!p.empty()){
    	temp = p.top();

    	p.pop();
    	if (temp->right==nullptr && temp->left==nullptr){
    		rslt.push_back(temp->val);
    	} else if (seen.find(temp) != seen.end()) {
    		rslt.push_back(temp->val);
    	} else { 
			if (temp->right) p.push(temp->right);
			p.push(temp);
			seen.insert(temp);
			if (temp->left) p.push(temp->left);
		}
    }

	return rslt;
}


vector<int> levelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    vector<int> rslt;
    TreeNode* temp;

    q.push(root);

    while(!q.empty()){
    	temp = q.front();
    	if(temp != nullptr){
    		rslt.push_back(temp->val);
    		q.push(temp->left);
    		q.push(temp->right);
    	}
    	q.pop();
    }

    return rslt;
}

void inHelper(TreeNode* node, vector<int> &rslt){
	if (node->left) inHelper(node->left, rslt);
	rslt.push_back(node->val);
	if (node->right) inHelper(node->right, rslt);
}

vector<int> inOrderTraversalR(TreeNode* root){
	vector<int> rslt;

	inHelper(root, rslt);

	return rslt;
}


void preHelper(TreeNode* node, vector<int> &rslt){
	rslt.push_back(node->val);
	if (node->left) preHelper(node->left, rslt);
	if (node->right) preHelper(node->right, rslt);
}


vector<int> preOrderTraversalR(TreeNode* root){
	vector<int> rslt;

	preHelper(root, rslt);

	return rslt;
}


void postHelper(TreeNode* node, vector<int> &rslt){
	if (node->left) postHelper(node->left, rslt);
	if (node->right) postHelper(node->right, rslt);
	rslt.push_back(node->val);
}

vector<int> postOrderTraversalR(TreeNode* root){
	vector<int> rslt;
	
	postHelper(root, rslt);
	return rslt;
}

// int max(TreeNode* a, TreeNode* b, int origin){
// 	if (a == nullptr && b == nullptr) return origin;
// 	if (a == nullptr) return (b->val > origin) ? b->val : origin;
// 	if (b == nullptr) return (a->val > origin) ? a->val : origin;
// 	int temp;
// 	temp = (a->val > b->val) ? a->val : b->val;
// 	return (temp > origin) ? temp : origin;
// }

// int min(TreeNode* a, TreeNode* b, int origin){
// 	if (a == nullptr && b == nullptr) return origin;
// 	if (a == nullptr) return (b->val < origin) ? b->val : origin;
// 	if (b == nullptr) return (a->val < origin) ? a->val : origin;
// 	int temp;
// 	temp = (a->val < b->val) ? a->val : b->val;
// 	return (temp < origin) ? temp : origin;
// }



// int findMaxOfBinTree(TreeNode* root, int current){
// 	if (!root) return current;
// 	int temp = max(root->left, root->right, root->val);
	
// 	int a = findMaxOfBinTree(root->left, temp);
// 	int b = findMaxOfBinTree(root->right, temp);

// 	return (a > b) ? a : b;
// }

// int findMinOfBinTree(TreeNode* root, int current){
// 	if (!root) return current;
// 	int temp = min(root->left, root->right, root->val);
	
// 	int a = findMinOfBinTree(root->left, temp);
// 	int b = findMinOfBinTree(root->right, temp);

// 	return (a < b) ? a : b;
// }

bool isValidBST(TreeNode* root) {
	if (!root) return true;

	if(root->left){
		if (root->left->val >= root->val) return false;
	    if (findLargestBT(root->left, root->left->val) >= root->val) return false;
	}

	if(root->right){
		if (root->right->val <= root->val) return false;
	    if (findSmallestBT(root->right, root->right->val) <= root->val) return false;
	}

    return (isValidBST(root->left) && isValidBST(root->right));
}


bool isValidBST1Helper(TreeNode* node, int* lower, int* upper){
    if (!node) return true;

    int val = node->val;
    if (upper != nullptr && val >= *upper) return false;
    if (lower != nullptr && val <= *lower) return false;

    return isValidBST1Helper(node->left, lower, &val) &&  isValidBST1Helper(node->right, &val, upper);
}


bool isValidBST1(TreeNode* root){
   return isValidBST1Helper(root, nullptr, nullptr);
}


int findLargestBT(TreeNode* root, int current){
    if (!root) return current;
    int max = (root->val > current) ? root->val : current;
    int a = findLargestBT(root->right, max);
    int b = findLargestBT(root->left, max);
    return (a > b) ? a : b;
}


int findSmallestBT(TreeNode* root, int current){
    if (!root) return current;
    int max = (root->val < current) ? root->val : current;
    int a = findSmallestBT(root->right, max);
    int b = findSmallestBT(root->left, max);
    return (a < b) ? a : b;
}


int getPrimeNum(int a, int b){
	return (a > b) ? ((a % b == 0) ? b : getPrimeNum(b, a % b)) : getPrimeNum(b , a); 
}


int maxDepth(TreeNode* root) {
	if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1+maxDepth(root->right);
    if (!root->right) return 1+maxDepth(root->left);
    return max(1+maxDepth(root->left), 1 + maxDepth(root->right));
}


bool isBalanced(TreeNode* root) {
	 if (!root) return true;
	 if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
	 return isBalanced(root->left) && isBalanced(root->right);
    
}


bool isBalancedBST(TreeNode* root){
   // to be continued...
   return false;
}
