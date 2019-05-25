#pragma once
#include"..//Type.h"

/*二分查找:
	使用条件:仅在顺序表有序的时候可用,因而不适用于数据经常变化的表
	注意:low=high时再找一次才查找完成,这时还剩最后一个结点(high或者low)没有比较
	二分查找也可以使用递归的形式
	时间复杂度为O(logn)
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