#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


typedef struct student {
	int num;
	char name[20];
	char sex;
}stu, *pstu;


int main() {
	stu s = { 19,"ferry",'M' };
	pstu p = &s;

}