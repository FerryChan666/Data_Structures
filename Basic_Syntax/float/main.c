#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {

	int i;
	char c;
	scanf("i=%d", &i);
	printf("%d", i);
	scanf("%c", &c);//¶ÁÈ¡'\n'
	printf("%c",c);//Êä³ö'\n'

	return 0;
}