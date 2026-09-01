#include <stdio.h>
#define MaxSize 50
typedef int ELemtype;
typedef struct {
	ELemtype data[MaxSize];
	int length;
}Sqlist;
//顺序表的声明（静态存储）

void PrintList(Sqlist l) {
	for (int i = 0;i <= l.length - 1;i++) {
		printf(" %d", l.data[i]);
	}
	printf("\n");
}
//打印顺序表

bool ListInsert(Sqlist& l, int pos, ELemtype element) {
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
//顺序表的插入

bool ListDelete(Sqlist& l, int i, ELemtype& del) {
	if (i<1 || i>l.length) {
		return false;
	}
	del = l.data[i-1];
	for (int j = i;j < l.length;j++) {
		l.data[j - 1] = l.data[j];
	}
	l.length--;
	return true;
}
//顺序表的删除

int locatelist(Sqlist l, ELemtype element) {
	int i;
	for (i = 0;i <= l.length - 1;i++) {
		if (element == l.data[i]) {
			return i+1;
		}
	}
	return 0;//循环结束没找到
}
//顺序表的查找

int main() {
	Sqlist l;
	bool ret;
	ELemtype del;
	l.data[0] = 1;
	l.data[1] = 2;
	l.data[2] = 3;
	l.length = 3;
	ret = ListInsert(l, 2, 4);
	if (ret) {
		printf("insert sqlist success\n");
		PrintList(l);
	}
	else {
		printf("insert sqlist failed\n");
	}
	ret = ListDelete(l, 1, del);
	if (ret) {
		printf("delete sqlist success\n");
		printf("del element=%d\n",del);
		PrintList(l);
	}else {
		printf("delete sqlist failed\n");
	}
	int pose;
	pose = locatelist(l, 4);
	if (pose) {
		printf("find this element\n");
		printf("position of element=%d\n", pose);
	}
	else {
		printf("Don't find this element\n");
	}
	return 0;
}