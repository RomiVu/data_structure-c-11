#ifndef TOOLS_H
#define TOOLS_H
#include <vector>

// extern const int MAX_VERTEX_NUM=100;

void CloseWindow();

int getRandomNumber(int min, int max);


//Definition for a binary tree node.
struct TreeNode {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


enum AdjecentEdge {
    ADJECENT,
    NO_ADJECENT
};

//Definition for a graph
struct GraphByMatrix {
	int vertexNums, edgeNums; // 顶点数 边数
	std::vector<int> vertex; // 简单应用的话，可以省略
    std::vector<std::vector<AdjecentEdge>> edges;

	GraphByMatrix():	vertexNums(0), edgeNums(0),
						edges(std::vector<std::vector<AdjecentEdge>>(100, std::vector<AdjecentEdge>(100, NO_ADJECENT))),
						vertex(std::vector<int>(100, 0)) {}

};


struct ArcNode {
	int adjvectex; // 相邻的节点 在 vertex vector中的index
	ArcNode* next; // 下一个
};


struct VertexNode {
	int val; // vertex data infomation
	ArcNode* first;
	VertexNode(int data) : val(data), first(nullptr) {}
};


struct GraphByLinkedList {
	int vertexNums, edgeNums; // 顶点数 边数
	std::vector<VertexNode*> vertex;
	GraphByLinkedList(): vertexNums(0), edgeNums(0), vertex(std::vector<VertexNode*>(100,nullptr)) {}

};


// generate a tree for test
TreeNode* genANBTree();


// given a interger, return all binary search trees consisting of [1,2, ... , n]
std::vector<TreeNode*> generateTrees(int n);

// generate a tree for test
TreeNode* genBSTviaLevel(const std::vector<int>& v);


// Chooses k unique random elements from a population sequence from its index [start, end].
std::vector<int> randomSample(int start, int end, int k);



int min(int a, int b);
int max(int a, int b);
// int abs(int a);


#endif