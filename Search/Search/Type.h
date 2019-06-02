#pragma once

typedef int KeyType;
typedef char InfoType;
#define BTOrder 3
struct ElemType {
	KeyType key;//关键字域
	InfoType otherInfo;//其他域
};

struct SSTable {
	ElemType* R;//存储空间基地址
	int length;//当前长度
};

struct BSTNode {
	ElemType data;
	BSTNode* lchild, * rchild;
};

class AVLNode
{
	friend class AVLTree;
public:
	ElemType data;
	AVLNode* left, * right;
	int balence;//平衡因子:右子树深度-左子树深度(初始化均为0)
	AVLNode() :left(nullptr), right(nullptr), balence(0) {};
	AVLNode(ElemType d, AVLNode* l = nullptr, AVLNode* r = nullptr)
		:data(d), left(l), right(r), balence(0) {};
	~AVLNode() {};
};

/*B树*/
struct Result
{
	BTNode* pt;//指向找到的结点
	int i;//在节点中的关键字序号,1~m
	int tag;//1表示查找成功,0表示失败
};
struct BTNode
{
	int keyNum;//结点中关键字个数
	BTNode* parent;//指向双亲结点
	KeyType K[BTOrder + 1];//关键字,0未用
	BTNode* ptr[BTOrder + 1];//记录指针向量
};

