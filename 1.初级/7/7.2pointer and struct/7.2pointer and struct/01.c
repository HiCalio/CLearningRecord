#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {
	int age;
	char sex;
	char name[30];
}stu,*pstu;//typedef可以用来起别名,stu等价于struct student, pstu等价于struct student*

typedef int INGETER;//方便后期维护时调整变量类型，可以一下子全变化

int main() {
	pstu p;//也可以用stu* p
	p = (stu*)malloc(sizeof(struct student));
	p->age = 18;
	p->sex = 'F';
	strcpy(p->name, "Liyue");
	printf("%d %c %s\n", p->age, p->sex, p->name);
	return 0;
}