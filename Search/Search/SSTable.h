#pragma once
typedef int keyType;
typedef char infoType;

struct ElemType {
	keyType key;//�ؼ�����
	infoType otherinfo;//������
};

struct SSTable {
	ElemType* R;//�洢�ռ����ַ
	int length;//��ǰ����
};

struct BSTNode {
	ElemType data;//ÿ���������ݰ����ؼ��ֺ�����������
	BSTNode* lchild, * rchild;//���Һ��ӵ�ָ��
};