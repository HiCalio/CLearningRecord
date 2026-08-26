#include<stdio.h>
#include<stdlib.h>//malloc要使用的头文件
#include<string.h>
int main(){
	int size;
	char* p;
	scanf_s("%d", &size);//别忘记字符串还需要一个字节存结束符
	p = (char*)malloc(size+1);//malloc返回的是void*无类型指针(无法偏移），需要强制类型转换
	strcpy_s(p, size+1, "malloc success");
	puts(p);
	free(p);//free时必须使用malloc申请时返回的指针值，不能偏移,如果要释放，必须先将指针偏移回原来的地址或者使用一个临时指针
	printf("free success\n");
	return 0;
}