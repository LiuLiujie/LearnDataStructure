#pragma once
#include "..//Type.h"

class SelectSort
{
public:
	void SimpleSelectSort(SqList& L);//��ѡ������
	void HeapSort(SqList &L);//������
	SelectSort();
	~SelectSort();
private:
	void CreateHeap(SqList& L);//������
	void HeapAdjust(SqList& L, int s, int m);//������
};

