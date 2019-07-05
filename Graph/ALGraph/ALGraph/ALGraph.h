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
	struct ArcNode//�߽��
	{
		int adjvex;//�ñ�ָ��Ķ����λ��
		ArcNode* nextarc;
		OtherInfo info;
	};

	struct VNode//������Ϣ
	{
		VerTexType data;
		ALGraph::ArcNode* firstArc;
	};
	VNode AdjList[MVNum];//�ڽӱ�
	int vexNum, arcNum;
};

