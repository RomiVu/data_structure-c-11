#include "tree.h"
#include <vector>


using namespace std;


void insertLeft(TreeNode* root, int left){
     TreeNode* p = new TreeNode(left);
     root->left = p;
}

void insertRight(TreeNode* root, int right){
     TreeNode* p = new TreeNode(right);
     root->right = p;
}


TreeNode* genANBTree() {
	TreeNode* root = new TreeNode(1);

	insertLeft(root, 2);
	insertRight(root, 3);

	insertLeft(root->left, 4);
	insertRight(root->left, 5);

	insertLeft(root->right, 6);
	insertRight(root->right, 7);

	return root;
}


void generateBSTs(int start, int end, vector<TreeNode*> &temp){
	if (start >= end) return;


	vector<TreeNode*> leftsub;
    vector<TreeNode*> rightsub;
    for (int i=start; i<=end; ++i){
        rightsub.clear();
        leftsub.clear();	
        
        generateBSTs(start, i-1, leftsub);
        generateBSTs(i+1, end, rightsub);

        if (leftsub.size() == 0 && rightsub.size() == 0){
        	TreeNode* root = new TreeNode(i);
        	temp.push_back(root);
        } else if (leftsub.size() == 0) {
	        for (auto rg : rightsub) {
        		TreeNode* root = new TreeNode(i);
        		root->right = rg;
        		temp.push_back(root);
	        }
        } else if (rightsub.size() == 0) {
        	for (auto lf : leftsub) {
        		TreeNode* root = new TreeNode(i);
        		root->left = lf;
        		temp.push_back(root);
        	}
        } else {
	        for (auto lf : leftsub) {
	        	for (auto rg : rightsub) {
	        		TreeNode* root = new TreeNode(i);
	        		root->left = lf;
	        		root->right = rg;
	        		temp.push_back(root);
	        	}
	        }
   		}
    }
    return;
} 


vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> rslt;
	vector<TreeNode*> leftsub;
    vector<TreeNode*> rightsub;

    for (int i=1; i<=n; ++i) {    	
        rightsub.clear();
        leftsub.clear();
        generateBSTs(1, i-1, leftsub);
        generateBSTs(i+1, n, rightsub);


        if (leftsub.size() == 0 && rightsub.size() == 0){
        	TreeNode* root = new TreeNode(i);
        	rslt.push_back(root);
        } else if (leftsub.size() == 0) {
	        for (auto rg : rightsub) {
        		TreeNode* root = new TreeNode(i);
        		root->right = rg;
        		rslt.push_back(root);
	        }
        } else if (rightsub.size() == 0) {
        	for (auto lf : leftsub) {
        		TreeNode* root = new TreeNode(i);
        		root->left = lf;
        		rslt.push_back(root);
        	}
        } else {
	        for (auto lf : leftsub) {
	        	for (auto rg : rightsub) {
	        		TreeNode* root = new TreeNode(i);
	        		root->left = lf;
	        		root->right = rg;
	        		rslt.push_back(root);
	        	}
	        }
   		}
    }

    return rslt;
}

TreeNode* genBSTviaLevel(const std::vector<int>& v){
	if (v.size() == 0) return nullptr;

	vector<TreeNode*> temp;
	for(int i=0; i<v.size(); i++){
		// todo : -1 is marked as nullptr; how to replace it with some other sign
		TreeNode* p = (v[i] == -1) ? nullptr : new TreeNode(v[i]);
		temp.push_back(p);
	}

	for (int i=0; i< temp.size(); i++){
		if (temp[i]) {
			temp[i]->left = (2*i+1 < temp.size()) ? temp[2*i+1] : temp[i]->left;
			temp[i]->right = (2*i+2 < temp.size()) ? temp[2*i+2] : temp[i]->right;
		}
	}

	return temp[0];
}

