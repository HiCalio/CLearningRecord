#include<stdio.h>
#include<stdlib.h>
typedef char BiElemType;

typedef struct BiNode {
	BiElemType weight;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode,*Bitree;
//二叉树

typedef Bitree ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,tag_t,*ptag_t;
//辅助队列的链表节点

typedef struct{
	LNode* front;
	LNode* rear;
}LinkQueue,tag;
//辅助队列的头尾指针

void InitialQueue(LinkQueue& Q);
bool DeQueue(LinkQueue& Q, ElemType& X);
void EnQueue(LinkQueue& Q,ElemType X);