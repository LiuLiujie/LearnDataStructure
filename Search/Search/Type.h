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
		int i;
		for (i = 1; i <= keyNum; ) {
			if (key < K[i]) {//С��,���ص���ָ�����λ��
				return i - 1;
			}
			else if (key > K[i]) {//����,��������
				i++;
			}else{//����,���ص����������λ��
				return i;
			}
		}
		return i - 1;//�����Ҳûһ�ҵ�,�������ָ�����λ��
	}
};

