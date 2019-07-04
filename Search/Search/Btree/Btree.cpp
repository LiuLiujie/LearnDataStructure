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

/*
* ɾ��B-����p�ڵ�ĵ�i���ؼ���
*
* @param T B-��
* @param p Ŀ��ؼ������ڽڵ�
* @param i �ؼ���λ��
*/
void BTree::DeleteBTree(BTNode*& T, BTNode*& p, int i)
{
	if (p->ptr[i] != nullptr) {
		//�������²�ķ��ն˽��
		Successor(p, i);//�ҵ����²�ķ��ն˽�����С�ؼ��ִ�����
		DeleteBTree(T, p, 1);//ɾ�����²���ն˽�����С�ؼ���
	} else {
		Remove(p, i);//�ӽ����ɾ��key[i]
		if (p->keyNum < (BTOrder - 1) / 2) {
			Restore(T, p);//����B��
		}
	}
}

/*
* ���������ҵ����²���ն˽�����С�ؼ��ִ���Ҫɾ���Ľ��
*
* @param p B-�����
* @param i �ؼ���λ��
*/
void BTree::Successor(BTNode*& p, int i)
{
	BTNode* leaf = p;
	if (!p) {
		return;
	}
	leaf = leaf->ptr[i];//leafָ������
	while (leaf->ptr[0]) {
		//�ҵ����²���ն˽��
		leaf = leaf->ptr[0];
	}
	p->Key[i] = leaf->Key[1];
	p = leaf;
}

/*
* �ӽ��p�Ƴ��ؼ���key[i]
* 
* @param p B-�����
* @Param i �ؼ���λ��
*/
void BTree::Remove(BTNode*& p, int i)
{
	int k;
	for (k = i; k < p->keyNum; k++) {
		//��ָ���keyȫ��ǰ��
		p->Key[k] = p->Key[k + 1];
		p->ptr[k] = p->ptr[k + 1];
	}
	(p->keyNum)--;
}

/*
* ����B-��
*
* @param T B-��
* @param p B-�����
*/
void BTree::Restore(BTNode*& T, BTNode*& p)
{
	//���汻ɾ���ĸ�,�����ֵܽ��
	BTNode* parent = nullptr, * leftBrother = nullptr, * rightBrother = nullptr;
	parent = p->parent;
	if (parent) {
		//������㲻Ϊ�յ������Ѱ�������ֵ�
		int i;
		for (i = 0; i <= parent->keyNum; i++) {
			if (parent->ptr[i] == p) {
				break;
			}
		}
		if (i > 0) {
			leftBrother = parent->ptr[i - 1];
		}
		if (i < parent->keyNum) {
			rightBrother = parent->ptr[i + 1];
		}
		//�����ֵ��и���Ĺؼ���
		if ((leftBrother && leftBrother->keyNum >= (BTOrder + 1) / 2) ||
			(rightBrother && rightBrother->keyNum >= (BTOrder + 1) / 2)) {
			BorrowFromBrother(p, leftBrother, rightBrother, parent, i);
		} else {//���ҽ�㶼û�и���ؼ���,��Ҫ�ϲ�
			if (leftBrother) {
				MergeWithLeftBrother(leftBrother, parent, p, T, i);
			} else if (rightBrother) {
				MergeWithRightBrother(rightBrother, parent, p, T, i);
			} else {
				//����������������,�ı���ڵ�
				for (int j = 0; j <= p->keyNum + 1; j++) {
					if (p->ptr[j]) {
						T = p->ptr[j];
						break;
					}
				}
			}
		}
	} else {
		//�����Ϊ��,��pΪ���ڵ�,ȥ�����ڵ�ʹ����һ��
		BTNode* a = nullptr;
		for (int j = 0; j <= p->keyNum + 1; j++) {
			if (p->ptr[j]) {
				a = p;
				p = p->ptr[j];
				a->ptr[j] = nullptr;
				delete a;
				break;
			}
		}
		T = p;
		T->parent = nullptr;
	}
}

