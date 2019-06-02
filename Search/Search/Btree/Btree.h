#pragma once
#include "..//Type.h"

class Btree
{
private:
	Result SearchBTree(Btree*& T, KeyType key);
	void InsertBTree(Btree*& T, KeyType key, Btree T, int i);
	//void DeleteBTree();//未完成函数,后序补充

public:
	BTNode* root;
	Btree();
	~Btree();
	Result SearchBtree(KeyType key);
	void InsertBTree(KeyType key);//接口,调用search函数获得T和i

};

