#include <stdio.h>
#define MaxSize 50
typedef int ELemtype;
typedef struct {
	ELemtype data[MaxSize];
	int length;
}Sqlist;
void PrintList(Sqlist l) {
	for (int i = 0;i <= l.length - 1;i++) {
		printf(" %d", l.data[i]);
	}
}
bool ListInsert(Sqlist &l,int pos,ELemtype element){
	if (pos<1 || pos>l.length) {
		return false;
	}
	if (l.length == MaxSize) {
		return false;
	}
	for (int i = l.length;i >= pos;i--) {//插入是从尾部开始移动元素
		l.data[i] = l.data[i - 1];
	}
	l.data[pos - 1] = element;
	l.length++;
	return true;
}
int main() {
	Sqlist l;
	bool ret;
	l.data[0] = 1;
	l.data[1] = 2;
	l.data[2] = 3;
	l.length = 3;
	ret=ListInsert(l, 2, 4);
	if (ret) {
		printf("insert sqlist success\n");
		PrintList(l);
	}
	else {
		printf("insert sqlist failed\n");
	}
	return 0;
}