/*
* ���ֵܽ���ؼ���
*
* @param p B-�����
* @param leftBrother p�������ֵܽ��
* @param rightBrother p�������ֵܽ��
* @param parent p����˫�׽ڵ�
* @param i λ��
*/
void BTree::BorrowFromBrother(BTNode*& p, BTNode*& leftBrother, BTNode*& rightBrother, BTNode*& parent, int& i)
{
	//���ֵ��и���ؼ���,�����ֵܽ�
	if (leftBrother && leftBrother->keyNum >= (BTOrder + 1) / 2) {
		for (int j = p->keyNum + 1; j > 0; j--) {
			//�ؼ�����ָ������ƶ�,�ڳ���һ��λ��
			if (j > 1) {
				p->Key[j] = p->Key[j - 1];//�ؼ�����0λ,����һ��
			}
			p->ptr[j] = p->ptr[j - 1];
		}
		p->ptr[0] = leftBrother->ptr[leftBrother->keyNum];//���ӽڵ�
		if (p->ptr[0]) {
			p->ptr[0]->parent = p;//���������ӽڵ�ָ��˫�׽ڵ�p
		}
		p->Key[1] = parent->Key[i];//��ɾ���游���Ĺؼ���
		parent->Key[i] = leftBrother->Key[leftBrother->keyNum];//������key��Ϊ��ɾ������ֵܵ����ؼ���
		(leftBrother->keyNum)--;
		(p->keyNum)++;
	} else if (rightBrother && rightBrother->keyNum >= (BTOrder + 1) / 2) {
		//���ֵ��и���ؼ���,�����ֵܽ�
		p->Key[p->keyNum + 1] = parent->Key[i + 1];
		p->ptr[p->keyNum + 1] = rightBrother->ptr[0];//����ָ��ָ�����ֵ�����ߵ�����ָ��
		if (p->ptr[p->keyNum + 1]) {
			p->ptr[p->keyNum + 1]->parent = p;
		}
		(p->keyNum)++;
		parent->Key[i + 1] = rightBrother->Key[1];
		for (int j = 0; j < rightBrother->keyNum; j++) {
			if (j > 0) {
				rightBrother->Key[j] = rightBrother->Key[j + 1];
			}
			rightBrother->ptr[j] = rightBrother->ptr[j + 1];
		}
		rightBrother->ptr[rightBrother->keyNum] = nullptr;
		(rightBrother->keyNum)--;
	}
}
/*
* �����ֵܺϲ�
*
* @param leftBrother p�������ֵܽ��
* @param parent p���ĸ��׽��
* @param p B-�����
* @param T B-��
* @param i λ��
*/
void BTree::MergeWithLeftBrother(BTNode*& leftBrother, BTNode*& parent, BTNode*& p, BTNode*& T, int& i)
{
	//�����ֵܺϲ�
	leftBrother->Key[leftBrother->keyNum + 1] = parent->Key[i];//�Ӹ��ڵ�ָ�ڵ������ֵܵĹؼ���
	leftBrother->ptr[leftBrother->keyNum + 1] = p->ptr[0];
	if (leftBrother->ptr[leftBrother->keyNum + 1]) {
		//�����ֵܵĽ��,���ν�����ʱ��Ҫ���丸��ָ����ڵ�
		leftBrother->ptr[leftBrother->keyNum + 1]->parent = leftBrother;
	}
	(leftBrother->keyNum)++;
	for (int j = 0; j <= p->keyNum; j++) {
		//�ѱ��ڵ�Ĺؼ��ֺ�����ָ�븳�����ֵ�
		leftBrother->Key[leftBrother->keyNum + j] = p->Key[j];
		leftBrother->ptr[leftBrother->keyNum + j] = p->ptr[j];
		if (leftBrother->ptr[leftBrother->keyNum + j]) {
			leftBrother->ptr[leftBrother->keyNum + j]->parent = leftBrother;
		}
	}
	leftBrother->keyNum += p->keyNum;
	parent->ptr[i] = nullptr;
	delete p;
	for (int j = i; j < parent->keyNum; j++) {
		//����
		parent->Key[j] = parent->Key[j + 1];//������bug,ָ�����ȹؼ��ֶ�һ��,����ĺ��Һϲ��������������
		parent->ptr[j] = parent->ptr[j + 1];
	}
	parent->ptr[parent->keyNum] = nullptr;
	(parent->keyNum)--;
	if (T == parent) {
		//�����ʱ�����Ϊ��,�򵱸����û�йؼ���ʱ�ŵ���
		if (parent->keyNum == 0) {
			for (int j = 0; j <= parent->keyNum + 1; j++) {
				if (parent->ptr[j]) {
					T = parent->ptr[j];
					break;
				}
				T->parent = nullptr;
			}
		}
	} else {
		//�������㲻Ϊ��,����Ҫ�ж��Ƿ����µ���
		if (parent->keyNum < (BTOrder - 1) / 2) {
			Restore(T, parent);
		}
	}
}

