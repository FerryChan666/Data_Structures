#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a[100];
	int count_n = 0;
	for (int i = 0; i < 100; i++)
	{
		scanf("%d", &a[i]);
		if (getchar() == '\n')
			count_n++;
		if (count_n == 2)
			break;

	}
	int count = 0;
	count_n = 0;
	for (int i = 0; i < 100; i++) {
		if (a[i] == 2)
			count++;
		if (a[i] == '\n') {
			count_n++;
			if (count_n == 2)
				break;
		}
	}
	printf("%d\n", count);
}