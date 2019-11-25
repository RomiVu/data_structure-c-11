#include "tools.h"
#include "chapter1.h"
#include "chapter2.h"
#include <cstdio>
#include <vector>
#include <iostream>


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

    vector<TreeNode*> v;
    v = generateTrees(3);
        vector<int> v1;
            vector<int> v2;
    for (auto node : v){

        v1 = preOrderTraversal(node);
        v2 = inOrderTraversal(node);

        printVector(v1);
        printVector(v2);
        printf("\n++++++++++ \n");
    }


	CloseWindow();
	return 0;
}