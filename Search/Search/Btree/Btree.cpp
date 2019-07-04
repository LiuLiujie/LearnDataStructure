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

/*
* 删除B-树上p节点的第i个关键字
*
* @param T B-树
* @param p 目标关键字所在节点
* @param i 关键字位序
*/
void BTree::DeleteBTree(BTNode*& T, BTNode*& p, int i)
{
	if (p->ptr[i] != nullptr) {
		//不是最下层的非终端结点
		Successor(p, i);//找到最下层的非终端结点的最小关键字代替它
		DeleteBTree(T, p, 1);//删除最下层非终端结点的最小关键字
	} else {
		Remove(p, i);//从结点中删除key[i]
		if (p->keyNum < (BTOrder - 1) / 2) {
			Restore(T, p);//调整B树
		}
	}
}

/*
* 在子树中找到最下层非终端结点的最小关键字代替要删除的结点
*
* @param p B-树结点
* @param i 关键字位序
*/
void BTree::Successor(BTNode*& p, int i)
{
	BTNode* leaf = p;
	if (!p) {
		return;
	}
	leaf = leaf->ptr[i];//leaf指向子树
	while (leaf->ptr[0]) {
		//找到最下层非终端结点
		leaf = leaf->ptr[0];
	}
	p->Key[i] = leaf->Key[1];
	p = leaf;
}

/*
* 从结点p移除关键字key[i]
* 
* @param p B-树结点
* @Param i 关键字位序
*/
void BTree::Remove(BTNode*& p, int i)
{
	int k;
	for (k = i; k < p->keyNum; k++) {
		//将指针和key全部前移
		p->Key[k] = p->Key[k + 1];
		p->ptr[k] = p->ptr[k + 1];
	}
	(p->keyNum)--;
}

