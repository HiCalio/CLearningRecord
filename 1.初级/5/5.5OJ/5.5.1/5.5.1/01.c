#include<stdio.h>
int change(int* j) 
{
	*j = *j / 2;
}

int main() {
	int i;
	scanf_s("%d", &i);
	change(&i);
	printf("%d", i);
	return 0;
}