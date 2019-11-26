#include "tools.h"
#include "chapter1.h"
#include "chapter2.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>


void printVector(vector<int> &v){
    for (auto i : v){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
// chapter 1
	// vector<int> v;
	// for (int i=0;i<10;i++){
	// 	v.push_back(getRandomNumber(0, 100));
	// }

 //    for (auto i : v){
 //    	printf("%d ", i);
 //    }

 //    printf("\n---------- \n");

 //    printf("findKthLarge: %f\n", getMedianOfArrayUnsorted(v, 0, v.size()-1)); 

 //    for (auto i : v){
 //    	printf("%d ", i);
 //    }

 //    printf("\n++++++++++ \n");

// chapter2
    // TreeNode* root = genANBTree();

    // vector<int> v1;
    // v1 = preOrderTraversal(root);

    // for (auto i : v1){
    // 	printf("%d ", i);
    // }

    // printf("\n++++++++++ \n");


// high level tree application 

    TreeNode* root;
    std::vector<int> v {5,2,7,1,3,6,8,-1,-1,-1,4};
    // std::vector<int> v {1, -1, 2, -1, -1, 3};

    root = genBSTviaLevel(v);

    std::vector<int> v1;
    std::vector<int> v2;

    // v1 = preOrderTraversal(root);
// 
    v2 = inOrderTraversal(root);

    // printVector(v1);
    printVector(v2);
    // printf("\n++++++++++ \n");

    if (isValidBST1(root)){
        printf("this is a vaild binary search tree.\n");
    } else {
        printf("this is NOT a vaild binary search tree.\n");
    }

    printf("this largest number %d; smallest number is %d\n", findLargestBT(root, root->val), findSmallestBT(root, root->val));


	CloseWindow();
	return 0;
}