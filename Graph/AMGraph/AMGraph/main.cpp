#include <iostream>
#include "Graph.h"

int main()
{
	Graph test;
	//test.CreateUDN();//��������ͼ
	//test.DFS();//ͼ�ı���,�����������
	//test.MiniSpanTree('A');//����ķ�㷨������С������
	//test.MiniSpanTree();//��³˹�����㷨������С������

	test.CreateDN();//��������ͼ
	test.ShortestPath('B');//�Ͻ���˹���㷨�������·��,�Ѳ���
	return 0;
}
