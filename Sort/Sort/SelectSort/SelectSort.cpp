#include "SelectSort.h"

/*直接选择排序
	不停地把本轮排序关键字最小的元素丢到前面去
	时间复杂度O(n^2)
*/
void SelectSort::SimpleSelectSort(SqList& L)
{
	int k;
	RedType t;
	for (int i = 1; i < L.length; i++)
	{
		k = i;
		for (int j = i + 1; j <= L.length; j++)
		{
			if (L.r[j].key < L.r[k].key) {
				k = j;//k指向本趟排序中关键字最小的记录
			}
		}
		if (k != i) {
			t = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = t;
		}
	}
}

void SelectSort::HeapSort(SqList& L)
{
	CreateHeap(L);
	RedType x;
	for (int i = L.length; i > 1; i--)
	{
		x = L.r[1];
		L.r[1] = L.r[i];
		L.r[i] = x;
		HeapAdjust(L, 1, i - 1);
	}
}

void SelectSort::CreateHeap(SqList& L)
{
	int n = L.length;
	for (int i = n / 2; i > 0; i--)
	{
		HeapAdjust(L, i, n);
	}
}

void SelectSort::HeapAdjust(SqList& L, int s, int m)
{
	RedType rc = L.r[s];
	for (int j = 2 * s; j <= m; j++)
	{
		if (j < m && L.r[j].key < L.r[j + 1].key) {
			j++;
		}
		if (rc.key>=L.r[j].key)
		{
			break;
		}
		L.r[s] = L.r[j];
		s = j;
	}
	L.r[s] = rc;
}
