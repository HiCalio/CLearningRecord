#include"Func.h"
int print_star(int i) {
	printf("**************\n");
	printf("printstar %d\n", i);
	return i + 3;
}

void print_message() {
	printf("how do you do\n");
	print_star(6);
}