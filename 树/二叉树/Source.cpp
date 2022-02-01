#include"Header.h"

void PreOrder(BiTree p) {
	if (p != NULL) {
		putchar(p->c);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void InOrder(BiTree p) {
	if (p != NULL) {
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}

void PostOrder(BiTree p) {
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}

void levelOrder(BiTree tree) {
	LinkQueue lq;
	InitQueue(lq);
	EnQueue(lq, tree);

	BiTree p;
	while (!QueueEmpty(lq))
	{
		DeQueue(lq, p);//节点出队，并把节点赋给p
		printf("%c", p->c);
		if (p->lchild) {
			EnQueue(lq, p->lchild);
		}
		if (p->rchild) {
			EnQueue(lq, p->rchild);
		}
	}
}

int main() {
	BiTree pnew;//临时树节点
	char c;
	BiTree tree = NULL;//树根
	//phead就是链表头，ptail就是链表尾，pcur用于遍历链表
	ptag_t phead = NULL, ptail = NULL, listpnew=NULL, pcur=NULL;
	//abcdefghij
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//申请树结点
		pnew->c = c;//数据放进去
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//申请链表结点
		listpnew->p = pnew;
		if (NULL == tree)
		{
			tree = pnew;//树的根
			phead = listpnew;//链表头
			ptail = listpnew;//链表尾
			pcur = listpnew;
			continue;//建立好了根节点
		}
		else {
			//尾插法
			ptail->pnext = listpnew;
			ptail = listpnew;
		}//pcur始终指向要插入的结点的位置
		if (NULL == pcur->p->lchild)//如何把新结点放入树
		{
			pcur->p->lchild = pnew;//把新结点放到要插入结点的左边
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//把新结点放到要插入结点的右边
			pcur = pcur->pnext;//左右都放了结点后，pcur指向队列的下一个
		}
	}
	PreOrder(tree);
	printf("\n");
	InOrder(tree);
	printf("\n");
	PostOrder(tree);
	printf("\n");
	levelOrder(tree);
}