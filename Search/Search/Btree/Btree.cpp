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
		i = p->Search(key);//�ڱ��ڵ����
		if (i > 0 && p->K[i] == key) {//�ڱ��ڵ��ҵ���
			found = true;
		} else {//�ڱ��ڵ�δ�ҵ�,ȥ��һ�������
			q = p;
			p = p->ptr[i];
		}
		if (found) {
			return Result{ p, i, 1 };//���ҳɹ�,���ش�����
		} else {
			return Result{ q, i, 0 };//����ʧ��,����Ӧ�ò����key��λ��(���ں�������)
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
	if (res.tag == 0)//������ʧ��,��ʱres�з��ص���Ӧ�ò���Ľ��
	{
		InsertBTreeNode(root, key, res.pt, res.i);
	}else
	{
		std::cout << "����Ѵ���,�����ظ�����" << std::endl;
	}
}

void BTree::MakeEmpty()
{
	DeleteBTree(root);
	root = nullptr;
}
