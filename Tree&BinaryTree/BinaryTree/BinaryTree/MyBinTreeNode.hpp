#include "MyBinTreeNode.h"

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
