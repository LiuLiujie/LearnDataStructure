#include "BalanceSortTree.h"

BSTNode* BalanceSortTree::SearchBST(BSTNode* T, KeyType key) const
{
	/*二叉排序树的递归查找:
		在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素
		若key小于节点T的key,则查找左子树,若大于则查找右子树
		若查找成功,则返回指向该数据元素节点的指针,否则返回空指针
	*/
	if ((!T) || key==T->data.key) {//这里隐藏了T为空时返回空指针
		return T;
	} else if (key < T->data.key) {
		return SearchBST(T->lchild, key);
	} else {
		return SearchBST(T->rchild, key);
	}
}

void BalanceSortTree::InsertBST(BSTNode*& T, ElemType e)
{
	/*二叉排序树的插入
		如果为空树,则将节点S作为根节点插入
		如果不为空时,则将key与节点的key进行比较,
		如果小于节点,则插入左子树,如果大于节点,插入右子树(本树不允许数据相同)
	*/
	if (!T) {//T为空时,创建节点
		BSTNode* S = new BSTNode;
		S->data = e;
		S->lchild = S->rchild = nullptr;
		T = S;
	} else if (e.key<T->data.key) {//如果
		InsertBST(T->lchild, e);
	} else if (e.key>T->data.key) {
		InsertBST(T->rchild, e);
	}
}


void BalanceSortTree::DeleteBST(BSTNode*& T, KeyType key)
{
	/*从根查找关键字等于key的结点*/
	BSTNode* p = T, * f = nullptr;
	while (p) {
		if (p->data.key == key) {
			break;
		}
		f = p;//f指向p的上父结点
		if (p->data.key > key) {
			p = p->lchild;
		} else {
			p = p->rchild;
		
		}
	}
	if (!p) {
		return;
	}

	/*考虑三种情况:p左右子树均不为空, 无右子树, 无左子树*/
	BSTNode* q = p;
	if ((p->lchild) && (p->rchild)) {//左右均不空
		BSTNode* s = p->lchild;//用s找到p的左子树中序遍历最后一个结点,q指向这最后一个结点父节点
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;//把s结点提上p的位置
		if (q!=p) {
			q->rchild = s->lchild;//重新接上q的右子树,即如果s是叶子结点,则q指空,若s只有左节点,则q右指向s左
		} else {//p==q情况,即要提上来的s就是p的左子树,则s一定也只有左子树,提上来成为p的左子树即可
			p->lchild = s->lchild;
		}
		delete s;//删除被提上的结点
		return;
	} else if (!p->rchild) {//p没有右子树,只需要将其左子树重新接入p的父亲结点f
		p = p->lchild;//把p指向p的左节点
	} else if (!p->lchild) {
		p = p->rchild;
	}

	/*将p所指向的子树挂到f相应的位置*/
	if (!f) {//即p为根节点,要删除根节点
		T = p;
		/*此时没有经过第一个if的q要删去的结点(原p),f指向q的父节点*/
	} else if (q==f->lchild) {//此时删去的是其父亲结点f的左节点
		//将其仅有的左或者右子树提到其父节点的左子树位置
		f->lchild = p;
	} else if (q==f->rchild) {//此时删去的是其父亲结点f的右节点
		//将其仅有的左或者右子树提到其父节点的右子树位置
		f->rchild = p;
	}
	delete q;
}

void BalanceSortTree::MakeEmpty(BSTNode*& T)
{
	if (T) {//即T为不空,删除其左节点和右节点
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
