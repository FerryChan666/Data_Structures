#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++) {
		printf("a[%d]=%d\n", i, a[i]);
	}
}

int main() {
	int a[5] = { 1,2,3,4,5 };
	char c[20], e[20];
	scanf("%s%s", c, e);
	printf("%s---%s", c, e);
}