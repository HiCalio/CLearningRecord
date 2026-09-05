#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack& S) {
	S.top = -1;//top等于-1就是空栈，哪怕数组里面有数据也视为垃圾数据
}
//初始化栈

bool StackEmpty(SqStack S) {
	if (-1 == S.top) {
		return true;
	}
	else {
		return false;
	}
}
//判断栈是否为空

bool Push(SqStack& S, ElemType x) {
	if (S.top == MaxSize) {
		return false;
	}
	S.data[++S.top] = x;//等价于S.top++;S.data[S.top]=x;
	return true;
}
//入栈

bool GetTop(SqStack S,ElemType &m) {
	if (StackEmpty(S)){
		return false;
	}
	m = S.data[S.top];
	return true;
}
//读取栈顶元素

bool Pop(SqStack& S, ElemType& x) {//原数据并不会被删除，只是栈顶指针被改变
	if (StackEmpty(S)) {
		return false;
	}
	x = S.data[S.top--];//等价于m=S.data[S.top];S.top--;
	return true;
}
//弹出栈顶元素

int main() {
	SqStack S;
	InitStack(S);
	ElemType x, m;
	bool flag;
	Push(S, 3);
	Push(S, 4);
	Push(S, 5);
	flag = GetTop(S, m);
	if (flag) {
		printf("Top is %d\n", m);
	}
	Pop(S, x);
	flag = GetTop(S, m);
	if (flag) {
		printf("Top is %d\n", m);
	}
	return 0;
}