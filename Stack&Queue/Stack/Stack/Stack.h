#pragma once
#include <iostream>
typedef int KeyType;
class Stack
{
public:
	Stack();
	~Stack();
	void Push(KeyType x);
	KeyType Pop();
	KeyType GetTop();
	bool Empty();
	void MakeEmpty();

private:
	struct SNode
	{
		KeyType data;
		SNode* next;
	};
	SNode* top;//ջ��ָ��
	SNode* base;//ջ��ָ��
};

