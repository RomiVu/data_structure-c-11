#include "chapter2.h"
#include <vector>
#include <queue>
#include <stack>

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
	TreeNode* temp;

	p.push(root);
    while(!p.empty()){
    	temp = p.top();
    	p.pop();
    	if (temp->right==nullptr && temp->left==nullptr){
    		rslt.push_back(temp->val);
    	} else if (!p.empty() && temp->right == p.top()){
    		rslt.push_back(temp->val);
    	} else { 
			if (temp->right) p.push(temp->right);
			p.push(temp);
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


bool isValidBST(TreeNode* root) {
	if (!root) return true;

	if(root->left && (root->left->val > root->val)) return false;
	if (root->right && (root->right->val < root->val)) return false;

    return (isValidBST(root->left) && isValidBST(root->right));
}
