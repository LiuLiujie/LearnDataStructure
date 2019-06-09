#pragma once
#include "..//Type.h"
class ExchangeSort
{
public:
	void BubbleSort(SqList &L);
	void QuickSort(SqList &L);
	ExchangeSort();
	~ExchangeSort();

private:
	void QSort(SqList& L, int low, int high);
	int Partition(SqList& L, int low, int high);
};

