#pragma once
#include "..//Type.h"

class Btree
{
private:
	Result SearchBTree(Btree*& T, KeyType key);
	void InsertBTree(Btree*& T, KeyType key, Btree T, int i);
	//void DeleteBTree();//δ��ɺ���,���򲹳�

public:
	BTNode* root;
	Btree();
	~Btree();
	Result SearchBtree(KeyType key);
	void InsertBTree(KeyType key);//�ӿ�,����search�������T��i

};

