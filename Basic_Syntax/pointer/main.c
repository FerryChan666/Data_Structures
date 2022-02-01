#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void change(int *i) {
	*i = *i / 2;
}
int main() {
	int i;
	scanf("%d", &i);
	change(&i);
	printf("%d\n", i);
}
