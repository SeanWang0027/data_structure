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

/*实现栈的模板类*/
template <class SElemType>class stack {
private:
	SElemType* base = NULL;// 栈底指针
	SElemType* top = NULL;// 栈顶指针
	int stacksize = 0;// 栈大小
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

/*实现栈的构造函数，分配空间和栈位置*/
template <class SElemType>stack<SElemType>::stack() {
	base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
	if (!base) {
		exit(OverFlow);
	}
	top = base;
	stacksize = STACK_INIT_SIZE;
}

/*栈的析构：实现栈空间的释放*/
template <class SElemType>stack<SElemType>::~stack() {
	free(base);
}

/*栈的清除：不删除栈的情况下清空栈内的已有元素*/
template <class SElemType>Status stack<SElemType>::ClearStack() {
	top = base;
	return OK;
}

/*栈的判空：返回栈的状态（是否为空）*/
template <class SElemType>Status stack<SElemType>::StackEmpty() {
	if (base == top) {
		return TRUE;
	}
	return FALSE;
}

/*栈的长度：返回一个栈的长度*/
template <class SElemType>int stack<SElemType>::StackLength() {
	return top - base;
}

/*栈的求解栈顶：返回栈顶元素值*/
template <class SElemType>Status stack<SElemType>::GetTop(SElemType& e) {
	if (StackEmpty()) {
		cout << "The Stack is Empty!" << endl;
		return ERROR;
	}
	e = *(top - 1);
	return OK;
}

/*栈的压入：压入栈的元素*/
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

/*栈的出栈*/
template <class SElemType>Status stack<SElemType>::Pop(SElemType& e) {
	if (StackEmpty()) {
		cout << "The Stack is Empty!";
		return ERROR;
	}
	e = *--top;
	return OK;
}

/*栈的展示（为了方便展示）*/
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