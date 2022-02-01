#include<stdio.h>
#include<stdlib.h>
void modifynum(int& i) {
	i = 10;
}

void modify_point(char*& p) {
	p = (char*)malloc(20);
}

int main() {
	char* p;
	modify_point(p);
	fgets(p, 20, stdin);
	printf("%s\n", p);
}