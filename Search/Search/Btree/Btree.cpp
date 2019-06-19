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

Result BTree::SearchBTree(BTNode*& T, KeyType key)
{
	BTNode* p = T, * q = nullptr;//pָ�������,qָ��p��˫��
	bool found = false;
	int i = 0;
	while (p && !found) {
		i = p->Search(key);//�ڱ��ڵ����
		if (i <= p->keyNum && p->Key[i] == key) {//�ڱ��ڵ��ҵ���
			found = true;
		} else {//�ڱ��ڵ�δ�ҵ�,ȥ��һ�������
			q = p;
			p = p->ptr[i-1];
		}
	}
	if (found) {
		return Result{ p, i, 1 };//���ҳɹ�,���ش�����
	} else {
		return Result{ q, i, 0 };//����ʧ��,����Ӧ�ò����key��λ��(���ں�������)
	}
}

/*��Key[i-1]��Key[i]֮�����ؼ���key*/
void BTree::InsertBTree(BTNode*& T, KeyType key, BTNode* q, int i)
{
	KeyType x;//ָ����Ҫ�����Ԫ��,һ��ʼָ��key,����ָ����Ҫ����˫�׽ڵ��Ԫ��
	int s;//�洢��λ��,���ڷ���
	bool finished = false;
	bool needNewRoot = false;
	BTNode* ap;//ָ���½ڵ��ָ��
	if (!q) {//qΪ��,˵����һ���յ�B-��,��Ҫ����
		NewRoot(T, key);
	}else{
		x = key;
		ap = nullptr;
		while (!needNewRoot && !finished)
		{
			Insert(q, key, ap, i);//������Ԫ��
			if (q->keyNum < BTOrder) {//�����Ԫ�ظ����Ƿ񳬳�
				finished = true;
			}else {//���ѽ��
				s = (BTOrder + 1) / 2;
				Split(q, ap, s);
				x = q->Key[s];//xָ���м�Ҫ�ᵽ˫�׽ڵ��Ԫ��
				if (q->parent) {//����˫�׽ڵ㲻Ϊ��,���ҵ���ȷλ�ò���
					q = q->parent;
					i = q->Search(x);//��q�в���Ҫ�����λ��,����ִ��whileѭ������Ԫ��
				}else{
					needNewRoot = true;
				}
			}
		}
		//���������Bug,�����ڵ��������Ϊp��apָ�������,��������������ô��
		if (needNewRoot){//�������Ҫ����һ���µĸ��ڵ�,��q��ap�洢ԭ���Ľ��,T����Ϊ�½ڵ�,
			NewRoot(T, x, q, ap);
		}
	}
}

/*����һ���µĸ��ڵ�*/
void BTree::NewRoot(BTNode*& T, KeyType key, BTNode* p, BTNode* ap)
{
	T = new BTNode;
	T->keyNum = 1;
	T->ptr[0] = p;
	T->ptr[1] = ap;
	T->Key[1] = key;
	if (p)
	{
		p->parent = T;
	}
	if (ap)
	{
		ap->parent = T;
	}
}

/*��q->Key[i]��q->Key[i+1]֮�����key*/
void BTree::Insert(BTNode*& q, KeyType key, BTNode* ap, int i)
{
	int j;
	int n = q->keyNum;
	for (j = n; j >= i; j--)//����
	{
		q->Key[j + 1] = q->Key[j];
		q->ptr[j + 1] = q->ptr[j];
	}
	q->Key[i] = key;
	q->ptr[i] = ap;
	if (ap)
	{
		ap->parent = q;
	}
	(q->keyNum)++;
}

/*��������,ǰһ�뱣����ԭ�ڵ�,��һ������ap��ָ����½ڵ�*/
void BTree::Split(BTNode*& q, BTNode*& ap, int s)
{
	int i, j;
	int n = q->keyNum;//�ؼ�������
	ap = new BTNode;
	ap->ptr[0] = q->ptr[s];//����n-s���������n-s+1��ָ����
	for (i = s + 1, j = 1; i <= n; i++, j++)
	{
		ap->Key[j] = q->Key[i];
		ap->ptr[j] = q->ptr[i];
	}
	ap->keyNum = n - s;
	ap->parent = q->parent;
	for ( i = 0; i <= ap->keyNum; i++)//�޸��½ڵ�ap���ӽڵ�ĸ��ڵ�
	{
		if (ap->ptr[i])
		{
			ap->ptr[i]->parent = ap;
		}
	}
	q->keyNum = s - 1;//����ĸ����ǰ�һ������ᵽ˫��λ�ú�ĸ���,��ȡ����������������
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

Result BTree::SearchBTree(KeyType key)
{
	return SearchBTree(root, key);
}

void BTree::InsertBTree(KeyType key)
{
	Result res;
	res = SearchBTree(key);
	if (res.tag == 0)//������ʧ��,��ʱres�з��ص���Ӧ�ò���Ľ��
	{
		InsertBTree(root, key, res.pt, res.i);
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
