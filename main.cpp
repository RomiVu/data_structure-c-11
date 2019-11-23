#include "tools.h"
#include "chapter1.h"
#include "chapter2.h"
#include <cstdio>
#include <vector>

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
    TreeNode* root = genANBTree();
    vector<int> v;

    v = inorderTraversal(root);

    for (auto i : v){
    	printf("%d ", i);
    }

	CloseWindow();
	return 0;
}