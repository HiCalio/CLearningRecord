#include<stdio.h>
int main() {
	int length, count=0;
	scanf_s("%d", &length);
	int a[100];
	for (int i = 0;i < length;i++) {
		scanf_s("%d", &a[i]);
		if (a[i] == 2) {
			count += 1;
		}
	}
	printf("%d", count);
	return 0;
}