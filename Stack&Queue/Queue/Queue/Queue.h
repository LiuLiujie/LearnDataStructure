#pragma once
#include <iostream>
typedef int KeyType;
class Queue
{
public:
	void EnQueue(KeyType e);
	KeyType DeQueue();
	KeyType GetHead();
	bool Empty();
	bool MakeEmpty();
	Queue();
	~Queue();

private:
	struct QNode {
		KeyType data;
		struct QNode* next;
	};
	QNode* front;//队头指针,指向不存储数据的头结点
	QNode* rear;//队尾指针,指向最后一个数据结点
};

