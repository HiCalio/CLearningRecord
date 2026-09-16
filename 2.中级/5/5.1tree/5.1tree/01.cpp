#include "fun.h"
void LevelOrder(Bitree T) {
	LinkQueue Q;
	InitialQueue(Q);
	BiNode* p;//储存出队节点
	EnQueue(Q, T);
	while (Q.front != Q.rear) {
		DeQueue(Q, p);
		putchar(p->c);//等价于printf("%c",p->c);
		if (p->lchild) {
			EnQueue(Q, p->lchild);
		}
		if (p->rchild) {
			EnQueue(Q, p->rchild);
		}
	}
}

int main() {
	BiNode* pnew;//用来指向二叉树的新节点
	Bitree T = NULL;
	char c;//abcdefghij
	tag Q;
	ptag_t pcur=NULL;//用来指向辅助队列中正在填充的树节点
	InitialQueue(Q);
	while (scanf_s("%c", &c, 1)) {
		if (c == '\n') {
			break;
		}
		pnew = (BiNode*)calloc(1, sizeof(BiNode));//calloc申请的空间大小是两个参数相乘，并赋值为0（即NULL）
		pnew->c = c;
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
	LevelOrder(T);
	return 0;
}