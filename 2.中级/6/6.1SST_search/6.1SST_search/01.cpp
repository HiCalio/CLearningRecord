#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElemType;

typedef struct SSTNode {
	ElemType* elem;
	int Tablength;
}SSTable;
//动态数组

void ST_Init(SSTable& ST, int len) {
	ST.Tablength = len+1;
	ST.elem = (ElemType*)malloc((len + 1) * sizeof(ElemType));
	int i;
	srand(time(NULL));
	for (i = 1;i < ST.Tablength;i++) {
		ST.elem[i] = rand() % 100;
	}
}

void ST_print(SSTable ST) {
	int i;
	for (i = 1;i < ST.Tablength;i++) {
		printf("%-3d", ST.elem[i]);
	}
	printf("\n");
}

int search(SSTable ST, ElemType x) {
	ST.elem[0] = x;
	int i;
	for (i = ST.Tablength - 1;ST.elem[i] != x;i--);
	return i;
}

int main() {
	SSTable ST;
	ST_Init(ST, 10);
	ST_print(ST);
	ElemType key;
	scanf_s("%d", &key, 1);
	int pos;
	pos = search(ST, key);
	if (pos) {
		printf("%-2d\n", pos);
	}
	else {
		printf("false\n");
	}
	return 0;
}