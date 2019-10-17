#include "linklist.h"
#include <iostream>


void headInsert(Node *head, Node *data)
{
	data->next = head->next;
	head->next = data;
}

void tailInsert(Node *head, Node *data)
{
	if (isEmpty(head)) 
	{
		head->next = data; 
		return;
	}
	Node *temp;
	temp = head->next;
	while(temp->next != nullptr) temp = temp->next;
	temp->next = data;
}

Node *findbyIndex(const Node &head, int index)
{	
	Node *rslt = head.next;
	for(int i=1;i<index;++i) rslt = rslt->next;
	return rslt;
}


Node *findbyValue(const Node &head, int value)
{
	Node *rslt = head.next;
	while(rslt != nullptr && rslt->m_data != value) rslt=rslt->next;
	return rslt;
}

void insertbyIndex(const Node &head,  Node *data, int index)
{	
	Node *nthNode = findbyIndex(head, index);
	if(nthNode == nullptr) return; // index may not exist.

	data->next = nthNode->next;
	nthNode->next = data;
	int temp = nthNode->m_data;
	nthNode->m_data = data->m_data;
	data->m_data = temp;
}

int getLength(const Node &head)
{
	Node *p = head.next;
	int length=0;
	while(p!=nullptr) 
	{
		p=p->next;
		length++;
	}
	return length;
}

void deletebyIndex(const Node &head, int index)
{
	Node *nthNode = findbyIndex(head, index);
	if (nthNode == nullptr) return;
	Node *temp = nthNode->next;
	if (temp == nullptr) 
		nthNode = nullptr;
	else
	{
		nthNode->m_data = temp->m_data;
		nthNode->next = temp->next;
		delete temp;
	}

}

void pirntList(const Node &head)
{
	Node *p = head.next;
	while (p != nullptr)
	{
		std::cout << p->m_data << ' ';
		p = p->next;
	}
	std::cout << '\n';
}

bool isEmpty(const Node &head)
{
	return (head.next != nullptr) ? true : false;
}

bool isEmpty(Node *head)
{
	return (head->next == nullptr) ? true : false;
}