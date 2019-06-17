#pragma once

typedef int KeyType;
typedef char InfoType;
//定义了B树最多结点数
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

class BTNode
{
	friend class BTree;
private:
	int keyNum;//结点中关键字个数
	BTNode* parent;//指向双亲结点
	KeyType K[BTOrder + 1];//关键字,0未用
	BTNode* ptr[BTOrder + 1];//记录指针向量,0使用

	int Search(KeyType key)//未测试
	{
		int i;
		for (i = 1; i <= keyNum; ) {
			if (key < K[i]) {//小于,返回的是指针域的位置
				return i - 1;
			}
			else if (key > K[i]) {//大于,继续查找
				i++;
			}else{//等于,返回的是数据域的位置
				return i;
			}
		}
		return i - 1;//到最后也没一找到,返回最大指针域的位置
	}
};

