#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}Lnode,*Linklist;

void PrintList(Linklist L)
{
	Linklist p;
	p=L->next;
	while (p != NULL)
	{
		printf("%d", p->data);//打印当前结点数据
		p= p->next;//指向下一个结点
		if (p != NULL)
		{
			printf(" ");
		}
	}
	printf("\n");
}

void list_head_insert(Linklist& L) {
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	Linklist s;
	ElemType x;
	scanf_s("%d", &x);
	while (x != 9999) {
		s= (Linklist)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d", &x);
	}
}

void list_tail_insert(Linklist& L) {
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	Linklist s,r;
	r = L;
	ElemType x;
	scanf_s("%d", &x);
	while (x != 9999) {
		s = (Linklist)malloc(sizeof(LNode));
		s->data = x;
		s->next = r->next;
		r->next = s;
		r = s;
		scanf_s("%d", &x);
	}
}

int main() {
	Linklist L,M;
	list_head_insert(L);
	PrintList(L);
	list_tail_insert(M);
	PrintList(M);
	return 0;
}