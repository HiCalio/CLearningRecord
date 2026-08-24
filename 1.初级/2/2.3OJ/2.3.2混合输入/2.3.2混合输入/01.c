#include<stdio.h>
int main() {
	int a;
	char b;
	float c;
	scanf_s("%d %c%f", &a, &b, 1, &c);
	printf("%0.2f", a + b + c);
	return 0;
}