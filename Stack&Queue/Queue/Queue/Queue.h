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
	QNode* front;//��ͷָ��,ָ�򲻴洢���ݵ�ͷ���
	QNode* rear;//��βָ��,ָ�����һ�����ݽ��
};

