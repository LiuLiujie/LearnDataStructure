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
	BTNode* p = T, * q = nullptr;//pָ�������,qָ��p��˫��
	bool found = false;
	int i = 0;
	while (p && !found) {
		i = p->Search(key);//�ڱ��ڵ��в���,ʹ��i�������ؼ���֮��
		if (i > 0 && p->K[i] == key) {
			found = true;
		} else {
			q = p;
			p = p->ptr[i];
		}
		if (found) {
			return Result{ p, i, 1 };//���ҳɹ�,���ش�����
		} else {
			return Result{ q, i, 0 };//����ʧ��,����Ӧ�ò���key��λ��
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
