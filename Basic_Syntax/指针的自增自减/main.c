#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a[3] = { 2,7,8 };
	int* p;
	int j;

	p = a;
	j = (*p)++;
	printf("a[0]=%d, j=%d,*p=%d\n", a[0], j, *p);
	return 0;
}