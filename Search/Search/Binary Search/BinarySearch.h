#pragma once
#include"..//Type.h"

/*���ֲ���:
	ʹ������:����˳��������ʱ�����,��������������ݾ����仯�ı�
	ע��:low=highʱ����һ�βŲ������,��ʱ��ʣ���һ�����(high����low)û�бȽ�
	���ֲ���Ҳ����ʹ�õݹ����ʽ
	ʱ�临�Ӷ�ΪO(logn)
*/
int Search_Bin(SSTable ST, KeyType key)
{
	int low = 1, high = ST.length;
	int mid;
	while (low<=high) {
		mid = (low + high) / 2;
		if (key == ST.R[mid].key) {
			return mid;
		}
		else if (key<ST.R[mid].key) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return 0;
}