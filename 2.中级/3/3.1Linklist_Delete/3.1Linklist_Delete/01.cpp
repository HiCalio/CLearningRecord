#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}LNode, * Linklist;//Lnode*和Linklist完全等价，都是结构体指针

void list_head_insert(LNode*& L) {
	L = (Linklist)malloc(sizeof(LNode));//申请头节点，头指针指向头节点
	L->next = NULL;
	ElemType x;
	Lnode* s;//工作指针
	scanf_s("%d", &x);
	while (x != 9999) {//9999只是作为结束的标志，不应被读入
		s = (Linklist)malloc(sizeof(LNode));//s指向新申请的节点
		s->data = x;
		s->next = L->next;//s的next指向原先的第一个节点
		L->next = s;//新节点成为第一个节点
		scanf_s("%d", &x);//最后读可以让9999不会被读入
	}
}
//申请头节点以及头插法构造链表

void list_tail_insert(Linklist& L) {
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	ElemType x;
	scanf_s("%d", &x);
	LNode* s, * r;//r作为尾指针，应当始终指向尾节点；s是用于指向新申请的节点
	r = L;//一开始头指针和尾指针都指向头节点
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = r->next;
		r->next = s;
		r = s;//将尾指针移到新的尾节点，这一步是和头插法的关键区别，相当于每次都在最后一个节点进行“头插”
		scanf_s("%d", &x);
	}
}
//尾插法构造链表

void print_linklist(Linklist L) {
	L = L->next;
	while (L != NULL) {
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}
//打印链表

LNode* Getelem(Linklist L, int pos) {
	int j = 0;
	if (pos < 0) {
		return NULL;
	}
	while (L && j < pos) {//链表不为空且还没到指定位置
		L = L->next;
		j++;
	}
	return L;
}
//按位置查找链表

Linklist LocateElem(Linklist L, ElemType x) {
	while (L) {
		if (L->data == x) {
			return L;
		}
		L = L->next;
	}
	return NULL;
}
//按值查找链表元素

bool ListInsert(Linklist L, int Pos, ElemType x) {//没有改变头指针，所以不需要&L
	LNode* p = Getelem(L, Pos - 1);
	if (NULL == p) {
		return false;
	}
	LNode* q;
	q = (Linklist)malloc(sizeof(LNode));//千万不要忘记给新的指针变量分配内存空间或者令它指向已有的内存空间，不然就是野指针
	q->data = x;//只有有了指向的内存空间才可以填数据	
	q->next = p->next;
	p->next = q;
	return true;
}
//在第i个位置插入元素

bool ListDelete(Linklist L,int i) {//不改变L的头指针，不需要&L
	Linklist p = Getelem(L, i - 1);
	if (p == NULL) {
		return false;//i的位置不合法
	}
	Linklist q = p->next;
	if (q == NULL) {
		return false;//i的位置不合法
	}
	p->next = q->next;
	free(q);
	return true;
}
//删除第i个节点

int main() {
	Linklist L, M, search;
	list_head_insert(L);
	print_linklist(L);
	//list_tail_insert(M);
	//print_linklist(M);
	//search = Getelem(L, 2);
	//if (search != NULL) {
	//	printf("Succeed in searching by serial number\n");
	//	printf("%d\n", search->data);
	//}
	//search = LocateElem(L, 6);
	//if (search != NULL) {
	//	printf("Succeed in searching by value\n");
	//	printf("%d\n", search->data);
	//}
	ListDelete(L, 3);
	print_linklist(L);
	return 0;
}