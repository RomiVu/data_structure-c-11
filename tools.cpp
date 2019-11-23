#include "tools.h"
#include <iostream>
#include <ctime> // for std::time ()
#include <random> // for mersenne twister

// using namespace std;

void CloseWindow()
{
	std::cout << "Tap twice 'Enter' to exit the window..." << std::endl;
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
}
 
namespace MyRandom
{
	// Initialize our mersenne twister with a random seed based on the clock (once at system startup)
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}
 
int getRandomNumber(int min, int max)
{
	std::uniform_int_distribution die { min, max }; // we can create a distribution in any function that needs it
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
	TreeNode* root = new TreeNode(getRandomNumber(0, 100));

	insertLeft(root, getRandomNumber(0, 100));
	insertRight(root, getRandomNumber(0, 100));

	insertLeft(root->left, getRandomNumber(0, 100));
	insertRight(root->left, getRandomNumber(0, 100));

	insertLeft(root->right, getRandomNumber(0, 100));
	insertRight(root->right, getRandomNumber(0, 100));

	insertLeft(root->left->left, getRandomNumber(0, 100));
	insertRight(root->left->right, getRandomNumber(0, 100));

	insertLeft(root->right->left, getRandomNumber(0, 100));
	insertRight(root->right->right, getRandomNumber(0, 100));

	return root;
}