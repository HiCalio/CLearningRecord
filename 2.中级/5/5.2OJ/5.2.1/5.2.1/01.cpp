#include<stdio.h>
#include<stdlib.h>
typedef char BiElemType;

typedef struct BiNode {
	BiElemType weight;
	struct BiNode* lchild;
	struct BiNode* rchild;
}BiNode, * Bitree;
//二叉树

typedef Bitree ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, tag_t, * ptag_t;
//辅助队列的链表节点

typedef struct {
	LNode* front;
	LNode* rear;
}LinkQueue, tag;
//辅助队列的头尾指针

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
	return true;
}
//出队

void InOrder(Bitree T) {
	if (T) {
		InOrder(T->lchild);
		putchar(T->weight);
		InOrder(T->rchild);
	}
}
//中序遍历

void PostOrder(Bitree T) {
	if (T) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		putchar(T->weight);
	}
}
//后序遍历

void LevelOrder(Bitree T) {
	LinkQueue Q;
	InitialQueue(Q);
	BiNode* p;//储存出队节点
	EnQueue(Q, T);
	while (Q.front != Q.rear) {
		DeQueue(Q, p);
		putchar(p->weight);//等价于printf("%c",p->weight);
		if (p->lchild) {
			EnQueue(Q, p->lchild);
		}
		if (p->rchild) {
			EnQueue(Q, p->rchild);
		}
	}
}
//层序遍历，也是广度优先遍历

int main() {
	BiNode* pnew;//用来指向二叉树的新节点
	Bitree T = NULL;
	char c;//1234567,ASCII码值作为权值
	tag Q;
	ptag_t pcur = NULL;//用来指向辅助队列中正在填充的树节点
	InitialQueue(Q);
	while (scanf_s("%c", &c,1)) {
		if (c == '\n') {
			break;
		}
		pnew = (BiNode*)calloc(1, sizeof(BiNode));//calloc申请的空间大小是两个参数相乘，并赋值为0（即NULL）
		pnew->weight = c;
		EnQueue(Q, pnew);//将新的树节点入队
		if (T == NULL) {
			T = pnew;//根节点单独处理
			pcur = Q.front->next;//pcur指向辅助队列中正在填充的树节点
		}
		else {
			if (pcur->data->lchild == NULL) {
				pcur->data->lchild = pnew;//左孩子为空放入左孩子
			}
			else {
				if (pcur->data->rchild == NULL) {
					pcur->data->rchild = pnew;//右孩子为空放入右孩子
				}
				pcur = pcur->next;//左右孩子填满后pcur指向队列中下一个节点
			}
		}
	}
	InOrder(T);
	printf("\n");
	PostOrder(T);
	printf("\n");
	LevelOrder(T);
	return 0;
}