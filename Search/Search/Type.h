#pragma once

typedef int KeyType;
typedef char InfoType;
//������B���������
#define BTOrder 3

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

/*B��*/
struct Result
{
	BTNode* pt;//ָ���ҵ��Ľ��
	int i;//�ڽڵ��еĹؼ������,1~m
	int tag;//1��ʾ���ҳɹ�,0��ʾʧ��
};

class BTNode
{
	friend class BTree;
private:
	int keyNum;//����йؼ��ָ���
	BTNode* parent;//ָ��˫�׽��
	KeyType K[BTOrder + 1];//�ؼ���,0δ��
	BTNode* ptr[BTOrder + 1];//��¼ָ������,0ʹ��

	int Search(KeyType key)//δ����
	{
		for (int i = 1; i <= keyNum; i++) {
			if (key >= K[i]) {
				if (i + 1 <= keyNum && key < K[i+1]) {
					return i;
				} else {
					return keyNum;//�����һ��K��,�������ֵ
				}
			}
		}
		return 1;//�ȵ�һ��KС,����1
	}
};

