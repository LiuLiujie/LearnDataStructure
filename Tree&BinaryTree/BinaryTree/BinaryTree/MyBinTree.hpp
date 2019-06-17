#pragma once
#include <iostream>
#include <vector>
#include "MyBinTreeNode.hpp"

template<typename Type> 
class MyBinTree
{
public:
	MyBinTree();
	MyBinTree(std::vector<Type> _refValue[], Type _stop, int order = 0);
	~MyBinTree();

	bool isEmpty();//判断是否为空树

	MyBinTreeNode<Type>* Parent(MyBinTreeNode<Type>* current);//返回父节点
	MyBinTreeNode<Type>* LeftChild(MyBinTreeNode<Type>* current);//返回左子树
	MyBinTreeNode<Type>* rightChild(MyBinTreeNode<Type>* current);//返回右子树

	int Find(const Type& item);
	const MyBinTreeNode<Type>* Getroot()const;
	int GetSize(const MyBinTreeNode<Type>* t = root)const;
	int GetDepth(const MyBinTreeNode<Type>* t = root)const;

	void InOrderCout();
	void PreOrderCout();
	void PostOrderCout();

	void Destroy();

private:
	MyBinTreeNode<Type>* root;
	std::vector<Type> RefValue;
	Type Stop;
	int createOrder;//0:先序,1中序,2后序

	MyBinTreeNode<Type>* Parent(MyBinTreeNode<Type>* start, MyBinTreeNode<Type>* current);

	void PreOrderCreate(MyBinTreeNode<Type>* current, int pos);
	void InOrderCreate();
	void PostOrderCreate();

	void PreOrderCout(MyBinTreeNode<Type>* current)const;
	void InOrderCout(MyBinTreeNode<Type>* current)const;
	void PostOrderCout(MyBinTreeNode<Type>* current)const;

	void Destroy(MyBinTreeNode* current);
};

template<typename Type>
MyBinTree<Type>::MyBinTree()
{
	root = nullptr;
}

template<typename Type>
MyBinTree<Type>::MyBinTree(std::vector<Type> _refValue[], Type _stop, int order)
{
	root = nullptr;
	RefValue = _refValue;
	Stop = _stop;
	//按照顺序创建二叉树
	if (order == 0){
		PreOrderCreate();
	}else if (order = 1){
		InOrderCreate();
	}else {
		PostOrderCreate();
	}
}

template<typename Type>
MyBinTree<Type>::~MyBinTree()
{
	delete root;
}

template<typename Type>
bool MyBinTree<Type>::isEmpty()
{
	return root == nullptr ? true : false;
}

template<typename Type>
MyBinTreeNode<Type>* MyBinTree<Type>::Parent(MyBinTreeNode<Type>* current)
{
	return root == nullptr || root == current ? nullptr : Parent(root, current);
}

template<typename Type>
MyBinTreeNode<Type>* MyBinTree<Type>::LeftChild(MyBinTreeNode<Type>* current)
{
	return root != nullptr ? current->leftChild : nullptr;
}

template<typename Type>
MyBinTreeNode<Type>* MyBinTree<Type>::rightChild(MyBinTreeNode<Type>* current)
{
	return root != nullptr ? current->rightChild : nullptr;
}

template<typename Type>
const MyBinTreeNode<Type>* MyBinTree<Type>::Getroot() const
{
	return root;
}

template<typename Type>
int MyBinTree<Type>::GetSize(const MyBinTreeNode<Type>* t) const
{
	if (t == nullptr){
		return 0;
	}else {
		return 1 + GetSize(t->leftChild) + GetSize(t->rightChild);
	}
}

template<typename Type>
int MyBinTree<Type>::GetDepth(const MyBinTreeNode<Type>* t) const
{
	if (t == nullptr){
		return 0;
	}else {
		int LNum = GetDepth(t->leftChild);
		int RNum = GetDepth(t->rightChild);
		return 1 + (LNum > RNum ? LNum : RNum);
	}
}

template<typename Type>
void MyBinTree<Type>::InOrderCout()
{
	InOrderCout(root);
}

template<typename Type>
void MyBinTree<Type>::PreOrderCout()
{
	PreOrderCout(root);
}

template<typename Type>
void MyBinTree<Type>::PostOrderCout()
{
	PostOrderCout(root);
}

template<typename Type>
void MyBinTree<Type>::Destroy()
{
	Destroy(root);
}

template<typename Type>
void MyBinTree<Type>::PreOrderCreate(MyBinTreeNode<Type> *current,int pos)
{

	if (RefValue.get(pos) == stop) {//无法判断两个模板是否完全相同,使用伪代码,只可判断一个
		current = nullptr;
	}else {
		current = new MyBinTreeNode(RefValue.get(pos));
		PreOrderCreate(current->leftChild, 2 * pos);
		PreOrderCreate(current->rightChild, 2 * pos + 1);
	}

}

template<typename Type>
void MyBinTree<Type>::PreOrderCout(MyBinTreeNode<Type>* current) const
{
	if (current != nullptr)
	{
		cout << current->data<<" ";
		PreOrderCout(current->leftChild);
		PreOrderCout(current->rightChild);
	}
}

template<typename Type>
void MyBinTree<Type>::InOrderCout(MyBinTreeNode<Type>* current) const
{
	if (current != nullptr)
	{
		InOrderCout(current->leftChild);
		std::cout << current->data<<" ";
		InOrderCout(current->rightChild);
	}
}

template<typename Type>
void MyBinTree<Type>::PostOrderCout(MyBinTreeNode<Type>* current) const
{
	if (current != nullptr) {
		PostOrderCout(current->leftChild);
		PostOrderCout(current->rightChild);
		cout << current->data << " ";
	}
}
