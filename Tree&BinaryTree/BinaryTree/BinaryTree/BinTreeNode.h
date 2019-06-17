#pragma once

typedef char TElemType;

class BinTreeNode
{
	friend class BinaryTree;
private:
	TElemType data;
	BinTreeNode* lchild, * rchild;

public:
	BinTreeNode();
	BinTreeNode(TElemType _data, BinTreeNode* _lchild = nullptr, BinTreeNode* _rchild = nullptr);
	~BinTreeNode();

	BinTreeNode* GetLChild();
	BinTreeNode* GetRChild();
	TElemType GetData();
};

