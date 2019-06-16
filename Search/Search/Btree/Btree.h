#pragma once
#include "..//Type.h"

class BTree
{
private:
	bool NodeExist;
	void DeleteBTree(BTNode*& T);//删除整棵树

	Result SearchBTreeNode(BTNode*& T, KeyType key);
	void InsertBTreeNode(BTNode*& T, KeyType key, BTree q, int i);

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBtreeNode(KeyType key);
	void InsertBTreeNode(KeyType key);
	void MakeEmpty();//删除整棵树,使之成为空树
};

