#include "Btree.h"

Result BTree::SearchBTree(BTNode*& T, KeyType key)
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
