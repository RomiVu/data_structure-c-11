#include "tools.h"
#include "chapter1.h"
#include "chapter2.h"
#include "leetcode.h"
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>


void printVector(std::vector<int> &v){
    for (auto i : v){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

void inOrderPrint(TreeNode* root){
 //    if (root->left){
 //        inOrderTraversal(root->left);
 //        cout << root->val << ' ';
 //        if (root->right) inOrderTraversal(root->right);
 //    } else {
 //        cout << root->val << ' ';
 //        if (root->right) inOrderTraversal(root->right);
 // }
     if (root->left) inOrderPrint(root->left);
     cout << root->val << ' ';
     if (root->right) inOrderPrint(root->right);
}


int calculateSum1(std::vector<int>& nums, std::vector<int>& seq){
    int rslt = 0;
    int lower, low, upper, high;
    for (int i=0; i < seq.size(); ++i){
        low = seq[i]-1;
        high = seq[i]+1;

        if (i > 1) std::sort(seq.begin(), seq.begin()+i);

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

    // TreeNode* root;
    // std::vector<int> v {2, 1, 3};
    // std::vector<int> v {1, -1, 2, -1, -1, 3};

    // root = genBSTviaLevel(v);

    // std::vector<int> v1;
    // std::vector<int> v2;

//     v1 = inOrderTraversal(root);
// // 
//     inOrderPrint(root);

//     printVector(v1);
    // printVector(v2);
    // printf("\n++++++++++ \n");

    // if (isValidBST1(root)){
    //     printf("this is a vaild binary search tree.\n");
    // } else {
    //     printf("this is NOT a vaild binary search tree.\n");
    // }

    // printf("this largest number %d; smallest number is %d\n", findLargestBT(root, root->val), findSmallestBT(root, root->val));
    Solution solu;

    std::vector<int> nums {9,76,64,21,97,60};

    printf("%d\n",  solu.maxCoins(nums));


    std::vector<int> seq2 {3, 2, 1, 4, 0, 5};
    printf("%d\n",  calculateSum1(nums, seq2));

    // std::vector<int> seq1 {3, 1, 2, 4, 0};
    // printf("%d\n",  calculateSum1(nums, seq1));


	CloseWindow();
	return 0;
}