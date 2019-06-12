#pragma once
#include "../Type.h"
class InsertSort
{
public:
	void ShellSort(SqList& L, int dt[], int t);
	void StraightInsertSort(SqList& L);
	void BinaryInsertSort(SqList& L);
	InsertSort();
	~InsertSort();

private:
	void ShellInsert(SqList& L, int dk);//dkÎªÔöÁ¿
};

