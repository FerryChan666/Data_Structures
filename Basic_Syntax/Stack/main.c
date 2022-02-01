#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* my_stack() {
	char c[20]= "I am a stack";
	puts(c);

	return c;
}

char* my_heap() {
	char* c = (char*)malloc(20);
	strcpy(c, "I am a heap");
	puts(c);
	return c;
}

int main() {
	char* p;
	p = my_heap();
	puts(p);
	free(p);
	p = NULL;
}