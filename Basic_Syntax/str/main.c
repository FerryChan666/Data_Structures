#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
int main() {
	char c[20];
	char c1[20];
	gets(c);
	strcpy(c1, c);

	//注意，数组从0开始。解决方法：将从1开始的数，全部-1.or将从0开始的数全部+1
	char tmp;
	int len = strlen(c) - 1;
	for (int i = 0; i <= len / 2; i++) {
		tmp = c1[i];
		c1[i] = c1[len - i];
		c1[len - i] = tmp;
	}
	puts(c1);

	int result = strcmp(c, c1);

	if (result < 0)

	{

		printf("%d\n", -1);

	}

	else if (result > 0)

	{

		printf("%d\n", 1);

	}

	else {

		printf("%d\n", 0);

	}
	
}