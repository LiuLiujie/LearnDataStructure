#pragma once
#include "..//SSTable.h"
class SequentialSearch
{
public:
	/*˳�����:
	��˳���ST��˳�������ؼ��ֵ���key������Ԫ��.
	���ҵ�,����ֵΪ��Ԫ���ڱ��е�λ��,����Ϊ0
	����0λΪ����,��ȥ����Ƿ�>=1,����ٶ�
	*/
	int Search_Seq(SSTable ST, keyType key) 
	{
		ST.R[0].key = key;
		int i;
		for (i = ST.length; ST.R[i].key != key; --i);
		return i;
	}

};

