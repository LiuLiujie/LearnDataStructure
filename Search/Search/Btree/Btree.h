#pragma once
#include "..//Type.h"

class BTree
{
private:
	bool NodeExist;
	void DeleteBTree(BTNode*& T);//ɾ��������

	Result SearchBTreeNode(BTNode*& T, KeyType key);
	void InsertBTreeNode(BTNode*& T, KeyType key, BTree q, int i);

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBtreeNode(KeyType key);
	void InsertBTreeNode(KeyType key);
	void MakeEmpty();//ɾ��������,ʹ֮��Ϊ����
};

