#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* print_stack() {
	char c[100] = "I am print_stack func";//数组存放在栈空间中，子函数调用完后就会被自动释放
	char* p;
	p = c;
	puts(p);
	return p;
}
char* print_malloc() //堆空间在进程中一直有效，不会因为函数调用结束而自动释放
{
	char* p;
	p = (char*)malloc(100);
	strcpy_s(p, 100, "I am print_malloc func");
	puts(p);
	return p;
}
int main() {
	char* p;
	p = print_stack();//虽然返回了指针值，但对应的栈空间已经被污染
	puts(p);
	p = print_malloc();
	puts(p);
	free(p);//只有free才会释放堆空间
	return 0;
}