#pragma once

#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int Arctype;

class AMGraph
{
	friend class Graph;
private:
	VerTexType vexs[MVNum];//�����
	Arctype arcs[MVNum][MVNum];//�ڽӾ���
	int vexNum,arcNum;//ͼ�ĵ�ǰ�����ͱ���

public:
	AMGraph();
	~AMGraph();
};

