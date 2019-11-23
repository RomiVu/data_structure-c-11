#include "chapter2.h"
#include <vector>
#include <stack>

using namespace std;

vector<int> inorderTraversal(TreeNode* root){
	vector<int> rslt;
	stack<TreeNode*> p;
	TreeNode* temp;

	p.push(root);
    while(!p.empty()){
    	temp = p.top();
		rslt.push_back(temp->val);
		p.pop();
		if (temp->right) p.push(temp->right);
	    if (temp->left) p.push(temp->left);
    }
    
    return rslt;
}