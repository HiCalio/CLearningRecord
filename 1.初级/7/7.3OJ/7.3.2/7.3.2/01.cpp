#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void shuru(char*& p) {
	p = (char*)malloc(100);
	fgets(p, 100,stdin);
}
int main() {
	char* p;
	shuru(p);
	printf("%s\n", p);
	return 0;
}