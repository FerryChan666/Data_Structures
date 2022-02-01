#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MaxSize 5
#define ElemType int

typedef struct {
	ElemType data[MaxSize];
	int front;
	int rear;
} SqQueue;

void Init(SqQueue &q) {
	q.front = q.rear = 0;
}

bool IsEmpty(SqQueue q) {
	if (q.front == q.rear) {
		return true;
	}
	return false;
}

bool IsFull(SqQueue q) {
	if ((q.rear + 1) % MaxSize == q.front) {
		return true;
	}
	return false;
}

bool EnQueue(SqQueue& q, ElemType e) {
	if (IsFull(q)) {
		return false;
	}
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}

bool DeQueue(SqQueue& q, ElemType &e) {
	if (IsEmpty(q)) {
		return false;
	}
	e = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

int main() {
	SqQueue q;
	ElemType e;
	bool flag;
	Init(q);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &e);
		flag=EnQueue(q, e);
		if (!flag)
		{
			printf("false\n");
		}
	}

	for (int i = 0; i < 5; i++) {
		flag = DeQueue(q, e);
		if (flag) {
			printf("%2d", e);
		}
	}
	printf("\n");
}