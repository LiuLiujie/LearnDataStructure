#include "InsertSort.h"

void InsertSort::ShellInsert(SqList& L, int dk)
{
	for (int i = dk + 1; i < L.length; i++)
	{
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			int j;
			for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
			{
				L.r[j + dk] = L.r[j];
			}
			L.r[j + dk] = L.r[0];
		}
	}
}

void InsertSort::ShellSort(SqList& L, int dt[], int t)
{
	for (int k = 0; k < t; k++)
	{
		ShellInsert(L, dt[k]);
	}
}


/*直接插入排序
	时间复杂度：n^2
	稳定的排序(即两个key相同元素的前后顺序不会改变)
	稍稍修改可用于链式结构
*/
void InsertSort::StraightInsertSort(SqList& L)
{
	for (int i = 2; i <= L.length; i++)
	{
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];//把待插入数据暂存在监视哨中
			L.r[i] = L.r[i - 1];//把待插数据的前一个数据后移，空出位置便于移动
			int j = i - 2;//j指向空位的前一个元素
			while (L.r[0].key < L.r[j].key) {//把大于待插数据的元素往后移动
				L.r[j + 1] = L.r[j];
				j--;
			}
			L.r[j + 1] = L.r[0];//将待插数据插入
		}
	}
}

/*折半插入排序
	时间复杂度:n^2, 但速度比直接插入快
	稳定的排序
*/
void InsertSort::BinaryInsertSort(SqList& L)
{
	for (int i = 2; i <= L.length; i++)
	{
		L.r[0] = L.r[i];
		int low = 1, high = i - 1;
		int m;
		while (low <= high) {
			m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key) {
				high = m - 1;
			}
			else {
				low = m - 1;
			}
		}
		int j;
		for (j = i - 1; j >= high + 1; j--)
		{
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}

InsertSort::InsertSort()
{
}

InsertSort::~InsertSort()
{
}
