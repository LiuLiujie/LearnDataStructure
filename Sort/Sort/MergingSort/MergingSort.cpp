#include "MergingSort.h"

void MergingSort::MergeSort(SqList& L)
{
	MSort(L.r, L.r, 1, L.length);
}

MergingSort::MergingSort()
{
}

MergingSort::~MergingSort()
{
}

void MergingSort::Merge(RedType R[], RedType T[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high)
	{
		if (R[i].key <= R[j].key) {
			T[k++] = R[i++];
		}else{
			T[k++] = R[j++];
		}
	}
	while (i<=mid)
	{
		T[k++] = R[i++];
	}
	while (j<=high)
	{
		T[k++] = R[j++];
	}
}

void MergingSort::MSort(RedType R[], RedType T[], int low, int high)
{
	
	if (low==high)
	{
		T[low] = R[low];
	}else {
		int mid = (low + high) / 2;//����ǰ���ж���
		RedType *S = new RedType[low+high];
		MSort(R, S, low, mid);//�ݹ�鲢����,�������
		MSort(R, S, mid + 1, high);
		Merge(S, T, low, mid, high);
	}
}
