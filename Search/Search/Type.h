#pragma once
typedef int KeyType;
typedef char InfoType;

struct ElemType {
	KeyType key;//�ؼ�����
	InfoType otherInfo;//������
};

struct SSTable {
	ElemType* R;//�洢�ռ����ַ
	int length;//��ǰ����
};

struct BSTNode {
	ElemType data;
	BSTNode* lchild, * rchild;
};

