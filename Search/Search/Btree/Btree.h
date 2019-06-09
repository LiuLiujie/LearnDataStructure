#pragma once
#include "..//Type.h"

class BTree
{
private:
	Result SearchBTree(BTNode*& T, KeyType key);
	void InsertBTree(BTNode*& T, KeyType key, Btree T, int i);
	//void DeleteBTree();//未完成函数,后序补充

public:
	BTNode* root;
	BTree();
	~BTree();
	Result SearchBtree(KeyType key);
	void InsertBTree(KeyType key);

};

