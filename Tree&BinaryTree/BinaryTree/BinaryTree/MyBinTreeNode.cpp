#pragma once

template<typename Type> 
class MyBinTreeNode
{
	friend class MyBinTree;
private:
	MyBinTreeNode<Type>* leftChild, * rightChild;//该节点的左子树和右子树
	Type data;
public:
	//两种方式创建一个节点,创建空节点后自己设置数据左右和直接调用有参构造函数创建
	MyBinTreeNode();
	MyBinTreeNode(Type item, MyBinTreeNode<Type>* left = nullptr, MyBinTreeNode<Type>* right = nullptr);
	~MyBinTreeNode();

	Type GetData()const;//表示只读取数据成员,不改变
	MyBinTreeNode<Type>* GetLeft()const;//得到左子树的地址
	MyBinTreeNode<Type>* GetRight()const;//得到右子树的地址

	void SetData(const Type& item);
	void SetLeft(MyBinTreeNode<Type>* L);
	void SetRight(MyBinTreeNode<Type>* R);
};

template<typename Type>
MyBinTreeNode<Type>::MyBinTreeNode()
{
	leftChild(nullptr), rightChild(nullptr);
}

template<typename Type>
MyBinTreeNode<Type>::MyBinTreeNode
(Type item, MyBinTreeNode<Type> *left, MyBinTreeNode<Type> *right)//默认参数只声明一次
{
	data = item;
	leftChild = left;
	rightChild = right;
}

template<typename Type>
MyBinTreeNode<Type>::~MyBinTreeNode()
{
	delete *leftChild;
	delegate *rightChild
}

template<typename Type>
Type MyBinTreeNode<Type>::GetData() const
{
	return data;
}

template<typename Type>
MyBinTreeNode<Type>* MyBinTreeNode<Type>::GetLeft() const
{
	return leftChild;
}

template<typename Type>
MyBinTreeNode<Type>* MyBinTreeNode<Type>::GetRight() const
{
	return rightChild;
}

template<typename Type>
void MyBinTreeNode<Type>::SetData(const Type & item)
{
	data = item;
}

template<typename Type>
void MyBinTreeNode<Type>::SetLeft(MyBinTreeNode<Type>* L)
{
	leftChild = L;
}

template<typename Type>
void MyBinTreeNode<Type>::SetRight(MyBinTreeNode<Type>* R)
{
	rightChild = R;
}
