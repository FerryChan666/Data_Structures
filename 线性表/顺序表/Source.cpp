#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MaxSize 50
#define ElemType int
typedef struct {
	ElemType data[MaxSize];
	int len;
} SqList;

void Print(SqList l) {
	for (int i = 0; i < l.len; i++) {
		printf("%3d", l.data[i]);
	}
	printf("\n");
}

bool Insert(SqList& l, ElemType e, int n) {
	//�жϲ���λ���Ƿ�Ϸ�
	if (n<1 || n>l.len) {
		return false;
	}
	//�жϲ�����Ƿ񳬳�SqList����󳤶�
	if (l.len == MaxSize) {
		return false;
	}
	//����1��ʼ������ȫ-1����ɴ�0��ʼ
	int len = l.len - 1;
	n = n - 1;
	for (int i = len; i >= n; i--) {
		l.data[i + 1] = l.data[i];
	}
	l.data[n] = e;
	l.len++;
	return true;
}

bool Delete(SqList& l, int n, ElemType &e) {
	if (n<1 || n>l.len) {
		return false;
	}
	//�������
	n--;
	int len = l.len - 1;

	e = l.data[n];
	for (int i = n; i < len; i++) {
		l.data[i] = l.data[i + 1];
	}
	l.len--;
	return true;
}


int main() {
	SqList l;
	l.data[0] = 1;
	l.data[1] = 2;
	l.data[2] = 3;
	l.len = 3;
	//����Ԫ��
	ElemType i;
	scanf("%d", &i);
	Insert(l, i, 2);
	Print(l);

}