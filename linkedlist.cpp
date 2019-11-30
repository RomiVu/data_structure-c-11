#include "linkedlist.h"
#include <vector>
#include <iostream>


using namespace std;


int getLength(DoubleLinkedNode* root){
	DoubleLinkedNode* temp = root;
	int length=0;
	
	while(temp){
		length++;
		temp = temp->next;
	}
	return length;
}

void printList(DoubleLinkedNode* root){
    DoubleLinkedNode* temp = root;
    cout << "DoubleLinkedList: ";
    while(temp){
    	cout << root->val << ' '; 
    	temp = temp->next;
    }
    cout << '\n';
}

void printList(ListNode* root){
    ListNode* temp= root;
    cout << "linkedlist: ";
    while(temp){
    	cout << temp->val << ' '; 
    	temp = temp->next;
    }
    cout << '\n';
}


int getLength(ListNode* root){
	ListNode* temp = root;
	int length=0;
	
	while(temp){
		length++;
		temp = temp->next;
	}

	return length;
}

ListNode* newListHeadInsert(std::vector<int>& input){
	ListNode root(0);
	ListNode* ptr = &root;

	for(int i=input.size()-1; i >= 0 ; --i){
		ptr = new ListNode(input[i]);
		ptr->next = root.next;
		root.next = ptr;
	}
	return root.next;
}


ListNode* newListTailInsert(std::vector<int>& input){
	ListNode root(0);
	ListNode* ptr = &root;

	for(auto i : input){
		ptr->next = new ListNode(i);
		ptr = ptr->next;
	}

	return root.next;
}


ListNode* getNodeByIndex(ListNode* root, int index){
	ListNode* temp = root;
	int start=1;

	while(start++ < index && temp != nullptr){
		temp = temp->next;
	}
	return temp;

}

ListNode* getNodeByValue(ListNode* root, int val){
	ListNode* temp = root;
	
	while(temp !=nullptr && temp->val != val){
		temp = temp->next;
	}
	return temp;
}


void inserAt(ListNode **root, int index, int val){
	if (index <= 0 || index > getLength(*root)) throw 0;
    ListNode *temp, *ptr;
	if (index == 1) {
		temp = new ListNode(val);
		temp->next=*root;
		*root = temp;
	}else{
		temp = getNodeByIndex(*root, index-1);
		ptr = new ListNode(val);
		ptr->next = temp->next;
		temp->next = ptr;
	}
}

void deleteAt(ListNode **root, int index){
	if (index <= 0 || index > getLength(*root)) throw 0;
	ListNode *temp, *del;
	if (index == 1){
		del = *root;
		*root = (*root)->next;
		delete del;
	}else{
		temp = getNodeByIndex(*root, index-1);
		del = temp->next;
		temp->next = del->next;
		delete del;
	}

}