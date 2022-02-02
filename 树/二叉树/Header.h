#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//����������ݽṹ
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType c;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;
//��������s
typedef struct tag {
	BiTree p;//����ÿһ���ڵ�ĵ�ַ
	struct tag* pnext;
}tag_t, * ptag_t;




//ջ��������ݽṹ
#define MaxSize 50
typedef BiTree StackElemType;
typedef struct {
	StackElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack& s);
bool StackEmpty(SqStack s);
bool StackFull(SqStack s);
bool Push(SqStack& s, StackElemType e);
bool Pop(SqStack& s, StackElemType& e);
bool GetTop(SqStack s, StackElemType& e);

//���е�������ݽṹ
typedef BiTree QueueElemType;
typedef struct LinkNode {//���нڵ�
	QueueElemType data;
	struct LinkNode* next;
}LinkNode;


typedef struct {//����ͷβָ��
	LinkNode* front;
	LinkNode* rear;
}LinkQueue;

void InitQueue(LinkQueue& lq);
bool QueueEmpty(LinkQueue lq);
void EnQueue(LinkQueue& lq, QueueElemType e);
bool DeQueue(LinkQueue& lq, QueueElemType& e);
