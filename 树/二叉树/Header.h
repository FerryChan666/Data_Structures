#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//树的相关数据结构
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType c;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;
//辅助链表s
typedef struct tag {
	BiTree p;//树的每一个节点的地址
	struct tag* pnext;
}tag_t, * ptag_t;




//栈的相关数据结构
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

//队列的相关数据结构
typedef BiTree QueueElemType;
typedef struct LinkNode {//队列节点
	QueueElemType data;
	struct LinkNode* next;
}LinkNode;


typedef struct {//队列头尾指针
	LinkNode* front;
	LinkNode* rear;
}LinkQueue;

void InitQueue(LinkQueue& lq);
bool QueueEmpty(LinkQueue lq);
void EnQueue(LinkQueue& lq, QueueElemType e);
bool DeQueue(LinkQueue& lq, QueueElemType& e);
