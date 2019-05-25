#include "BalanceSortTree.h"

BSTNode* BalanceSortTree::SearchBST(BSTNode* T, KeyType key) const
{
	/*�����������ĵݹ����:
		�ڸ�ָ��T��ָ�����������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ��
		��keyС�ڽڵ�T��key,�����������,�����������������
		�����ҳɹ�,�򷵻�ָ�������Ԫ�ؽڵ��ָ��,���򷵻ؿ�ָ��
	*/
	if ((!T) || key==T->data.key) {//����������TΪ��ʱ���ؿ�ָ��
		return T;
	} else if (key < T->data.key) {
		return SearchBST(T->lchild, key);
	} else {
		return SearchBST(T->rchild, key);
	}
}

void BalanceSortTree::InsertBST(BSTNode*& T, ElemType e)
{
	/*�����������Ĳ���
		���Ϊ����,�򽫽ڵ�S��Ϊ���ڵ����
		�����Ϊ��ʱ,��key��ڵ��key���бȽ�,
		���С�ڽڵ�,�����������,������ڽڵ�,����������(����������������ͬ)
	*/
	if (!T) {//TΪ��ʱ,�����ڵ�
		BSTNode* S = new BSTNode;
		S->data = e;
		S->lchild = S->rchild = nullptr;
		T = S;
	} else if (e.key<T->data.key) {//���
		InsertBST(T->lchild, e);
	} else if (e.key>T->data.key) {
		InsertBST(T->rchild, e);
	}
}


void BalanceSortTree::DeleteBST(BSTNode*& T, KeyType key)
{
	/*�Ӹ����ҹؼ��ֵ���key�Ľ��*/
	BSTNode* p = T, * f = nullptr;
	while (p) {
		if (p->data.key == key) {
			break;
		}
		f = p;//fָ��p���ϸ����
		if (p->data.key > key) {
			p = p->lchild;
		} else {
			p = p->rchild;
		
		}
	}
	if (!p) {
		return;
	}

	/*�����������:p������������Ϊ��, ��������, ��������*/
	BSTNode* q = p;
	if ((p->lchild) && (p->rchild)) {//���Ҿ�����
		BSTNode* s = p->lchild;//��s�ҵ�p������������������һ�����,qָ�������һ����㸸�ڵ�
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;//��s�������p��λ��
		if (q!=p) {
			q->rchild = s->lchild;//���½���q��������,�����s��Ҷ�ӽ��,��qָ��,��sֻ����ڵ�,��q��ָ��s��
		} else {//p==q���,��Ҫ��������s����p��������,��sһ��Ҳֻ��������,��������Ϊp������������
			p->lchild = s->lchild;
		}
		delete s;//ɾ�������ϵĽ��
		return;
	} else if (!p->rchild) {//pû��������,ֻ��Ҫ�������������½���p�ĸ��׽��f
		p = p->lchild;//��pָ��p����ڵ�
	} else if (!p->lchild) {
		p = p->rchild;
	}

	/*��p��ָ��������ҵ�f��Ӧ��λ��*/
	if (!f) {//��pΪ���ڵ�,Ҫɾ�����ڵ�
		T = p;
		/*��ʱû�о�����һ��if��qҪɾȥ�Ľ��(ԭp),fָ��q�ĸ��ڵ�*/
	} else if (q==f->lchild) {//��ʱɾȥ�����丸�׽��f����ڵ�
		//������е�������������ᵽ�丸�ڵ��������λ��
		f->lchild = p;
	} else if (q==f->rchild) {//��ʱɾȥ�����丸�׽��f���ҽڵ�
		//������е�������������ᵽ�丸�ڵ��������λ��
		f->rchild = p;
	}
	delete q;
}

void BalanceSortTree::MakeEmpty(BSTNode*& T)
{
	if (T) {//��TΪ����,ɾ������ڵ���ҽڵ�
		MakeEmpty(T->lchild);
		MakeEmpty(T->rchild);
		delete T;
		T = nullptr;
	} else {
		return;
	}
}

BalanceSortTree::BalanceSortTree()
{
	BSTree = nullptr;
}

BalanceSortTree::~BalanceSortTree()
{
	if (BSTree) {
		MakeEmpty();
	}
}

ElemType BalanceSortTree::SearchBST(KeyType key) const
{
	BSTNode* e = SearchBST(BSTree, key);
	return e->data;
}

void BalanceSortTree::InsertBST(ElemType e)
{
	InsertBST(BSTree, e);
}

void BalanceSortTree::CreateBST(ElemType e[], int num)
{
	for (int i = 1; i < num; i++) {
		InsertBST(BSTree, e[i]);
	}
}

void BalanceSortTree::DeleteBST(KeyType key)
{
	DeleteBST(BSTree, key);
}

void BalanceSortTree::MakeEmpty()
{
	MakeEmpty(BSTree);
}
