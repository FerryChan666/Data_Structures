#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MaxSize 50
#define ElemType int

typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

void Init(SqStack &s) {
	s.top = -1;
}

bool IsEmpty(SqStack s) {
	if (s.top == -1) {
		return true;
	}	
	return false;
}

bool IsFull(SqStack s) {
	if (s.top >= MaxSize - 1) {
		return true;
	}
	return false;
}

bool Push(SqStack& s, ElemType e) {
	if (IsFull(s)) {
		return false;
	}
	s.data[++s.top] = e;
	return true;
}

bool Pop(SqStack& s, ElemType &e) {
	if (IsEmpty(s)) {
		return false;
	}
	e=s.data[s.top--];
	return true;
}

bool GetTop(SqStack s, ElemType& e) {
	if (IsEmpty(s)) {
		return false;
	}
	e = s.data[s.top];
	return true;
}

int main() {
	SqStack s;
	ElemType e;
	bool flag;
	Init(s);
	for (int i = 0; i < 3; i++) {
		scanf("%d", &e);
		Push(s, e);
	}

	for (int i = 0; i < 3; i++) {
		flag = Pop(s, e);
		if (flag) {
			printf("%2d", e);
		}
	}
	return 0;
}