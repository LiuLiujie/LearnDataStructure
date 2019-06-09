#pragma once

#include <iostream>
#include "AMGraph.h"

class Graph
{
private:
	AMGraph *AMG;
	void CreateUDN(AMGraph* G);//������
	void CreateDN(AMGraph* G);//������
	int LocateVex(AMGraph* G, VerTexType u);//����AMͼG�ж���u��λ��

#pragma region ͼ�ı���
	//�������
	void DFS_AM(AMGraph* G, int v);//�ӵ�v����ʼ����AMͼ
	bool visited[MVNum];
#pragma endregion

#pragma region ��С������
	#pragma region ����ķ�㷨
	struct Closedge//��¼��С��
	{
		VerTexType adjvex;//��С�ߵĶ�Ӧ���¶���
		Arctype lowcost;//������С�ߵ�Ȩֵ
	};
	Closedge closedge[MVNum];
	int Min(Closedge* closedge);
	void MiniSpanTree_Prim(AMGraph* G, VerTexType u);//�Ӷ���u����,����ķ�㷨����AMͼ����С������
	#pragma endregion

	#pragma region ��³˹�����㷨
	struct Edge {
		VerTexType Head;
		VerTexType Tail;
		Arctype lowcast;
	};
	Edge *edge;
	int Vexset[MVNum];//��������
	void MiniSpanTree_Kruskal(AMGraph* G);
	void Sort(Edge* edge);
	#pragma endregion
#pragma endregion

#pragma region ���·��
	#pragma region �Ͻ���˹��
	bool S[MVNum];//��¼��ԭ��v0��vi�Ƿ��Ѿ�ȷ�����·��
	int Path[MVNum];//��¼��ԭ��v0���յ�v1�ĵ�ǰ���·��vi��ֱ��ǰ�����,��Ϊ-1
	int D[MVNum];//��¼��v0��vi�����·������,��ΪmaxInt
	void ShortestPath(AMGraph* G, int v0);
	#pragma endregion

#pragma endregion
public:
	Graph();
	~Graph();
	void CreateUDN();//����������
	void CreateDN();//����������
	//ͼ�ı���
	void DFS(int v = 0);//�ӵ�v�����㿪ʼ������ͨͼ,Ĭ��0

	//��С������
	void MiniSpanTree(VerTexType u);//�Ӷ���u����������С������,����ķ�㷨
	void MiniSpanTree();//��³˹�����㷨

	//���·��
	void ShortestPath(VerTexType v0);
};