/*
* �����ֵܺϲ�
*
* @param leftBrother p�������ֵܽ��
* @param parent p���ĸ��׽��
* @param p B-�����
* @param T B-��
* @param i λ��
*/
void BTree::MergeWithRightBrother(BTNode*& rightBrother, BTNode*& parent, BTNode*& p, BTNode*& T, int& i)
{
	//�����ֵܺϲ�
	for (int j = (rightBrother->keyNum); j > 0; j--) {
		if (j > 0) {
			rightBrother->Key[j + 1 + p->keyNum] = rightBrother->Key[j];
		}
		rightBrother->ptr[j + 1 + p->keyNum] = rightBrother->ptr[j];
	}
	rightBrother->Key[p->keyNum + 1] = parent->Key[i + 1];//�Ѹ����ķָ��������ֵܺ����ֵܵĹؼ���������ʹ��
	for (int j = 0; j <= p->keyNum; j++) {
		//�ѱ��ڵ�Ĺؼ��ּ�����ָ���Ƶ����ֵ���ȥ
		if (j > 0) {
			rightBrother->Key[j] = p->Key[j];
		}
		rightBrother->ptr[j] = p->ptr[j];
		if (rightBrother->ptr[j]) {
			rightBrother->ptr[j]->parent = rightBrother;//�����ƹ�ȥ�Ľ��ĸ����Ϊ���ֵ�
		}
	}
	rightBrother->keyNum += (p->keyNum + 1);
	parent->ptr[i] = nullptr;
	delete p;
	for (int j = i; j < parent->keyNum; j++) {
		if (j > i) {
			parent->Key[j] = parent->Key[j + 1];
		}
		parent->ptr[j] = parent->ptr[j + 1];
	}
	if (parent->keyNum == 1) {
		//���������ڹؼ��ּ���֮ǰֻ��һ�����,��ô��Ҫ�Ѹ������Һ��Ӹ�������
		parent->ptr[0] = parent->ptr[1];
	}
	parent->ptr[parent->keyNum] = nullptr;
	(parent->keyNum)--;
	if (T == parent) {
		//�¹���ʱ�����Ϊ��,�򵱸����û�йؼ���ʱ�ŵ���
		if (parent->keyNum == 0) {
			for (int j = 0; j <= parent->keyNum + 1; j++) {
				if (parent->ptr[j]) {
					T = parent->ptr[j];
					break;
				}
			}
			T->parent = nullptr;
		}
	} else {
		//�������㲻Ϊ��,����Ҫ�ж��Ƿ���Ҫ���µ���
		if (parent->keyNum < (BTOrder - 1) / 2) {
			Restore(T, parent);
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
