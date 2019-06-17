#include "BinTreeNode.h"

BinTreeNode::BinTreeNode()
{
	lchild = nullptr;
	rchild = nullptr;
}

BinTreeNode::BinTreeNode(TElemType _data, BinTreeNode* _lchild, BinTreeNode* _rchild)
{
	data = _data;
	lchild = _lchild;
	rchild = _rchild;
}

BinTreeNode::~BinTreeNode()
{
}

BinTreeNode* BinTreeNode::GetLChild()
{
	return lchild;
}

BinTreeNode* BinTreeNode::GetRChild()
{
	return rchild;
}

TElemType BinTreeNode::GetData()
{
	return data;
}
