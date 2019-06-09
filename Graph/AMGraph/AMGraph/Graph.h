#pragma once

#include <iostream>
#include "AMGraph.h"

class Graph
{
private:
	AMGraph *AMG;
	void CreateUDN(AMGraph* G);//无向网
	void CreateDN(AMGraph* G);//有向网
	int LocateVex(AMGraph* G, VerTexType u);//返回AM图G中顶点u的位置

#pragma region 图的遍历
	//深度优先
	void DFS_AM(AMGraph* G, int v);//从第v个开始遍历AM图
	bool visited[MVNum];
#pragma endregion

#pragma region 最小生成树
	#pragma region 普里姆算法
	struct Closedge//记录最小边
	{
		VerTexType adjvex;//最小边的对应的新顶点
		Arctype lowcost;//这天最小边的权值
	};
	Closedge closedge[MVNum];
	int Min(Closedge* closedge);
	void MiniSpanTree_Prim(AMGraph* G, VerTexType u);//从顶点u出发,普里姆算法构造AM图的最小生成树
	#pragma endregion

	#pragma region 克鲁斯卡尔算法
	struct Edge {
		VerTexType Head;
		VerTexType Tail;
		Arctype lowcast;
	};
	Edge *edge;
	int Vexset[MVNum];//辅助数组
	void MiniSpanTree_Kruskal(AMGraph* G);
	void Sort(Edge* edge);
	#pragma endregion
#pragma endregion

#pragma region 最短路径
	#pragma region 迪杰特斯拉
	bool S[MVNum];//记录从原点v0到vi是否已经确定最短路径
	int Path[MVNum];//记录从原点v0到终点v1的当前最短路径vi的直接前驱序号,无为-1
	int D[MVNum];//记录从v0到vi的最短路径长度,否为maxInt
	void ShortestPath(AMGraph* G, int v0);
	#pragma endregion

#pragma endregion
public:
	Graph();
	~Graph();
	void CreateUDN();//创建无向网
	void CreateDN();//创建有向网
	//图的遍历
	void DFS(int v = 0);//从第v个顶点开始遍历联通图,默认0

	//最小生成树
	void MiniSpanTree(VerTexType u);//从顶点u出发构造最小生成树,普里姆算法
	void MiniSpanTree();//克鲁斯卡尔算法

	//最短路径
	void ShortestPath(VerTexType v0);
};

