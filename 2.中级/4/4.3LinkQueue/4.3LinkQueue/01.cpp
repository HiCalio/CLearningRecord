#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode;
typedef struct {
	struct LNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LNode*)malloc(sizeof(LNode));
	Q.front->next = NULL;
}
//初始化队列（链表实现法）

void EnQueue(LinkQueue& Q, ElemType x) {
	LNode* s= (LNode*)malloc(sizeof(LNode));//s作为局部指针变量，函数调用结束就会自动销毁释放内存，但malloc出来的节点所占的内存空间不会自动销毁
	s->data = x;
	s->next = NULL;//别忘了链表的结束标志
	Q.rear->next = s;//从队尾入队
	Q.rear = s;
}
//入队

bool DeQueue(LinkQueue& Q, ElemType& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	LNode* p = Q.front->next;
	x = p->data;
	if (Q.rear == p) {
		Q.rear = Q.front;//删除最后一个节点时要将rear指向头节点
	}
	Q.front->next = p->next;
	free(p);
}
//出队

int main() {
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ElemType x;
	DeQueue(Q, x);
	printf("%d\n", x);
	DeQueue(Q, x);
	printf("%d\n", x);
	DeQueue(Q, x);
	printf("%d\n", x);
	return 0;
}