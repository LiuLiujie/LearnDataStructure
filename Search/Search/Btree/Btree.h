#pragma once

#include "..//Type.h"
#include <iostream>

class BTree
{
private:
	bool NodeExist;//结点是否存在,用于搜索,插入,删除结点
	void DeleteBTree(BTNode*& T);//删除整棵树

	Result SearchBTree(BTNode*& T, KeyType key);
	void InsertBTree(BTNode*& T, KeyType key, BTNode* q, int i);//未完成
	void NewRoot(BTNode*& T, KeyType key, BTNode* p = nullptr, BTNode* ap = nullptr);//创建根节点
	void Insert(BTNode*& q, KeyType key, BTNode* ap, int i);//插入key
	void Split(BTNode*& q, BTNode*& ap, int s);//分裂结点

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBTree(KeyType key);
	void InsertBTree(KeyType key);
	void MakeEmpty();//删除整棵树,使之成为空树
};

