#ifndef GRAPH_H
#define GRAPH_H
#include<vector>

using namespace std;

enum AdjecentEdge {
    ADJECENT,
    NO_ADJECENT
};

//Definition for a graph
struct GraphByMatrix {
	int vertexNums, edgeNums; // 顶点数 边数
	vector<int> vertex; // 简单应用的话，可以省略
    vector<vector<AdjecentEdge>> edges;

	GraphByMatrix():	vertexNums(0), edgeNums(0),
						edges(vector<vector<AdjecentEdge>>(100, vector<AdjecentEdge>(100, NO_ADJECENT))),
						vertex(vector<int>(100, 0)) {}

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
	vector<VertexNode*> vertex;
	GraphByLinkedList(): vertexNums(0), edgeNums(0), vertex(vector<VertexNode*>(100,nullptr)) {}

};


#endif