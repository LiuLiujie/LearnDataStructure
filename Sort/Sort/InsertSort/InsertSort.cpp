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


/*ֱ�Ӳ�������
	ʱ�临�Ӷȣ�n^2
	�ȶ�������(������key��ͬԪ�ص�ǰ��˳�򲻻�ı�)
	�����޸Ŀ�������ʽ�ṹ
*/
void InsertSort::StraightInsertSort(SqList& L)
{
	for (int i = 2; i <= L.length; i++)
	{
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];//�Ѵ����������ݴ��ڼ�������
			L.r[i] = L.r[i - 1];//�Ѵ������ݵ�ǰһ�����ݺ��ƣ��ճ�λ�ñ����ƶ�
			int j = i - 2;//jָ���λ��ǰһ��Ԫ��
			while (L.r[0].key < L.r[j].key) {//�Ѵ��ڴ������ݵ�Ԫ�������ƶ�
				L.r[j + 1] = L.r[j];
				j--;
			}
			L.r[j + 1] = L.r[0];//���������ݲ���
		}
	}
}

/*�۰��������
	ʱ�临�Ӷ�:n^2, ���ٶȱ�ֱ�Ӳ����
	�ȶ�������
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
