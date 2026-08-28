#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student 
{
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
};//结构体类型申明末尾一定要有分号，本质上还是一条语句，只不过约定俗成放在函数体外声明

int main() {
	struct student s = { 1001,"liyue",'M',20,85.4,"HangZhou" };
	printf("%04d %s %c %2d %5.2f %s\n", s.num, s.name, s.sex, s.age, s.score, s.addr);
	//除整体赋值以外（如s1=s)结构体不能直接访问整体，只能一个个访问内部成员
	struct student array[3];
	for (int i = 0;i < 3;i++) {
		scanf("%d%s %c%d%f%s", &array[i].num, array[i].name, &array[i].sex,&array[i].age, &array[i].score, array[i].addr);
	}//结构体数组输入,1001 liyue M 20 85.4 HangZhou
	for (int i = 0;i < 3;i++) {
		printf("%04d %-8s %c%5d%8.2f %s\n", array[i].num, array[i].name, array[i].sex, array[i].age, array[i].score, array[i].addr);
	}//结构体数组输出
	return 0;
}