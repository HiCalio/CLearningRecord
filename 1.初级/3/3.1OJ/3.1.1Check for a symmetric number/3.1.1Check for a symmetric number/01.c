#include<stdio.h>
int main() {
	int a,b=0,c;
	scanf_s("%d", &a);
	c = a;
	int i = sizeof(a);
	while (i >= 0) {
		b = b*10+a % 10;//提取a的最低位放在b的最高位上
		a = a / 10;//去除最低位
		i--;
	}
	if (b == c) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	return 0;
}