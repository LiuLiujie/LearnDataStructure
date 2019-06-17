#pragma once

#include "..//Type.h"
#include <iostream>

class BTree
{
private:
	bool NodeExist;//结点是否存在,用于搜索,插入,删除结点
	void DeleteBTree(BTNode*& T);//删除整棵树

	Result SearchBTreeNode(BTNode*& T, KeyType key);
	void InsertBTreeNode(BTNode*& T, KeyType key, BTNode* q, int i);//未完成

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBTreeNode(KeyType key);
	void InsertBTreeNode(KeyType key);
	void MakeEmpty();//删除整棵树,使之成为空树
};

