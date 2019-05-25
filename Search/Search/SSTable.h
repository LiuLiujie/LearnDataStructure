#pragma once
typedef int keyType;
typedef char infoType;

struct ElemType {
	keyType key;//关键字域
	infoType otherinfo;//其他域
};

struct SSTable {
	ElemType* R;//存储空间基地址
	int length;//当前长度
};

struct BSTNode {
	ElemType data;//每个结点的数据包括关键字和其他数据项
	BSTNode* lchild, * rchild;//左右孩子的指针
};