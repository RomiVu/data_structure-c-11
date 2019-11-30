#include "linkedlist.h"
#include "tools.h"
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
	std::vector<int> v {9, 6, 8, 2, 6};

	ListNode *root1, *root2;
	root1 = newListHeadInsert(v);
	root2 = newListTailInsert(v);


	printList(root1);
	inserAt(&root1, 1, 1);
	printList(root1);
	deleteAt(&root1, 1);
	printList(root1);


	CloseWindow();
	return 0;
}