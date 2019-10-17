#ifndef LINKLIST_H
#define LINKLIST_H

// template <typename Elemtype>
struct Node
{
	int m_data;
	Node *next;
	Node() : m_data(0), next(nullptr)  {}
	Node(int data) : m_data(data), next(nullptr)  {}
};

void headInsert(Node *head, Node *data);
void tailInsert(Node *head, Node *data);
void insertbyIndex(const Node &head,  Node *data, int index);
void deletebyIndex(const Node &head, int index);

Node *findbyIndex(const Node &head, int index);

Node *findbyValue(const Node &head, int value);
int getLength(const Node &head);
void pirntList(const Node &head);
bool isEmpty(const Node &head);
bool isEmpty(Node *head);

#endif

