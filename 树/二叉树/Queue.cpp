#include"Header.h"
void InitQueue(LinkQueue& lq) {
	//ͷ�ڵ�
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
	//�½ڵ�
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = NULL;
	//β�巨
	lq.rear->next = s;
	//���������У�ͷβָ�룩
	lq.rear = s;
}

bool DeQueue(LinkQueue& lq, QueueElemType& e) {
	if (QueueEmpty(lq)) {
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