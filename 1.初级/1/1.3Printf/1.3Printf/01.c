#include<stdio.h>
int main()
{
	int i = 10;
	float f = 93.2;
	printf("student number=%-5d  score=%5.2f\n", i, f);
	i = 1000;
	f = 96.3;
	printf("student number=%-5d  score=%5.2f\n", i, f);
	printf("%10s\n", "END");
	return 0;
}