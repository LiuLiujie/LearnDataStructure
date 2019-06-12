#pragma once
#include "..//Type.h"

class MergingSort
{
public:
	void MergeSort(SqList& L);
	MergingSort();
	~MergingSort();

private:
	//RedType *S;
	void Merge(RedType R[], RedType T[], int low, int mid, int high);
	void MSort(RedType R[], RedType T[], int low, int high);
};

