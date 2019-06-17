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
		i = p->Search(key);//在本节点查找
		if (i > 0 && p->K[i] == key) {//在本节点找到了
			found = true;
		} else {//在本节点未找到,去下一个结点找
			q = p;
			p = p->ptr[i];
		}
		if (found) {
			return Result{ p, i, 1 };//查找成功,返回待查结点
		} else {
			return Result{ q, i, 0 };//查找失败,返回应该插入该key的位置(便于后续插入)
		}
	}
}

void BTree::InsertBTreeNode(BTNode*& T, KeyType key, BTNode* q, int i)
{
	BTNode* ap = nullptr;
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

Result BTree::SearchBTreeNode(KeyType key)
{
	return SearchBTreeNode(root, key);
}

void BTree::InsertBTreeNode(KeyType key)
{
	Result res;
	res = SearchBTreeNode(key);
	if (res.tag == 0)//即查找失败,此时res中返回的是应该插入的结点
	{
		InsertBTreeNode(root, key, res.pt, res.i);
	}else
	{
		std::cout << "结点已存在,无需重复插入" << std::endl;
	}
}

void BTree::MakeEmpty()
{
	DeleteBTree(root);
	root = nullptr;
}
