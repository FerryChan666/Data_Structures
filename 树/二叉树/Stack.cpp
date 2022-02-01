#include"Header.h"
void InitStack(SqStack& s) {
	s.top = -1;
}

bool StackEmpty(SqStack s) {
	if (s.top == -1) {
		return true;
	}
	return false;
}

bool StackFull(SqStack s) {
	if (s.top >= MaxSize - 1) {
		return true;
	}
	return false;
}

bool Push(SqStack& s, StackElemType e) {
	if (StackFull(s)) {
		return false;
	}
	s.data[++s.top] = e;
	return true;
}

bool Pop(SqStack& s, StackElemType& e) {
	if (StackEmpty(s)) {
		return false;
	}
	e = s.data[s.top--];
	return true;
}

bool GetTop(SqStack s, StackElemType& e) {
	if (StackEmpty(s)) {
		return false;
	}
	e = s.data[s.top];
	return true;
}