#include "ExchangeSort.h"

/*ð������:
	һ�ְ�����һ���ؼ����Ƶ����,�n-1��
	�ȶ�������
	ʱ�临�Ӷ�n^2
*/
void ExchangeSort::BubbleSort(SqList& L)
{
	int m = L.length - 1;
	bool flag = 1;//���ڼ���һ�������Ƿ�������
	RedType t;
	while ((m > 0) && flag)
	{
		flag = 0;//��ʼ��flag,��û�з�������,�򲻻������һ������
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
