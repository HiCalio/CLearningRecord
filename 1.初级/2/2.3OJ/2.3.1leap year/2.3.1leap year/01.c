#include<stdio.h>
int main() {
	int x;
	while (scanf_s("%d", &x)) {
		if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) {
			printf("yes\n");
		}
		else {
		printf("no\n");
		}
	}
	return 0;
}