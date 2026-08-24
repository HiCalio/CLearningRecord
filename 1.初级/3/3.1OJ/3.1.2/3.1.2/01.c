#include<stdio.h>
int main() {
	int n,result=1;
	scanf_s("%d", &n);
	int i = 1;
	while (i <= n)
	{
		result = result * i;
		i++;
	}
	printf("%d\n", result);
	return 0;
}