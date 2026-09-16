#include "fun.h"

void InitialQueue(LinkQueue& Q) {
	LNode* p;
	p = (LNode*)malloc(sizeof(LNode));
	Q.rear = Q.front = p;
	Q.front->next = NULL;
}
//队列初始化

void EnQueue(LinkQueue& Q, ElemType x) {
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
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