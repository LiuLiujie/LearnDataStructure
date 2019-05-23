#include <iostream>

#include "SSTable.h"
#include "Sequential Search/SequentialSearch.h"

void testSequentialSearch();

int main()
{
	testSequentialSearch();
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

	SequentialSearch seqS;
	std::cout << seqS.Search_Seq(test, myKey);
}