/*
* 调整B-树
*
* @param T B-树
* @param p B-树结点
*/
void BTree::Restore(BTNode*& T, BTNode*& p)
{
	//保存被删结点的父,左右兄弟结点
	BTNode* parent = nullptr, * leftBrother = nullptr, * rightBrother = nullptr;
	parent = p->parent;
	if (parent) {
		//当父结点不为空的情况下寻找左右兄弟
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
		//左右兄弟有富余的关键字
		if ((leftBrother && leftBrother->keyNum >= (BTOrder + 1) / 2) ||
			(rightBrother && rightBrother->keyNum >= (BTOrder + 1) / 2)) {
			BorrowFromBrother(p, leftBrother, rightBrother, parent, i);
		} else {//左右结点都没有富余关键字,需要合并
			if (leftBrother) {
				MergeWithLeftBrother(leftBrother, parent, p, T, i);
			} else if (rightBrother) {
				MergeWithRightBrother(rightBrother, parent, p, T, i);
			} else {
				//左右子树均不存在,改变根节点
				for (int j = 0; j <= p->keyNum + 1; j++) {
					if (p->ptr[j]) {
						T = p->ptr[j];
						break;
					}
				}
			}
		}
	} else {
		//父结点为空,即p为根节点,去掉根节点使树减一层
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
* 向兄弟结点借关键字
*
* @param p B-树结点
* @param leftBrother p结点的左兄弟结点
* @param rightBrother p结点的右兄弟结点
* @param parent p结点的双亲节点
* @param i 位序
*/
void BTree::BorrowFromBrother(BTNode*& p, BTNode*& leftBrother, BTNode*& rightBrother, BTNode*& parent, int& i)
{
	//左兄弟有富余关键字,向左兄弟借
	if (leftBrother && leftBrother->keyNum >= (BTOrder + 1) / 2) {
		for (int j = p->keyNum + 1; j > 0; j--) {
			//关键字与指针向后移动,腾出第一个位置
			if (j > 1) {
				p->Key[j] = p->Key[j - 1];//关键字无0位,故少一个
			}
			p->ptr[j] = p->ptr[j - 1];
		}
		p->ptr[0] = leftBrother->ptr[leftBrother->keyNum];//借子节点
		if (p->ptr[0]) {
			p->ptr[0]->parent = p;//将借来的子节点指向双亲节点p
		}
		p->Key[1] = parent->Key[i];//被删结点存父结点的关键字
		parent->Key[i] = leftBrother->Key[leftBrother->keyNum];//父结点的key变为被删结点左兄弟的最大关键字
		(leftBrother->keyNum)--;
		(p->keyNum)++;
	} else if (rightBrother && rightBrother->keyNum >= (BTOrder + 1) / 2) {
		//右兄弟有富余关键字,向右兄弟借
		p->Key[p->keyNum + 1] = parent->Key[i + 1];
		p->ptr[p->keyNum + 1] = rightBrother->ptr[0];//子树指针指向右兄弟最左边的子树指针
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
* 与左兄弟合并
*
* @param leftBrother p结点的左兄弟结点
* @param parent p结点的父亲结点
* @param p B-树结点
* @param T B-树
* @param i 位序
*/
void BTree::MergeWithLeftBrother(BTNode*& leftBrother, BTNode*& parent, BTNode*& p, BTNode*& T, int& i)
{
	//与做兄弟合并
	leftBrother->Key[leftBrother->keyNum + 1] = parent->Key[i];//从父节点分割本节点与左兄弟的关键字
	leftBrother->ptr[leftBrother->keyNum + 1] = p->ptr[0];
	if (leftBrother->ptr[leftBrother->keyNum + 1]) {
		//给左兄弟的结点,当次结点存在时需要把其父亲指向左节点
		leftBrother->ptr[leftBrother->keyNum + 1]->parent = leftBrother;
	}
	(leftBrother->keyNum)++;
	for (int j = 0; j <= p->keyNum; j++) {
		//把本节点的关键字和子树指针赋给左兄弟
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
		//左移
		parent->Key[j] = parent->Key[j + 1];//可能有bug,指针数比关键字多一个,下面的和右合并则考虑了这个问题
		parent->ptr[j] = parent->ptr[j + 1];
	}
	parent->ptr[parent->keyNum] = nullptr;
	(parent->keyNum)--;
	if (T == parent) {
		//如果此时父结点为根,则当父结点没有关键字时才调整
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
		//如果父结点不为根,则需要判断是否重新调整
		if (parent->keyNum < (BTOrder - 1) / 2) {
			Restore(T, parent);
		}
	}
}

/*
* 与右兄弟合并
*
* @param leftBrother p结点的右兄弟结点
* @param parent p结点的父亲结点
* @param p B-树结点
* @param T B-树
* @param i 位序
*/
void BTree::MergeWithRightBrother(BTNode*& rightBrother, BTNode*& parent, BTNode*& p, BTNode*& T, int& i)
{
	//与右兄弟合并
	for (int j = (rightBrother->keyNum); j > 0; j--) {
		if (j > 0) {
			rightBrother->Key[j + 1 + p->keyNum] = rightBrother->Key[j];
		}
		rightBrother->ptr[j + 1 + p->keyNum] = rightBrother->ptr[j];
	}
	rightBrother->Key[p->keyNum + 1] = parent->Key[i + 1];//把父结点的分割两个本兄弟和右兄弟的关键字拿下来使用
	for (int j = 0; j <= p->keyNum; j++) {
		//把本节点的关键字即子树指针移到右兄弟中去
		if (j > 0) {
			rightBrother->Key[j] = p->Key[j];
		}
		rightBrother->ptr[j] = p->ptr[j];
		if (rightBrother->ptr[j]) {
			rightBrother->ptr[j]->parent = rightBrother;//调整移过去的结点的父结点为右兄弟
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
		//如果父结点在关键字减少之前只有一个结点,那么需要把父结点的右孩子赋给左孩子
		parent->ptr[0] = parent->ptr[1];
	}
	parent->ptr[parent->keyNum] = nullptr;
	(parent->keyNum)--;
	if (T == parent) {
		//吐过此时父结点为根,则当父结点没有关键字时才调整
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
		//如果父结点不为根,则需要判断是否需要重新调整
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
