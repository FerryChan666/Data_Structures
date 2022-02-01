#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

void Print(LinkList L)

{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
	}
	printf("\n");
}

//头插法
LinkList Create_List_1(LinkList& l) {
	//创建头结点
	l = (LNode*)malloc(sizeof(LNode));
	l->next = NULL;
	//s用于指向新节点
	LNode* s;
	ElemType i;
	scanf("%d", &i);
	while (i != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		s->next = l->next;
		l->next = s;
		scanf("%d", &i);
	}
	return l;
}

//尾插法
LinkList Create_List_2(LinkList& l) {
	//新建头节点
	l = (LNode*)malloc(sizeof(LNode));
	l->next = NULL;
	//新节点
	LNode* s, *r=l;//r指向尾节点
	ElemType i;
	scanf("%d", &i);
	while (i!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		r->next = s;
		//更新尾节点
		r = s;
		scanf("%d", &i);
	}
	r->next = NULL;
	return l;
}

//按序号查找($)
LinkList GetElem(LinkList l, int i) {
	LNode* p = l->next;//让p指向第一个元素(头节点的下一个)
	int j = 1;//计链表的序号

	if (0 == i) {	//第0元素（头节点）
		return l;
	}
	if (i < 0) {//i无效
		return NULL;
	}
	
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;//返回节点指针，如果超过链表长度，返回NULL
}
//插入
bool FrontInsert(LinkList l,ElemType e, int i) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	LNode *p=GetElem(l, i-1);//获取要插入的前一个节点的指针
	if (NULL == p) {
		return false;
	}
	s->next = p->next;
	p->next = s;
	return true;
}
//删除
bool Delete(LinkList l, int i) {
	LNode* p = GetElem(l, i-1);//获得要删除元素的前一个节点
	if (NULL == p) {
		return false;
	}
	LNode* s = p->next;//指向要删除元素，以便free
	//链接好删除后的元素
	p->next = s->next;
	free(s);
	s = NULL;
	return true;
}

int main() {
	LinkList l;
	Create_List_2(l);
	LNode* p = GetElem(l, 2);
	printf("%d\n", p->data);
	FrontInsert(l, 99, 2);
	Print(l);
	Delete(l, 4);
	Print(l);
}