#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {

	int i;
	char c;
	scanf("i=%d", &i);
	printf("%d", i);
	scanf("%c", &c);//��ȡ'\n'
	printf("%c",c);//���'\n'

	return 0;
}