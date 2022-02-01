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
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
	}
	printf("\n");
}

DLinkList Dlist_head_insert(DLinkList& dl) {
	//创建头节点
	dl = (DNode*)malloc(sizeof(DNode));
	dl->prior = dl->next = NULL;
	//创建新节点
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
		dl->next = s;//断链一定要放最后
		scanf("%d", &e);//循环读入
	}
	return dl;
}

DLinkList Dlist_tail_insert(DLinkList& dl) {
	//创建头节点
	dl = (DNode*)malloc(sizeof(DNode));
	dl->prior = dl->next = NULL;
	//创建新节点
	DNode* s, *r = dl;//s为新节点指针，r为尾节点指针
	ElemType e;
	scanf("%d", &e);
	while (e!=9999)
	{
		s = (DNode*)malloc(sizeof(DNode));
		s->data = e;
		s->prior = r;
		r->next = s;
		//更新尾节点
		r = s;
		scanf("%d", &e);//循环读入
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