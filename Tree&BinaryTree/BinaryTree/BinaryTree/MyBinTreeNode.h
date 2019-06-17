#pragma once

template<typename Type> class MyBinTreeNode
{
	friend class MyBinTree;
private:
	MyBinTreeNode<Type> *leftChild, *rightChild;//该节点的左子树和右子树
	Type data;
public:
	//两种方式创建一个节点,创建空节点后自己设置数据左右和直接调用有参构造函数创建
	MyBinTreeNode();
	MyBinTreeNode(Type item, MyBinTreeNode<Type> *left = nullptr, MyBinTreeNode<Type> *right = nullptr);
	~MyBinTreeNode();

	Type GetData()const;//表示只读取数据成员,不改变
	MyBinTreeNode<Type> *GetLeft()const;//得到左子树的地址
	MyBinTreeNode<Type> *GetRight()const;//得到右子树的地址

	void SetData(const Type &item);
	void SetLeft(MyBinTreeNode<Type> *L);
	void SetRight(MyBinTreeNode<Type> *R);
};


