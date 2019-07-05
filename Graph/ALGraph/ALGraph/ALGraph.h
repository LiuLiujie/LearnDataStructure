#pragma once

#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef char OtherInfo;
typedef int Arctype;

class ALGraph
{
	friend class Graph;
public:
	ALGraph();
	~ALGraph();
private:
	struct ArcNode//边结点
	{
		int adjvex;//该边指向的顶点的位置
		ArcNode* nextarc;
		OtherInfo info;
	};

	struct VNode//顶点信息
	{
		VerTexType data;
		ALGraph::ArcNode* firstArc;
	};
	VNode AdjList[MVNum];//邻接表
	int vexNum, arcNum;
};

