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
		DeQueue(lq, p);//�ڵ���ӣ����ѽڵ㸳��p
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
	BiTree pnew;//��ʱ���ڵ�
	char c;
	BiTree tree = NULL;//����
	//phead��������ͷ��ptail��������β��pcur���ڱ�������
	ptag_t phead = NULL, ptail = NULL, listpnew=NULL, pcur=NULL;
	//abcdefghij
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//���������
		pnew->c = c;//���ݷŽ�ȥ
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//����������
		listpnew->p = pnew;
		if (NULL == tree)
		{
			tree = pnew;//���ĸ�
			phead = listpnew;//����ͷ
			ptail = listpnew;//����β
			pcur = listpnew;
			continue;//�������˸��ڵ�
		}
		else {
			//β�巨
			ptail->pnext = listpnew;
			ptail = listpnew;
		}//pcurʼ��ָ��Ҫ����Ľ���λ��
		if (NULL == pcur->p->lchild)//��ΰ��½�������
		{
			pcur->p->lchild = pnew;//���½��ŵ�Ҫ����������
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//���½��ŵ�Ҫ��������ұ�
			pcur = pcur->pnext;//���Ҷ����˽���pcurָ����е���һ��
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