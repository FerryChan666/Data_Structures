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
		printf("%3d", L->data);//��ӡ��ǰ�������
		L = L->next;//ָ����һ�����
	}
	printf("\n");
}

//ͷ�巨
LinkList Create_List_1(LinkList& l) {
	//����ͷ���
	l = (LNode*)malloc(sizeof(LNode));
	l->next = NULL;
	//s����ָ���½ڵ�
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

//β�巨
LinkList Create_List_2(LinkList& l) {
	//�½�ͷ�ڵ�
	l = (LNode*)malloc(sizeof(LNode));
	l->next = NULL;
	//�½ڵ�
	LNode* s, *r=l;//rָ��β�ڵ�
	ElemType i;
	scanf("%d", &i);
	while (i!=9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		r->next = s;
		//����β�ڵ�
		r = s;
		scanf("%d", &i);
	}
	r->next = NULL;
	return l;
}

//����Ų���($)
LinkList GetElem(LinkList l, int i) {
	LNode* p = l->next;//��pָ���һ��Ԫ��(ͷ�ڵ����һ��)
	int j = 1;//����������

	if (0 == i) {	//��0Ԫ�أ�ͷ�ڵ㣩
		return l;
	}
	if (i < 0) {//i��Ч
		return NULL;
	}
	
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;//���ؽڵ�ָ�룬������������ȣ�����NULL
}
//����
bool FrontInsert(LinkList l,ElemType e, int i) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	LNode *p=GetElem(l, i-1);//��ȡҪ�����ǰһ���ڵ��ָ��
	if (NULL == p) {
		return false;
	}
	s->next = p->next;
	p->next = s;
	return true;
}
//ɾ��
bool Delete(LinkList l, int i) {
	LNode* p = GetElem(l, i-1);//���Ҫɾ��Ԫ�ص�ǰһ���ڵ�
	if (NULL == p) {
		return false;
	}
	LNode* s = p->next;//ָ��Ҫɾ��Ԫ�أ��Ա�free
	//���Ӻ�ɾ�����Ԫ��
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