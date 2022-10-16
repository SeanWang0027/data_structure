#ifndef QUEUE
#define QUEUE
#include <iostream>
#define OverFlow -2
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
using namespace std;
typedef int Status;

template <typename QElemType> class queue {
private:
	struct Qnode {
		QElemType data;
		Qnode* next = NULL;
	};
	Qnode* front = NULL;
	Qnode* rear = NULL;
public:
	queue();
	~queue();
	Status ClearQueue();
	Status QueueEmpty();
	int QueueLength();
	Status Enqueue(const QElemType n);
	Status Dequeue(QElemType& e);
	Status Showqueue();
};

template <typename QElemType>queue<QElemType>::queue() {
	front = new(nothrow)Qnode;
	if (front == NULL) {
		exit(OverFlow);
	}
	rear = front;
}

template <typename QElemType>queue<QElemType>::~queue() {
	while (front) {
		Qnode* p = front;
		front = p->next;
		delete(p);
	}
}

template <typename QElemType>Status queue<QElemType>::ClearQueue() {
	while (front != rear) {
		if (front->next == rear) {
			rear = front;
			delete front->next;
			continue;
		}
		Qnode* p = front->next;
		front->next = p->next;
		delete(p);
	}
	return OK;
}

template <typename QElemType>Status queue<QElemType>::QueueEmpty() {
	if (rear == front) {
		return TRUE;
	}
	return FALSE;
}

template <typename QElemType>int queue<QElemType>::QueueLength() {
	Qnode* t = front;
	int count = 0;
	while (t->next) {
		count++;
		t = t->next;
	}
	return count;
}

template<typename QElemType>Status queue<QElemType>::Enqueue(const QElemType n) {
	Qnode* q = new(nothrow)Qnode;
	if (q == NULL) {
		exit(OverFlow);
	}
	q->data = n;
	rear->next = q;
	rear = q;
	return OK;
}

template<typename QElemType>Status queue<QElemType>::Dequeue(QElemType& e) {
	if (QueueEmpty()) {
		return ERROR;
	}
	Qnode* p = new(nothrow)Qnode;
	if (p == NULL) {
		exit(OverFlow);
	}
	p = front->next;
	if (p == rear) {
		rear = front;
		e = p->data;
		delete p;
		return OK;
	}
	e = p->data;
	front->next = p->next;
	delete p;
	return OK;
}

template<typename QElemType>Status queue<QElemType>::Showqueue() {
	Qnode* p = front->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return OK;
}

#endif
