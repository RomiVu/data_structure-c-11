#include "tools.h"
#include "chapter1.h"
#include "chapter2.h"
#include "leetcode.h"
#include "tree.h"
#include "graph.h"
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
    // vector<int> v;
    int rslt = 0;
    // nums.insert(nums.begin(), 1);
    // nums.push_back(1);

    // for (auto i : seq){
    //     rslt += nums[i] * nums[i+1] * nums[i+2];
    //     nums.erase(nums.begin()+i+1);
    // }

    return rslt;
}


int maxCoins(vector<int>& nums) {
    int N = nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    const int len = nums.size();
    std::vector<std::vector<int>> d(len,std::vector<int>(len,0));
    for(int c = 1;c <= N;++c){
        for(int i = 1;i+c-1 <= N;++i){
            const int j = i+c-1;
            int& ans=d[i][j];
            for(int k=i;k<=j;++k){
                ans=max(ans, nums[i-1]*nums[k]*nums[j+1] + d[i][k-1] + d[k+1][j]);
            }
        }
    }
    return d[1][N];
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
    // Solution solu;

    // std::vector<int> v {3,1,4,2};

	CloseWindow();
	return 0;
}

