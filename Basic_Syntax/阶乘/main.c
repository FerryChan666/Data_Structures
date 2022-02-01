#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int i;
	scanf("%d", &i);
	int sum = 1;
	while (i)
	{
		sum *=i;
		i--;
	}
	printf("%d\n", sum);
	return 0;
}