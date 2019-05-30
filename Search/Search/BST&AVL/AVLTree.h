#pragma once
#include <iostream>
#include <cassert>
#include "..//Type.h"
class AVLTree
{
private:
	AVLNode* root;
	int InsertAVL(AVLNode*& tree, ElemType x, int& taller);//����ڵ�
	void RotateLeft(AVLNode* Tree, AVLNode*& NewTree);//������ת
	void RotateRight(AVLNode* Tree, AVLNode*& NewTree);//���ҵ���ת
	void LeftBalance(AVLNode*& Tree, int& taller);//��Ҫ��ƽ��:�����������������
	void RightBalance(AVLNode*& Tree, int& taller);//��Ҫ��ƽ��:�������������Һ���
	int DepthAVL(AVLNode* t) const;//�ݹ��ö��������

public:
	AVLTree();
	void InsertAVL(ElemType x);
	int DepthAVL() const;
};

