#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}Stack;
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitSqQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}

bool EnQueue(SqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.rear == Q.front) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

void InitStack(Stack& S) {
	S.top = -1;
}

bool Push(Stack& S, ElemType x) {
	if (S.top == MaxSize - 1) {
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

bool Pop(Stack& S, ElemType& x) {
	if (S.top == -1) {
		return false;
	}
	x = S.data[S.top--];
	return true;
}

int main() {
	Stack S;
	InitStack (S);
	int i = 0;
	ElemType x;
	while (i < 3) {
		scanf_s("%d", &x);
		Push(S, x);
		i++;
	}
	ElemType Del;
	while (i > 0) {
		Pop(S, Del);
		printf(" %d", Del);
		i--;
	}
	printf("\n");
	SqQueue Q;
	InitSqQueue(Q);
	bool ret=true;
	ElemType m;
	while (ret) {
		scanf_s("%d", &m);
		ret = EnQueue(Q, m);
		if (ret == false) {
			printf("false\n");
		}
	}
	ret = true;
	while (ret) {
		ret = DeQueue(Q, Del);
		if (ret) {
			printf(" %d",Del);
		}
	}
	return 0;
}