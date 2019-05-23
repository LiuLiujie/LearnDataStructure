#include <iostream>

#include "SSTable.h"
#include "Sequential Search/SequentialSearch.h"
#include "Binary Search/BinarySearch.h"

void testSequentialSearch();
void testBinarySearch();

int main()
{
	testSequentialSearch();
	testBinarySearch();
}

void testSequentialSearch()
{
	SSTable test;//����һ������Ϊ100��˳���,0�ճ�����Ϊ�۲���
	test.R = new ElemType[101];
	for (int i = 1; i <= 100; i++) {
		test.R[i].key = i;
		test.length = 100;
	}
	keyType myKey = 10;//�趨�����ؼ���ΪA

	std::cout << Search_Seq(test, myKey) << std::endl;
}

void testBinarySearch()
{
	SSTable test;//����һ������Ϊ100��˳���,0�ճ�����Ϊ�۲���
	test.R = new ElemType[101];
	for (int i = 1; i <= 100; i++) {
		test.R[i].key = i;
		test.length = 100;
	}
	keyType myKey = 14;//�趨�����ؼ���ΪA

	std::cout << Search_Bin(test, myKey) << std::endl;
}
