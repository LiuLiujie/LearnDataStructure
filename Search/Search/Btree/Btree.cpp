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
	BTNode* p = T, * q = nullptr;//p指向待查结点,q指向p的双亲
	bool found = false;
	int i = 0;
	while (p && !found) {
		i = p->Search(key);//在本节点查找
		if (i <= p->keyNum && p->Key[i] == key) {//在本节点找到了
			found = true;
		} else {//在本节点未找到,去下一个结点找
			q = p;
			p = p->ptr[i-1];
		}
	}
	if (found) {
		return Result{ p, i, 1 };//查找成功,返回待查结点
	} else {
		return Result{ q, i, 0 };//查找失败,返回应该插入该key的位置(便于后续插入)
	}
}

/*在Key[i-1]和Key[i]之间插入关键字key*/
void BTree::InsertBTree(BTNode*& T, KeyType key, BTNode* q, int i)
{
	KeyType x;//指向需要插入的元素,一开始指向key,后来指向需要提上双亲节点的元素
	int s;//存储中位数,用于分裂
	bool finished = false;
	bool needNewRoot = false;
	BTNode* ap;//指向新节点的指针
	if (!q) {//q为空,说明是一个空的B-树,需要创建
		NewRoot(T, key);
	}else{
		x = key;
		ap = nullptr;
		while (!needNewRoot && !finished)
		{
			Insert(q, key, ap, i);//插入新元素
			if (q->keyNum < BTOrder) {//检查结点元素个数是否超出
				finished = true;
			}else {//分裂结点
				s = (BTOrder + 1) / 2;
				Split(q, ap, s);
				x = q->Key[s];//x指向中间要提到双亲节点的元素
				if (q->parent) {//若其双亲节点不为空,则找到正确位置插入
					q = q->parent;
					i = q->Search(x);//在q中查找要插入的位置,继续执行while循环插入元素
				}else{
					needNewRoot = true;
				}
			}
		}
		//这里可能有Bug,当根节点的子树不为p和ap指向的两棵,而是三个子树怎么办
		if (needNewRoot){//上提后需要创建一个新的根节点,由q和ap存储原来的结点,T创建为新节点,
			NewRoot(T, x, q, ap);
		}
	}
}

/*生成一个新的根节点*/
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

/*在q->Key[i]和q->Key[i+1]之间插入key*/
void BTree::Insert(BTNode*& q, KeyType key, BTNode* ap, int i)
{
	int j;
	int n = q->keyNum;
	for (j = n; j >= i; j--)//后移
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

/*将结点分裂,前一半保留在原节点,后一半移入ap所指向的新节点*/
void BTree::Split(BTNode*& q, BTNode*& ap, int s)
{
	int i, j;
	int n = q->keyNum;//关键字数量
	ap = new BTNode;
	ap->ptr[0] = q->ptr[s];//移入n-s个数据域和n-s+1个指针域
	for (i = s + 1, j = 1; i <= n; i++, j++)
	{
		ap->Key[j] = q->Key[i];
		ap->ptr[j] = q->ptr[i];
	}
	ap->keyNum = n - s;
	ap->parent = q->parent;
	for ( i = 0; i <= ap->keyNum; i++)//修改新节点ap的子节点的父节点
	{
		if (ap->ptr[i])
		{
			ap->ptr[i]->parent = ap;
		}
	}
	q->keyNum = s - 1;//这里的个数是把一个结点提到双亲位置后的个数,提取过程在主调函数中
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
	if (res.tag == 0)//即查找失败,此时res中返回的是应该插入的结点
	{
		InsertBTree(root, key, res.pt, res.i);
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
