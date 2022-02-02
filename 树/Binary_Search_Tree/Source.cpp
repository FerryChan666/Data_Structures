#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int BiElemType ;

typedef struct BiTNode {
	BiElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

bool Insert_BST(BiTree& t, BiElemType e) {
	if (NULL == t) {
		t = (BiTree)calloc(1, sizeof(BiTNode));
		t->data = e;
		return true;
	}
	else if (e == t->data) {
		return false;
	}
	else if (e < t->data) {
		return Insert_BST(t->lchild, e);
	}
	else
	{
		return Insert_BST(t->rchild, e);
	}
}

void Create_BST(BiTree &t, BiElemType *arr, int n) {
	for (size_t i = 0; i < n; i++)
	{
		Insert_BST(t, arr[i]);
	}
}

void InOrder(BiTree p, BiElemType *a, int &pos) {
	if (p != NULL) {
		InOrder(p->lchild,a,pos);
		printf("%3d", p->data);
		a[pos++] = p->data;
		InOrder(p->rchild,a,pos);
	}
}

BiTree BST_Search(BiTree t, BiElemType e) {
	if (e == t->data) {
		return t;
	}
	else if (e < t->data) {
		return BST_Search(t->lchild, e);
	}
	else {
		return BST_Search(t->rchild, e);
	}
}

int main() {
	BiTree t=NULL;
	int arr[10] = { 87, 7, 60, 80 ,59, 34, 86, 99, 21, 3 };
	Create_BST(t, arr, 10);

	int a[10];
	int pos = 0;
	InOrder(t,a,pos);
	printf("\n");


	return 0;
}