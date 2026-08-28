#include<stdio.h>
int step(int n)//递归的核心就是确定递归公式
{//递归一定要有结束条件，且要在递归调用前面
	if (1 == n || 2 == n) {
		return n;
	}
	return step(n - 1) + step(n - 2);
}
int main() {
	int n;
	scanf_s("%d", &n);
	printf("step(%d)=%d\n", n, step(n));
	return 0;
}