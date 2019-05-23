#pragma once
#include"../SSTable.h"

/*���ֲ���:
	ʹ������:����˳��������ʱ�����
	ע��:low=highʱ����һ�βŲ������,��ʱ��ʣ���һ�����(high����low)û�бȽ�
	���ֲ���Ҳ����ʹ�õݹ����ʽ
*/
int Search_Bin(SSTable ST, keyType key)
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