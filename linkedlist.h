#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int data) : val(data), next(nullptr) {}
};

struct DoubleLinkedNode {
	int val;
	DoubleLinkedNode *next, *prior;
	DoubleLinkedNode(int data) : val(data), next(nullptr) {}
};


ListNode* newListTailInsert(std::vector<int>& input);
ListNode* newListHeadInsert(std::vector<int>& input);

ListNode* getNodeByIndex(ListNode* root, int index);
ListNode* getNodeByValue(ListNode* root, int val);

void inserAt(ListNode **root, int index, int val);
void deleteAt(ListNode **root, int index);

int getLength(ListNode* root);

void printList(ListNode* root);



int getLength(DoubleLinkedNode* root);

void printList(DoubleLinkedNode* root);


#endif
