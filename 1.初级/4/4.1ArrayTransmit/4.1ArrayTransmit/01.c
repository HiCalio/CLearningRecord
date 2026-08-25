#include<stdio.h>
void print(int a[],int length)//数组名传递到子函数时，子函数的形参接受到的是数组的起始地址（指针），无法传递数组长度
{
	int i = 0;
	for (i = 0;i < length;i++) //动态输出数组元素
	{
		printf("%3d", a[i]);
	}
}

int main() {
	int a[5] = { 1,2,3,4,5 };
	print(a,5);
	return 0;
}