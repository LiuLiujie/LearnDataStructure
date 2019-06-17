#pragma once

template<typename Type> 
class MyBinTreeNode
{
	friend class MyBinTree;
private:
	MyBinTreeNode<Type>* leftChild, * rightChild;//�ýڵ����������������
	Type data;
public:
	//���ַ�ʽ����һ���ڵ�,�����սڵ���Լ������������Һ�ֱ�ӵ����вι��캯������
	MyBinTreeNode();
	MyBinTreeNode(Type item, MyBinTreeNode<Type>* left = nullptr, MyBinTreeNode<Type>* right = nullptr);
	~MyBinTreeNode();

	Type GetData()const;//��ʾֻ��ȡ���ݳ�Ա,���ı�
	MyBinTreeNode<Type>* GetLeft()const;//�õ��������ĵ�ַ
	MyBinTreeNode<Type>* GetRight()const;//�õ��������ĵ�ַ

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
(Type item, MyBinTreeNode<Type> *left, MyBinTreeNode<Type> *right)//Ĭ�ϲ���ֻ����һ��
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
