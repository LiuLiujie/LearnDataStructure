#pragma once

#include "..//Type.h"
#include <iostream>

class BTree
{
private:
	bool NodeExist;//����Ƿ����,��������,����,ɾ�����
	void DeleteBTree(BTNode*& T);//ɾ��������

	Result SearchBTree(BTNode*& T, KeyType key);
	void InsertBTree(BTNode*& T, KeyType key, BTNode* q, int i);//������bug
	void NewRoot(BTNode*& T, KeyType key, BTNode* p = nullptr, BTNode* ap = nullptr);//�������ڵ�
	void Insert(BTNode*& q, KeyType key, BTNode* ap, int i);//����key
	void Split(BTNode*& q, BTNode*& ap, int s);//���ѽ��

	void DeleteBTree(BTNode*& T, BTNode*& p, int i);//ɾ���ڵ�
	void Successor(BTNode*& p, int i);
	void Remove(BTNode*& p, int i);
	void Restore(BTNode*& T, BTNode*& p);
	void BorrowFromBrother(BTNode*& p, BTNode*& leftBrother, BTNode*& rightBrother, BTNode*& parent, int& i);
	void MergeWithLeftBrother(BTNode*& leftBrother, BTNode*& parent, BTNode*& p, BTNode*& T, int& i);
	void MergeWithRightBrother(BTNode*& rightBrother, BTNode*& parent, BTNode*& p, BTNode*& T, int& i);

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBTree(KeyType key);
	void InsertBTree(KeyType key);
	void MakeEmpty();//ɾ��������,ʹ֮��Ϊ����
};

