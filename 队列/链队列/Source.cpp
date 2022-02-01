#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
#define ElemType int
//队列节点
typedef struct LinkNode {
	ElemType data;
	struct LinkNode* next;
}LinkNode;

//队列头尾指针
typedef struct {
	LinkNode* front;
	LinkNode* rear;
}LinkQueue;

void InitQueue(LinkQueue& lq) {
	//头节点
	LinkNode* s = (LinkNode *)malloc(sizeof(LinkNode));
	s->next = NULL;

	lq.front = lq.rear = s;
}

void EnQueue(LinkQueue& lq,ElemType e) {
	//新节点
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	//尾插法
	lq.rear->next = s;
	//更新链队列（头尾指针）
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
	//先让p指向第一个元素
	LinkNode* p = lq.front->next;
	e = p->data;
	//修改指针
	lq.front->next = p->next;
	//判断是否为最后一个元素，是就让头尾指针指向头节点。
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