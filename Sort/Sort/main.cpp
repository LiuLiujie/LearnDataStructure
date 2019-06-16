#include <iostream>
#include "InsertSort/InsertSort.h"
#include "ExchangeSort/ExchangeSort.h"
#include "SelectSort/SelectSort.h"
#include "MergingSort/MergingSort.h"

using namespace std;

int main()
{
	InsertSort test;
	MergingSort testMerging;//tested

	/*测试数据*/
	SqList L;
	L.length = 6;
	int A[] = { 1,3,4,2,5,7 };
	for (int i = 1; i <= L.length; i++)
	{
		L.r[i].key = A[i-1];
	}

	/*测试函数*/
	testMerging.MergeSort(L);

	/*结果输出*/
	for (int i = 1; i <= L.length; i++)
	{
		cout<<L.r[i].key;
	}
}