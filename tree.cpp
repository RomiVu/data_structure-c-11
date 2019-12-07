#include "tree.h"
#include "tools.h"
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



// generate a balanced BST from random vector
TreeNode* generateBST(const vector<int>& v){
    if (v.size() == 0) return nullptr;

    TreeNode* root = new TreeNode(v[0]);

    for (int i=1; i<v.size(); i++){
        insertBST(root, v[i]);
    }
    return root;
}


// insert into a balanced BST to keep it sorted and balanced
void insertBST(TreeNode* root, int element){
    if (!root) return;

    TreeNode* ptr = root;
    while(true) {
        if (element < ptr->val){
            // ptr->ld++;
            if (ptr->left){
                ptr = ptr->left;
            }else {
                ptr->left = new TreeNode(element);
                return;
            }
        } else if (element > ptr->val){
            // ptr->rd++;
            if (ptr->right){
                ptr = ptr->right;
            }else {
                ptr->right = new TreeNode(element);
                return;
            }
        }else {
            throw 0; // can't be equal
            return;
        }
    }
}


// 1 means insert successful, otherwise failure
int insertBSTbook(TreeNode &root, int elem){
    if (!root){
        root = new TreeNode(element);
        return 1;
    } else if (elem < root->val){
        insertBSTbook(root->left, elem);
    } else if (elem > root->val) {
        insertBSTbook(root->right, elem);
    } else {
        return 0;
    }
}



void transformBSTtoBalanced(TreeNode* root){
    if (!root) return;
    if (root->left) transformBSTtoBalanced(root->left);
    if (root->right) transformBSTtoBalanced(root->right);
    root->ld = (root->left) ? max(root->left->ld, root->left->rd) + 1 : 0;
    root->rd = (root->right) ? max(root->right->ld, root->right->rd) + 1 : 0;
}


TreeNode* findTheUnbalanced(TreeNode *root){
    if (!root) return nullptr;
    if (root->left && _abs(root->left->ld - root->left->rd) > 1) return root;
    findTheUnbalanced(root->left);
    if (root->right && _abs(root->right->ld - root->right->rd) > 1) return root;
    findTheUnbalanced(root->right);
    if (_abs(root->ld - root->rd) > 1) return root;
    return nullptr;
}

// TreeNode* rotateRight(TreeNode *root){

// }
