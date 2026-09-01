#include<stdio.h>
#include<stdlib.h>
#define Initial 50
typedef int Elemtype;

typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}Lnode,*Linklist;

bool Initlist(Linklist &L) {
	L = (LNode*)malloc(Initial * sizeof(LNode));
	L->next = NULL;
	return true;
}
//链表的初始化

int main() {
	Linklist p;
	LNode* q;
	Initlist(p);
	q = p->next;
	return 0;
}