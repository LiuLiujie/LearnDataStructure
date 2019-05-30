#include <iostream>

#include "Type.h"
#include "Sequential Search/SequentialSearch.h"
#include "Binary Search/BinarySearch.h"
#include "BST&AVL/BalanceSortTree.h"
#include "BST&AVL/AVLTree.h"

void testSequentialSearch();
void testBinarySearch();
void testBST();
void testAVL();

int main()
{
	//testSequentialSearch();
	//testBinarySearch();
	//testBST();
	testAVL();
}

void testSequentialSearch()
{
	SSTable test;//生成一个长度为100的顺序表,0空出来作为观察哨
	test.R = new ElemType[101];
	for (int i = 1; i <= 100; i++) {
		test.R[i].key = i;
		test.length = 100;
	}
	KeyType myKey = 10;//设定搜索关键字为A

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
	KeyType myKey = 14;//设定搜索关键字为A

	std::cout << Search_Bin(test, myKey) << std::endl;
}

void testBST()
{
	ElemType e[100];
	int num = 100;
	for (int i = 0; i < num; i++) {
		e[i].key = i;
	}
	e[1].otherInfo = 'c';
	BalanceSortTree test;
	test.CreateBST(e, 100);
	ElemType a = test.SearchBST(1);
	std::cout << a.otherInfo;
	test.MakeEmpty();
}

void testAVL()
{
	ElemType e[9];
	KeyType a[] = { 16,3,7,11,9,26,18,14,15 };
	for (int i = 0; i < 9; i++) {
		e[i].key = a[i];
	}
	AVLTree test;
	for (int i = 0; i < 9; i++) {
		test.InsertAVL(e[i]);
	}
}
