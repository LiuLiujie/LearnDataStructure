#pragma once

#include "..//Type.h"
#include <iostream>

class BTree
{
private:
	bool NodeExist;//����Ƿ����,��������,����,ɾ�����
	void DeleteBTree(BTNode*& T);//ɾ��������

	Result SearchBTreeNode(BTNode*& T, KeyType key);
	void InsertBTreeNode(BTNode*& T, KeyType key, BTNode* q, int i);//δ���

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBTreeNode(KeyType key);
	void InsertBTreeNode(KeyType key);
	void MakeEmpty();//ɾ��������,ʹ֮��Ϊ����
};

