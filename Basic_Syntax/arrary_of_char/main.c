#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(char c[]) {
	int i = 0;
	while (c[i])
	{
		printf("%c", c[i]);
		i++;
	}
	printf("\n");
}
int main() {
	char c[20] = "hello";
	print(c);
}