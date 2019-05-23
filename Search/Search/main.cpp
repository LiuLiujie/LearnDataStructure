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
	SSTable test;//����һ������Ϊ100��˳���,0�ճ�����Ϊ�۲���
	test.R = new ElemType[101];
	for (int i = 1; i <= 100; i++) {
		test.R[i].key = i;
		test.length = 100;
	}
	keyType myKey = 10;//�趨�����ؼ���ΪA

	SequentialSearch seqS;
	std::cout << seqS.Search_Seq(test, myKey);
}
