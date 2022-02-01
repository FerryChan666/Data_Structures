#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct student	//struct是关键字，student是数据类型
{
	int num;
	char name[20];
	char sex;
};		//最后一定加分号

int main() {
	struct student s;
	scanf("%d%s %c", &s.num, s.name, &s.sex);
	printf("%d %s %c", s.num, s.name, s.sex);
	return 0;
}