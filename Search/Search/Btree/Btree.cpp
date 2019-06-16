#include "Btree.h"

void BTree::DeleteBTree(BTNode*& T)
{
	if (T)
	{
		for (int i = 0; i < BTOrder + 1; i++)
		{
			DeleteBTree(T->ptr[i]);
		}
		delete T;
	}
}

Result BTree::SearchBTreeNode(BTNode*& T, KeyType key)
{
	BTNode* p = T, * q = nullptr;//p指向待查结点,q指向p的双亲
	bool found = false;
	int i = 0;
	while (p && !found) {
		i = p->Search(key);//在本节点中查找,使得i在两个关键字之间
		if (i > 0 && p->K[i] == key) {
			found = true;
		} else {
			q = p;
			p = p->ptr[i];
		}
		if (found) {
			return Result{ p, i, 1 };//查找成功,返回待查结点
		} else {
			return Result{ q, i, 0 };//查找失败,返回应该插入key的位置
		}
	}
}

BTree::BTree() :root(nullptr)
{
}

BTree::~BTree()
{
	if (root)
	{
		MakeEmpty();
	}
}

void BTree::MakeEmpty()
{
	DeleteBTree(root);
	root = nullptr;
}
