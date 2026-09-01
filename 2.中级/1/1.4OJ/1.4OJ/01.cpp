#include<stdio.h>
typedef int ElemType;
typedef struct {
	ElemType data[10];
	int length;
}Sqlist;

void Initlist(Sqlist& l) {
	l.data[0] = 1;
	l.data[1] = 2;
	l.data[2] = 3;
	l.length = 3;
}
//初始化顺序表

void Printlist(Sqlist l) {
	int i;
	for (i = 0;i <= l.length - 1;i++) {
		printf("%3d", l.data[i]);
	}
	printf("\n");
}
//打印顺序表

bool Insertlist(Sqlist& L, int i, ElemType element) {
	if (i<1 || i>L.length) {
		return false;
	}
	if (L.length==10) {
		return false;
	}
	int j;
	for (j = L.length;j >= i;j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = element;
	L.length++;
	return true;
}
//顺序表的插入

bool Deletelist(Sqlist& L, int i) {
	if (i<1 || i>L.length) {
		return false;
	}
	int j;
	for (j = i;j <= L.length-1;j++) {
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}
//顺序表的删除

int main() {
	Sqlist L;
	Initlist(L);
	ElemType i;
	scanf_s("%d", &i);
	Insertlist(L, 2, i);
	Printlist(L);
	int pos,ret;
	scanf_s("%d", &pos);
	ret=Deletelist(L, pos);
	if (ret) {
		Printlist(L);
	}else {
		printf("false\n");
	}
	return 0;
}