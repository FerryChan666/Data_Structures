#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct student {
	int num;
	char name[20];
	char sex;
};
int main()
{

	struct student sarr[3] = {1001,"lilei",'M',1005,"zhangsan",'M',1007,"lili",'F'};
	struct student* p=&sarr; //����ṹ��ָ��
	int num;
	//->��++���ȼ���
	num = p->num++;//��ִ��num=p->num, �ٰ����ȼ��Ӽ� p->num++;
	printf("num=%d,p->num=%d\n", num, p->num);//1001 1002

	num = p++->num;//��ִ��num=p->num, �ٰ����ȼ��Ӽ� p++
	printf("num=%d,p->num=%d\n", num, p->num);//1002 1005
}