#include "Queue.h"

void Queue::EnQueue(KeyType e)
{
	QNode* p = new QNode;
	if (p) {
		p->data = e;
		p->next = nullptr;
		rear->next = p;
		rear = p;
	} else {
		std::cout << "Create Node Failed" << std::endl;
	}
}

KeyType Queue::DeQueue()
{
	if (front != rear) {
		QNode* p = front->next;//p指向第一个元素
		KeyType e = p->data;
		front->next = p->next;//头结点指向下一个元素
		if (rear == p)//这是队列最后一个元素将要被删除,使头指针和尾指针指向同一处表示空队列
		{
			rear = front;
		}
		delete p;
		return e;
	} else {
		std::cout << "Queue Is Empty!" << std::endl;
	}
}

KeyType Queue::GetHead()
{
	if (front != rear) {
		KeyType e = front->next->data;
		return e;
	} else {
		std::cout << "Queue Is Empty!" << std::endl;
	}
}

bool Queue::Empty()
{
	if (front == rear) {
		return true;
	}
	return false;
}

bool Queue::MakeEmpty()
{
	while (!Empty()) {
		DeQueue();
	}
	delete front;
	front = nullptr;
	rear = nullptr;
}

Queue::Queue()
{
	QNode* p = new QNode;
	p->next = nullptr;
	front = p;
	rear = p;
}

Queue::~Queue()
{
	if (!Empty()) {
		MakeEmpty();
	}
}
