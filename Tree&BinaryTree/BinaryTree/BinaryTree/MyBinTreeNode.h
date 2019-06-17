#pragma once

template<typename Type> class MyBinTreeNode
{
	friend class MyBinTree;
private:
	MyBinTreeNode<Type> *leftChild, *rightChild;//�ýڵ����������������
	Type data;
public:
	//���ַ�ʽ����һ���ڵ�,�����սڵ���Լ������������Һ�ֱ�ӵ����вι��캯������
	MyBinTreeNode();
	MyBinTreeNode(Type item, MyBinTreeNode<Type> *left = nullptr, MyBinTreeNode<Type> *right = nullptr);
	~MyBinTreeNode();

	Type GetData()const;//��ʾֻ��ȡ���ݳ�Ա,���ı�
	MyBinTreeNode<Type> *GetLeft()const;//�õ��������ĵ�ַ
	MyBinTreeNode<Type> *GetRight()const;//�õ��������ĵ�ַ

	void SetData(const Type &item);
	void SetLeft(MyBinTreeNode<Type> *L);
	void SetRight(MyBinTreeNode<Type> *R);
};


