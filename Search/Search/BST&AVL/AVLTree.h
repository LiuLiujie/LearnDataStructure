#pragma once
#include <iostream>
#include <cassert>
#include "..//Type.h"
class AVLTree
{
private:
	AVLNode* root;
	int InsertAVL(AVLNode*& tree, ElemType x, int& taller);//插入节点
	void RotateLeft(AVLNode* Tree, AVLNode*& NewTree);//向左单旋转
	void RotateRight(AVLNode* Tree, AVLNode*& NewTree);//向右单旋转
	void LeftBalance(AVLNode*& Tree, int& taller);//需要左平衡:包括左单旋和先左后右
	void RightBalance(AVLNode*& Tree, int& taller);//需要右平衡:包括右旋和先右后左
	int DepthAVL(AVLNode* t) const;//递归获得二叉树深度

public:
	AVLTree();
	void InsertAVL(ElemType x);
	int DepthAVL() const;
};

