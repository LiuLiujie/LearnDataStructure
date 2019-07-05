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
		QNode* p = front->next;//pָ���һ��Ԫ��
		KeyType e = p->data;
		front->next = p->next;//ͷ���ָ����һ��Ԫ��
		if (rear == p)//���Ƕ������һ��Ԫ�ؽ�Ҫ��ɾ��,ʹͷָ���βָ��ָ��ͬһ����ʾ�ն���
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
