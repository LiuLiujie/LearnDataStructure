#include <iostream>
#include "Graph.h"

int main()
{
	Graph test;
	//test.CreateUDN();//创建无向图
	//test.DFS();//图的遍历,深度优先搜索
	//test.MiniSpanTree('A');//普里姆算法创建最小生成树
	//test.MiniSpanTree();//克鲁斯卡尔算法创建最小生成树

	test.CreateDN();//创建有向图
	test.ShortestPath('B');//迪杰特斯拉算法计算最短路径,已测试
	return 0;
}
