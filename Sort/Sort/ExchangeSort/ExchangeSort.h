#pragma once
#include "..//Type.h"
class ExchangeSort
{
public:
	void BubbleSort(SqList &L);
	void QuickSort(SqList &L);//这个快排很难理解,换一个
	ExchangeSort();
	~ExchangeSort();

private:
	void QSort(SqList& L, int low, int high);
	int Partition(SqList& L, int low, int high);
};

