#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct student	//struct�ǹؼ��֣�student����������
{
	int num;
	char name[20];
	char sex;
};		//���һ���ӷֺ�

int main() {
	struct student s;
	scanf("%d%s %c", &s.num, s.name, &s.sex);
	printf("%d %s %c", s.num, s.name, s.sex);
	return 0;
}