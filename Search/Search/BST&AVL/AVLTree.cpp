#include "AVLTree.h"

int AVLTree::InsertAVL(AVLNode*& tree, ElemType x, int& taller)
{
	int success;
	if (!tree) {//为空树,创建节点,用success判断节点是否创建成功
		tree = new AVLNode(x);
		success = tree ? 1 : 0;
		if (success) {
			taller = 1;//记录树是否是否有变长
		}
	} 
	else if (x.key < tree->data.key) {//新节点关键码小于当前节点
		success = InsertAVL(tree->left, x, taller);//递归创建
		if (taller) {//表示高度增加了
			switch (tree->balence) {//高度增加后重新计算平衡因子
				case -1://原本就是左子树比右子树高,现在左子树又增加1,左子树需要重新平衡(未确定方式)
					LeftBalance(tree, taller);//本函数包括了左旋和先左旋在右旋两种情况
					//取决于新加入的结点是在其左子树还是右子树,左则为左单旋,右则为先左后右
					break;
				case 0://原本是平衡的,现在其左子树增加了1,则平衡因子变为-1,仍然平衡
					tree->balence = -1;
					break;
				case 1://原本是左子树比柚子是高,现在右子树增加了1,则平衡因子变为0
					tree->balence = 0;
					taller = 0;
					break;
				default:
					assert(false);
			}
		}
	}
	else if (x.key > tree->data.key) {
		success = InsertAVL(tree->right, x, taller);
		if (taller) {
			switch (tree->balence) {
				case -1:
					tree->balence = 0;
					taller = 0;
					break;
				case 0://原本是平衡的,现在其右子树增加了1,则平衡因子变为1
					tree->balence = 1;
					break;
				case 1:
					RightBalance(tree, taller);
					break;
				default:
					assert(false);
			}
		}

	}
	return success;
}

void AVLTree::RotateLeft(AVLNode* Tree, AVLNode*& NewTree)
{
	/*左单旋情况:
		把根节点的左节点作为新的根节点
		把新的根节点的左节点作为原根节点的右节点
		把新的根节点的左节点设为原根节点
	*/
	NewTree = Tree->right;
	Tree->right = NewTree->left;
	NewTree->left = Tree;
}

void AVLTree::RotateRight(AVLNode* Tree, AVLNode*& NewTree)
{
	/*右单旋情况:
		把根节点节点的左节点作为新的根节点
		把新的根节点的右节点作为原根节点的左节点
		把新的根节点的右节点设为原根节点
	*/
	NewTree = Tree->left;
	Tree->left = NewTree->right;
	NewTree->right = Tree;
}

void AVLTree::LeftBalance(AVLNode*& Tree, int& taller)
{
	AVLNode* leftsub = Tree->left;//记录下当前根节点的左节点
	AVLNode* rightsub;
	switch (leftsub->balence) {//判断当前根节点的左子树是否平衡
		case -1://(根节点的左子树的)左子树大于右子树:向右单旋一次即可恢复平衡
			Tree->balence = leftsub->balence = 0;
			RotateRight(Tree, Tree);
			taller = 0;
			break;
		case 0:
			std::cout << "AVL tree remains." << std::endl;
			break;
		case 1://右子树大于左子树
			rightsub = leftsub->right;//指向左子树的右子树
			switch (rightsub->balence) {
				case -1://要先进行一次左旋在进行一次右旋
					Tree->balence = 1;//根节点变为新根节点的右节点,且平衡因子为1
					leftsub->balence = 0;//根节点的左节点仍然是新根节点的左节点,但平衡因子为0
					break;
				case 0:
					Tree->balence = leftsub->balence = 0;
					break;
				case 1:
					Tree->balence = 0;
					leftsub->balence = -1;
					break;
				default:
					assert(false);
			}
			rightsub->balence = 0;
			RotateLeft(leftsub, Tree->left);//将根节点的左子树进行一次左旋,使得根节点的左子树平衡
			//但此时根节点的平衡因子仍然为-2,需要把根节点进行一次右旋
			RotateRight(Tree, Tree);//再把根节点进行一次右旋
			taller = 0;
			break;
		default:
			assert(false);
	}
}

void AVLTree::RightBalance(AVLNode*& Tree, int& taller)
{
	AVLNode* rightsub = Tree->right;
	AVLNode* leftsub;
	switch (rightsub->balence) {
		case 1:
			Tree->balence = rightsub->balence = 0;
			RotateLeft(Tree, Tree);
			taller = 0;
			break;
		case 0:
			std::cout << "AVL tree remains." << std::endl;
		case -1:
			leftsub = rightsub->left;
			switch (leftsub->balence) {
				case 1:
					Tree->balence = -1;
					rightsub->balence = 0;
					break;
				case 0:
					Tree->balence = rightsub->balence = 0;
					break;
				case -1:
					Tree->balence = 0;
					rightsub->balence = 1;
					break;
				default:
					assert(false);
			}
			leftsub->balence = 0;
			RotateRight(rightsub, Tree->right);
			RotateLeft(Tree, Tree);
			taller = 0;
		default:
			assert(false);
	}
}

int AVLTree::DepthAVL(AVLNode* t) const
{
	if (t) {
		return 0;
	}
	int left = DepthAVL(t->left);
	int right = DepthAVL(t->right);

	return left > right ? left + 1 : right + 1;
}

AVLTree::AVLTree() :root(nullptr)
{
}

void AVLTree::InsertAVL(ElemType x)
{
	int taller;
	bool success = InsertAVL(root, x, taller);
	if (!success) {
		std::cout << "InsertAVL Fail !!!" << std::endl;
	}
}

int AVLTree::DepthAVL() const
{
	return DepthAVL(root);
}
