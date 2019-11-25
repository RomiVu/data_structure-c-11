#include "tools.h"
#include <iostream>
#include <ctime> // for time ()
#include <random> // for mersenne twister
#include <vector>

using namespace std;

void CloseWindow()
{
	cout << "Tap twice 'Enter' to exit the window..." << endl;
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
}
 
namespace MyRandom
{
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	mt19937 mersenne{ static_cast<mt19937::result_type>(time(nullptr)) };
}
 
int getRandomNumber(int min, int max)
{
	uniform_int_distribution die { min, max }; // we can create a distribution in any function that needs it
	return die(MyRandom::mersenne); // and then generate a random number from our global generator
}

void insertLeft(TreeNode* root, int left){
     TreeNode* p = new TreeNode(left);
     root->left = p;
}

void insertRight(TreeNode* root, int right){
     TreeNode* p = new TreeNode(right);
     root->right = p;
}


TreeNode* genANBTree() {
	// TreeNode* root = new TreeNode(getRandomNumber(0, 100));

	// insertLeft(root, getRandomNumber(0, 100));
	// insertRight(root, getRandomNumber(0, 100));

	// insertLeft(root->left, getRandomNumber(0, 100));
	// insertRight(root->left, getRandomNumber(0, 100));

	// insertLeft(root->right, getRandomNumber(0, 100));
	// insertRight(root->right, getRandomNumber(0, 100));

	// insertLeft(root->left->left, getRandomNumber(0, 100));
	// insertRight(root->left->right, getRandomNumber(0, 100));

	// insertLeft(root->right->left, getRandomNumber(0, 100));
	// insertRight(root->right->right, getRandomNumber(0, 100));

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