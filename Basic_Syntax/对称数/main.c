#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int count=0;
	int n2 = n;

	//ȡλ��
	while (n2)
	{
		n2 /= 10;
		count++;
	}
	printf("%d\n", count);

	//ȡ��벿��
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

	//��ȡǰ�벿��
	int first_part = n3;
	if (count % 2)
		first_part /= 10;
	printf("%d\n", first_part);

	//�ж����
	if (back_part == first_part)
		printf("yes\n");
	else
		printf("no\n");
}