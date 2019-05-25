#pragma once
typedef int KeyType;
typedef char InfoType;

struct ElemType {
	KeyType key;//关键字域
	InfoType otherInfo;//其他域
};

struct SSTable {
	ElemType* R;//存储空间基地址
	int length;//当前长度
};

struct BSTNode {
	ElemType data;
	BSTNode* lchild, * rchild;
};

