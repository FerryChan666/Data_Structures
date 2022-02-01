#include"Header.h"
void InitQueue(LinkQueue& lq) {
	//头节点
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->next = NULL;
	lq.front = lq.rear = s;
}

bool QueueEmpty(LinkQueue lq) {
	if (lq.front == lq.rear) {
		return true;
	}
	return false;
}

void EnQueue(LinkQueue& lq, QueueElemType e) {
	//新节点
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	//尾插法
	lq.rear->next = s;
	//更新链队列（头尾指针）
	lq.rear = s;
}

bool DeQueue(LinkQueue& lq, QueueElemType& e) {
	if (QueueEmpty(lq)) {
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