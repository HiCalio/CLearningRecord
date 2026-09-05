#include<stdio.h>
#include<stdlib.h>
#define MaxSize 6

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];//最多存Maxsize-1个元素
	int front, rear;//队列头，队列尾指针;默认队头出，队尾进
}SqQueue;

void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
//初始化循环队列

bool IsEmpty(SqQueue Q) {
	return Q.front == Q.rear;
}
//判断是否为空

bool EnQueue(SqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return false;//队列已满
	}
	Q.data[Q.rear] = x;//队尾入队
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
//入队

bool DeQueue(SqQueue& Q, ElemType &x) {
	if (IsEmpty(Q)){
		return false;//队列为空
	}
	x = Q.data[Q.front];//队头出队
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
//出队

int main(){
	SqQueue Q;
	ElemType x;
	InitQueue(Q);
	bool ret;
	ret=IsEmpty(Q);
	if (ret) {
		printf("Queue is empty\n");
	}
	else {
		printf("Queue is not empty\n");
	}
	int i = 1;
	while (ret) {
		ret= EnQueue(Q, i);
		if (ret) {
			printf("EnQueue %d Successfully\n",i);
		}
		else {
			printf("EnQueue %d Failed\n", i);
		}
		i++;	
	}
	DeQueue(Q,x);
	printf("DeQueue %d Successfully\n", x);
	return 0;
}