#pragma once

#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int Arctype;

class AMGraph
{
	friend class Graph;
private:
	VerTexType vexs[MVNum];//顶点表
	Arctype arcs[MVNum][MVNum];//邻接矩阵
	int vexNum,arcNum;//图的当前点数和边数

public:
	AMGraph();
	~AMGraph();
};

