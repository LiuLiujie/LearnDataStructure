#include "ExchangeSort.h"

/*冒泡排序:
	一轮把最大的一个关键字移到最后,最坏n-1轮
	稳定的排序
	时间复杂度n^2
*/
void ExchangeSort::BubbleSort(SqList& L)
{
	int m = L.length - 1;
	bool flag = 1;//用于计算一趟排序是否发生交换
	RedType t;
	while ((m > 0) && flag)
	{
		flag = 0;//初始化flag,若没有发生交换,则不会进行下一趟排序
		for (int i = 1; i <= m; i++)
		{
			if (L.r[i].key > L.r[i + 1].key) {
				flag = 1;
				t = L.r[i];
				L.r[i] = L.r[i + 1];
				L.r[i + 1] = t;
			}
		}
		m--;
	}
}

void ExchangeSort::QuickSort(SqList& L)
{

}

ExchangeSort::ExchangeSort()
{
}

ExchangeSort::~ExchangeSort()
{
}

void ExchangeSort::QSort(SqList& L, int low, int high)
{
}

int ExchangeSort::Partition(SqList& L, int low, int high)
{
	return 0;
}
