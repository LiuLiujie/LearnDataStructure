#pragma once

#include "..//Type.h"
#include <iostream>

class BTree
{
private:
	bool NodeExist;//����Ƿ����,��������,����,ɾ�����
	void DeleteBTree(BTNode*& T);//ɾ��������

	Result SearchBTree(BTNode*& T, KeyType key);
	void InsertBTree(BTNode*& T, KeyType key, BTNode* q, int i);//δ���
	void NewRoot(BTNode*& T, KeyType key, BTNode* p = nullptr, BTNode* ap = nullptr);//�������ڵ�
	void Insert(BTNode*& q, KeyType key, BTNode* ap, int i);//����key
	void Split(BTNode*& q, BTNode*& ap, int s);//���ѽ��

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBTree(KeyType key);
	void InsertBTree(KeyType key);
	void MakeEmpty();//ɾ��������,ʹ֮��Ϊ����
};

