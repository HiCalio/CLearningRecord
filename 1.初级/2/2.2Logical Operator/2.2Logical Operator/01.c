#include<stdio.h>
int main() {
	int i = 0;
	printf("you can't find me!\n");
	i&& printf("you can't see me!\n");//短路运算，当&&前面的值为假时，不会再执行后面的运算；可用于简洁代码
	while (scanf_s("%d", &i))
	{
		!!i-1&& printf("you find me!\n");//!!逻辑非优先级高于算术运算符，逻辑与&&和逻辑或||优先级小于关系运算符；
	}
	return 0;
}