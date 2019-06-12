#pragma once
#include "..//Type.h"

class SelectSort
{
public:
	void SimpleSelectSort(SqList& L);//简单选择排序
	void HeapSort(SqList &L);//堆排序
	SelectSort();
	~SelectSort();
private:
	void CreateHeap(SqList& L);//建初堆
	void HeapAdjust(SqList& L, int s, int m);//调整堆
};

