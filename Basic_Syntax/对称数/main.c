#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int count=0;
	int n2 = n;

	//取位数
	while (n2)
	{
		n2 /= 10;
		count++;
	}
	printf("%d\n", count);

	//取后半部分
	int half=count / 2;
	int n3 = n;
	int back_count = 0;
	int back_part = 0;
	while (back_count != half) {
		back_part = back_part * 10 + n3 % 10;
		n3 /= 10;
		back_count++;
	}
	printf("%d\n", back_part);

	//获取前半部分
	int first_part = n3;
	if (count % 2)
		first_part /= 10;
	printf("%d\n", first_part);

	//判断相等
	if (back_part == first_part)
		printf("yes\n");
	else
		printf("no\n");
}