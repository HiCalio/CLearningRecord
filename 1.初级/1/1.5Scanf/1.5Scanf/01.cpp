#include<stdio.h>
int main()
{//标准输入缓冲区是空的scanf才会阻塞
	int i,ret;
	float f;
	char c;
	//scanf_s("%d", &i);
	//printf("i=%d\n", i);
	////fflush(stdin); 清空标准输入缓冲区，但移植性差，不要用
	//scanf_s(" %c", &c,1); //%前面打一个空格的作用：不断读入输入流，跳过所有连续空白字符，将碰到的
	//					  //第一个不是空白的字符赋予到字符/字符串变量
	//printf("c=%c\n", c);
	ret=scanf_s("%d %c%f",&i, &c,1,&f);//scanf批量输入。其中ret为scanf的返回值，代表成功匹配的个数
	printf("i=%d  c=%c  f=%5.2f\n", i,c,f);
	return 0;
}