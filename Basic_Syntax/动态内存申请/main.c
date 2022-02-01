#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int i;//申请字节数
	scanf("%d", &i);
	char* p;
	p = (char*)malloc(i);//指定指针类型为char*
	strcpy(p, "malloc success");
	puts(p);
	free(p);
	p = NULL;
	return 0;
}