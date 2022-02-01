#include<stdio.h>
int main() {
	int i = -1;
	int j;
	j = i++ > -1;
	printf("i=%d,j=%d", i, j);
	return 0;
}