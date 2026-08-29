#include<stdio.h>
#include<string.h>
typedef struct student {
	int num;
	char name[20];
	char sex;
}stu;
int main() {
	stu s = { 0 };
	scanf_s("%d %s %c", &s.num, s.name, 20,&s.sex,1);
	printf("%d %s %c\n", s.num, s.name, s.sex);
	return 0;
}