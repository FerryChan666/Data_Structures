#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
#define ElemType int
//���нڵ�
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//����ͷβָ��
typedef struct {
	LinkNode* front;
	LinkNode* rear;
}LinkQueue;

void InitQueue(LinkQueue& lq) {
	//ͷ�ڵ�
	LinkNode* s = (LinkNode *)malloc(sizeof(LinkNode));
	s->next = NULL;

	lq.front = lq.rear = s;
}

void EnQueue(LinkQueue& lq,ElemType e) {
	//�½ڵ�
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	//β�巨
	lq.rear->next = s;
	//���������У�ͷβָ�룩
	lq.rear = s;
}

bool IsEmpty(LinkQueue lq) {
	if (lq.front == lq.rear) {
		return true;
	}
	return false;
}

bool DeQueue(LinkQueue& lq, ElemType& e) {
	if (IsEmpty(lq)) {
		return false;
	}
	//����pָ���һ��Ԫ��
	LinkNode* p = lq.front->next;
	e = p->data;
	//�޸�ָ��
	lq.front->next = p->next;
	//�ж��Ƿ�Ϊ���һ��Ԫ�أ��Ǿ���ͷβָ��ָ��ͷ�ڵ㡣
	if (lq.rear == p) {
		lq.rear = lq.front;
	}
	free(p);
	return true;
}

int main() {
	LinkQueue lq;
	InitQueue(lq);
	EnQueue(lq, 3);
	EnQueue(lq, 4);
	EnQueue(lq, 5);
	ElemType e;
	while (!IsEmpty(lq))
	{
		DeQueue(lq, e);
		printf("%2d", e);
	}
	return 0;
}