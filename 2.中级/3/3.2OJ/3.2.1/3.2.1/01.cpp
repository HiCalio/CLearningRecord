#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}Lnode,*Linklist;

void PrintList(Linklist L)
{
	L = L->next;
	while (L != NULL)
	{
		printf("%3d", L->data);//打印当前结点数据
		L = L->next;//指向下一个结点
	}
	printf("\n");
}

void list_tail_insert(Linklist& L) {
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* p, * r;
	r = L;
	ElemType x;
	scanf_s("%d", &x);
	while (x != 9999) {
		p = (Linklist)malloc(sizeof(LNode));
		p->data = x;
		p->next = r->next;
		r->next = p;
		r = p;
		scanf_s("%d", &x);
	}
}

Linklist GetElem(Linklist L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 0;
	while (L && j < i) {
		L = L->next;
		j++;
	}
	return L;
}

bool ListDelete(Linklist L, int i) {
	Linklist p = GetElem(L, i - 1);
	if (p == NULL) {
		return false;
	}
	Linklist q = p->next;
	if (q == NULL) {
		return false;
	}
	p->next = q->next;
	free(q);
	return true;
}

bool ListInsert(Linklist L, ElemType x, int i) {
	Linklist p = GetElem(L, i - 1);
	if (p == NULL) {
		return false;
	}
	Linklist q= (Linklist)malloc(sizeof(LNode));
	q->data = x;
	q->next = p->next;
	p->next = q;
	return true;
}

int main() {
	Linklist L;
	list_tail_insert(L);
	Linklist q;
	q = GetElem(L, 2);
	if (q == NULL) {
		printf("Failure\n");
	}
	else {
		printf("%d\n", q->data);
	}
	ListInsert(L, 99, 2);
	PrintList(L);
	ListDelete(L, 4);
	PrintList(L);
	return 0;
}