#pragma once
#include "..//SSTable.h"
class SequentialSearch
{
public:
	/*顺序查找:
	在顺序表ST中顺序查找其关键字等于key的数据元素.
	若找到,则函数值为该元素在表中的位置,否则为0
	设置0位为岗哨,免去检测是否>=1,提高速度
	*/
	int Search_Seq(SSTable ST, keyType key) 
	{
		ST.R[0].key = key;
		int i;
		for (i = ST.length; ST.R[i].key != key; --i);
		return i;
	}

};

