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
	SSTable test;//生成一个长度为100的顺序表,0空出来作为观察哨
	test.R = new ElemType[101];
	for (int i = 1; i <= 100; i++) {
		test.R[i].key = i;
		test.length = 100;
	}
	keyType myKey = 10;//设定搜索关键字为A

	std::cout << Search_Seq(test, myKey) << std::endl;
}

void testBinarySearch()
{
	SSTable test;//生成一个长度为100的顺序表,0空出来作为观察哨
	test.R = new ElemType[101];
	for (int i = 1; i <= 100; i++) {
		test.R[i].key = i;
		test.length = 100;
	}
	keyType myKey = 14;//设定搜索关键字为A

	std::cout << Search_Bin(test, myKey) << std::endl;
}
