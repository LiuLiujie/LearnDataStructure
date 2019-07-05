#include "Stack.h"
Stack::Stack()
{
	SNode* p = new SNode;
	p->next = nullptr;
	top = p;
	base = p;
}

Stack::~Stack()
{
	if (!Empty()) {
		MakeEmpty();
	}
}

void Stack::Push(KeyType x)
{
	SNode* p = new SNode;
	if (p != nullptr) {
		p->data = x;
		p->next = top;
		top = p;
	} else {
		std::cout << "ERROR:Create New Node Failed" << std::endl;
	}
}

KeyType Stack::Pop()
{
	if (Empty())//判断当前栈是否为空
	{
		std::cout << "ERROR::Stack Is Empty" << std::endl;
		return -1;
	}
	KeyType x;
	SNode* p = top;
	if (p != nullptr) {
		x = p->data;
		top = top->next;
	} else {
		std::cout << "ERROR::Create New Node Failed" << std::endl;
	}
	delete p;
	return x;
}

KeyType Stack::GetTop()
{
	if (Empty())//判断当前栈是否为空
	{
		std::cout << "ERROR::Stack Is Empty!!!" << std::endl;
		return -1;
	}
	return top->data;
}

bool Stack::Empty() {
	if (top == base) {
		return true;
	}
	return false;
}

void Stack::MakeEmpty()
{
	while (!Empty()) {
		Pop();
	}
	delete top;
	top = nullptr;
	base = nullptr;
}

