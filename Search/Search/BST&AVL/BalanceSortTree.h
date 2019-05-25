#pragma once
#include "../Type.h"

class BalanceSortTree
{
private:
	BSTNode *BSTree;
	BSTNode* SearchBST(BSTNode* T, KeyType key) const;
	void InsertBST(BSTNode*& T, ElemType e);//ÒýÓÃ´«µÝ
	void DeleteBST(BSTNode*& T, KeyType key);
	void MakeEmpty(BSTNode*& T);

public:
	BalanceSortTree();
	~BalanceSortTree();

	ElemType SearchBST(KeyType key) const;
	void CreateBST(ElemType e[], int num);
	void InsertBST(ElemType e);
	void DeleteBST(KeyType key);
	void MakeEmpty();
};

