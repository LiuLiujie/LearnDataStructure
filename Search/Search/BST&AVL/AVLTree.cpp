#include "AVLTree.h"

int AVLTree::InsertAVL(AVLNode*& tree, ElemType x, int& taller)
{
	int success;
	if (!tree) {//Ϊ����,�����ڵ�,��success�жϽڵ��Ƿ񴴽��ɹ�
		tree = new AVLNode(x);
		success = tree ? 1 : 0;
		if (success) {
			taller = 1;//��¼���Ƿ��Ƿ��б䳤
		}
	} 
	else if (x.key < tree->data.key) {//�½ڵ�ؼ���С�ڵ�ǰ�ڵ�
		success = InsertAVL(tree->left, x, taller);//�ݹ鴴��
		if (taller) {//��ʾ�߶�������
			switch (tree->balence) {//�߶����Ӻ����¼���ƽ������
				case -1://ԭ����������������������,����������������1,��������Ҫ����ƽ��(δȷ����ʽ)
					LeftBalance(tree, taller);//�������������������������������������
					//ȡ�����¼���Ľ������������������������,����Ϊ����,����Ϊ�������
					break;
				case 0://ԭ����ƽ���,������������������1,��ƽ�����ӱ�Ϊ-1,��Ȼƽ��
					tree->balence = -1;
					break;
				case 1://ԭ�����������������Ǹ�,����������������1,��ƽ�����ӱ�Ϊ0
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
				case 0://ԭ����ƽ���,������������������1,��ƽ�����ӱ�Ϊ1
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
	/*�������:
		�Ѹ��ڵ����ڵ���Ϊ�µĸ��ڵ�
		���µĸ��ڵ����ڵ���Ϊԭ���ڵ���ҽڵ�
		���µĸ��ڵ����ڵ���Ϊԭ���ڵ�
	*/
	NewTree = Tree->right;
	Tree->right = NewTree->left;
	NewTree->left = Tree;
}

void AVLTree::RotateRight(AVLNode* Tree, AVLNode*& NewTree)
{
	/*�ҵ������:
		�Ѹ��ڵ�ڵ����ڵ���Ϊ�µĸ��ڵ�
		���µĸ��ڵ���ҽڵ���Ϊԭ���ڵ����ڵ�
		���µĸ��ڵ���ҽڵ���Ϊԭ���ڵ�
	*/
	NewTree = Tree->left;
	Tree->left = NewTree->right;
	NewTree->right = Tree;
}

void AVLTree::LeftBalance(AVLNode*& Tree, int& taller)
{
	AVLNode* leftsub = Tree->left;//��¼�µ�ǰ���ڵ����ڵ�
	AVLNode* rightsub;
	switch (leftsub->balence) {//�жϵ�ǰ���ڵ���������Ƿ�ƽ��
		case -1://(���ڵ����������)����������������:���ҵ���һ�μ��ɻָ�ƽ��
			Tree->balence = leftsub->balence = 0;
			RotateRight(Tree, Tree);
			taller = 0;
			break;
		case 0:
			std::cout << "AVL tree remains." << std::endl;
			break;
		case 1://����������������
			rightsub = leftsub->right;//ָ����������������
			switch (rightsub->balence) {
				case -1://Ҫ�Ƚ���һ�������ڽ���һ������
					Tree->balence = 1;//���ڵ��Ϊ�¸��ڵ���ҽڵ�,��ƽ������Ϊ1
					leftsub->balence = 0;//���ڵ����ڵ���Ȼ���¸��ڵ����ڵ�,��ƽ������Ϊ0
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
			RotateLeft(leftsub, Tree->left);//�����ڵ������������һ������,ʹ�ø��ڵ��������ƽ��
			//����ʱ���ڵ��ƽ��������ȻΪ-2,��Ҫ�Ѹ��ڵ����һ������
			RotateRight(Tree, Tree);//�ٰѸ��ڵ����һ������
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
