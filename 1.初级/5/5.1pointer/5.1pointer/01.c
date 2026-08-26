#include<stdio.h>
void change(int j) {
	j = 5;
}
void change2 (int *j) {
	*j = 5;//*j就是一个指针变量，通过间接访问主函数栈空间中变量i所在的内存空间
}
int main() {
	int i = 5;
	int a = 10;
	int* i_pointer=&i;//定义了一个指针变量，i_pointer是指针变量名；指针和变量类型要匹配；
	printf("i=%d\n", i);//直接访问
	printf("*i_pointer=%d\n", *i_pointer);//间接访问；注意区分计组中的间接寻址
	printf("before change a=%d\n", a);
	change(a);//C语言的函数调用是值传递，实参赋值给形参；效果相当于j=i
	printf("after change a=%d\n", a);
	printf("before change2 a=%d\n", a);
	change2(&a);//C语言的函数调用仍然是值传递；但此时效果相当于*j=&i
	printf("after change2 a=%d\n", a);
	return 0;
}