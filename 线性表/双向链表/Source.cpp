#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct DNode {
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DNode, * DLinkList;

void Print(DLinkList L)

{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
	}
	printf("\n");
}

DLinkList Dlist_head_insert(DLinkList& dl) {
	//����ͷ�ڵ�
	dl = (DNode*)malloc(sizeof(DNode));
	dl->prior = dl->next = NULL;
	//�����½ڵ�
	ElemType e;
	scanf("%d", &e);
	while (e != 9999)
	{
		DNode* s = (DNode*)malloc(sizeof(DNode));
		s->data = e;
		s->next = dl->next;
		s->prior = dl;
		if (dl->next)
		{
			dl->next->prior = s;
		}
		dl->next = s;//����һ��Ҫ�����
		scanf("%d", &e);//ѭ������
	}
	return dl;
}

DLinkList Dlist_tail_insert(DLinkList& dl) {
	//����ͷ�ڵ�
	dl = (DNode*)malloc(sizeof(DNode));
	dl->prior = dl->next = NULL;
	//�����½ڵ�
	DNode* s, *r = dl;//sΪ�½ڵ�ָ�룬rΪβ�ڵ�ָ��
	ElemType e;
	scanf("%d", &e);
	while (e!=9999)
	{
		s = (DNode*)malloc(sizeof(DNode));
		s->data = e;
		s->prior = r;
		r->next = s;
		//����β�ڵ�
		r = s;
		scanf("%d", &e);//ѭ������
	}
	r->next = NULL;
	return dl;
}

int main() {
	DLinkList p;
	Dlist_head_insert(p);
	Print(p);
	Dlist_tail_insert(p);
	Print(p);

	return 0;
}