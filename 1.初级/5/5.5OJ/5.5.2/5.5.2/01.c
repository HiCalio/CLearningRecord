#include<stdio.h>
#include<stdlib.h>
int main() {
	int size;
	char c;
	char* p;
	scanf_s("%d", &size);
	p = (char*)malloc(size+1);
	scanf_s("%c",&c,1);//去除缓冲区里的回车键
	fgets(p, size, stdin);
	puts(p);
	free(p);
	return 0;
}