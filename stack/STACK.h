#ifndef STACK
#define STACK
#include <iostream>
using namespace std;
#define OverFlow -2
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;

/*ʵ��ջ��ģ����*/
template <class SElemType>class stack {
private:
	SElemType* base = NULL;// ջ��ָ��
	SElemType* top = NULL;// ջ��ָ��
	int stacksize = 0;// ջ��С
public:
	stack();
	~stack();
	Status ClearStack();
	Status StackEmpty();
	int StackLength();
	Status GetTop(SElemType& e);
	Status Push(SElemType e);
	Status Pop(SElemType& e);
	Status ShowStack();
};

/*ʵ��ջ�Ĺ��캯��������ռ��ջλ��*/
template <class SElemType>stack<SElemType>::stack() {
	base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if (!base) {
		exit(OverFlow);
	}
	top = base;
	stacksize = STACK_INIT_SIZE;
}

/*ջ��������ʵ��ջ�ռ���ͷ�*/
template <class SElemType>stack<SElemType>::~stack() {
	free(base);
}

/*ջ���������ɾ��ջ����������ջ�ڵ�����Ԫ��*/
template <class SElemType>Status stack<SElemType>::ClearStack() {
	top = base;
	return OK;
}

/*ջ���пգ�����ջ��״̬���Ƿ�Ϊ�գ�*/
template <class SElemType>Status stack<SElemType>::StackEmpty() {
	if (base == top) {
		return TRUE;
	}
	return FALSE;
}

/*ջ�ĳ��ȣ�����һ��ջ�ĳ���*/
template <class SElemType>int stack<SElemType>::StackLength() {
	return top - base;
}

/*ջ�����ջ��������ջ��Ԫ��ֵ*/
template <class SElemType>Status stack<SElemType>::GetTop(SElemType& e) {
	if (StackEmpty()) {
		cout << "The Stack is Empty!" << endl;
		return ERROR;
	}
	e = *(top - 1);
	return OK;
}

/*ջ��ѹ�룺ѹ��ջ��Ԫ��*/
template <class SElemType>Status stack<SElemType>::Push(SElemType e) {
	if (top - base == stacksize - 1) {
		base = (SElemType*)realloc(base, sizeof(SElemType) * (stacksize + STACKINCREMENT));
		if (!base) {
			exit(OverFlow);
		}
		top = stacksize + base - 1;
		stacksize += STACKINCREMENT;
	}
	*top++ = e;
	return OK;
}

/*ջ�ĳ�ջ*/
template <class SElemType>Status stack<SElemType>::Pop(SElemType& e) {
	if (StackEmpty()) {
		cout << "The Stack is Empty!";
		return ERROR;
	}
	e = *--top;
	return OK;
}

/*ջ��չʾ��Ϊ�˷���չʾ��*/
template <class SElemType>Status stack<SElemType>::ShowStack() {
	if (StackEmpty()) {
		cout << "The Stack is Empty!" << endl;
		return ERROR;
	}
	SElemType* s = base;
	while (s != top) {
		cout << *s++ << endl;
	}
	return OK;
}

#endif