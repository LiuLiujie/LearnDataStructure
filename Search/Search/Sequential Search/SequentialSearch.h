#pragma once
#include"..//Type.h"

/*˳�����:
	��˳���ST��˳�������ؼ��ֵ���key������Ԫ��.
	���ҵ�,����ֵΪ��Ԫ���ڱ��е�λ��,����Ϊ0
	����0λΪ����,��ȥ����Ƿ�>=1,����ٶ�
	ʱ�临�Ӷ�ΪO(n)
*/
int Search_Seq(SSTable ST, KeyType key) 
{
	ST.R[0].key = key;
	int i;
	for (i = ST.length; ST.R[i].key != key; --i);
	return i;
}

