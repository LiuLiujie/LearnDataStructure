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

class AVLNode
{
	friend class AVLTree;
public:
	ElemType data;
	AVLNode* left, * right;
	int balence;//ƽ������:���������-���������(��ʼ����Ϊ0)
	AVLNode() :left(nullptr), right(nullptr), balence(0) {};
	AVLNode(ElemType d, AVLNode* l = nullptr, AVLNode* r = nullptr)
		:data(d), left(l), right(r), balence(0) {};
	~AVLNode() {};
};

