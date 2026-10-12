#include "fun.h"
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

void PreOrder(Bitree T) {
	if (T) {
		putchar(T->weight);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//先序遍历，也是深度优先遍历

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

int Wpl_PreOrder(Bitree T,int depth) {
	static int wpl = 0;//静态局部变量，程序调用结束后销毁（而不是，而且只初始化一次
	if (T) {
		if (T->lchild == NULL && T->rchild == NULL) {
			wpl += T->weight * depth;
		}
		Wpl_PreOrder(T->lchild,depth+1);
		Wpl_PreOrder(T->rchild,depth+1);
	}
	return wpl;
}
//先序遍历计算带权路径长度

int Wpl(Bitree T) {
	return Wpl_PreOrder(T, 0);
}

int main() {
	BiNode* pnew;//用来指向二叉树的新节点
	Bitree T = NULL;
	char c;//1234567,ASCII码值作为权值
	tag Q;
	ptag_t pcur=NULL;//用来指向辅助队列中正在填充的树节点
	InitialQueue(Q);
	while (scanf_s("%c", &c, 1)) {
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
			if (pcur->data->lchild==NULL) {
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
	printf("-------------PreOrder------------------\n");
	PreOrder(T);
	printf("\n-------------InOrder-------------------\n");
	InOrder(T);
	printf("\n-------------PostOrder-----------------\n");
	PostOrder(T);
	printf("\n-------------LevelOrder----------------\n");
	LevelOrder(T);
	printf("\n-------------Wpl-----------------------\n");
	printf("%d\n", Wpl(T));
	return 0;
}