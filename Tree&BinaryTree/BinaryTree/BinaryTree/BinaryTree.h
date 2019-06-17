#pragma once

#include "BinTreeNode.h"

class BinaryTree
{
private:
	BinTreeNode* root;
	void InOrder(BinTreeNode*& T);
	void PreOrder(BinTreeNode*& T);
	void PostOrder(BinTreeNode*& T);
	void MakeEmpty(BinTreeNode*& T);

public:
	void InOrder();
	void PreOrder();
	void PostOrder();
	void MakeEmpty();
	bool IsEmpty();
};

