#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef int ElemType;

typedef struct STNode {
	ElemType* elem;
	int Tablength;
}STable;
//动态数组

void ST_Init(STable& ST, int len) {
	ST.Tablength = len + 1;
	ST.elem = (ElemType*)malloc((len + 1) * sizeof(ElemType));
	int i;
	srand(time(NULL));
	for (i = 1;i < ST.Tablength;i++) {
		ST.elem[i] = rand() % 100;
	}
}

void ST_print(STable ST) {
	int i;
	for (i = 1;i < ST.Tablength;i++) {
		printf("%-3d", ST.elem[i]);
	}
	printf("\n");
}

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void Bubble(ElemType* A, int n) {
	int i=0, j;
	bool flag = true;
	while (flag&&i < n - 1) {
		flag = false;
		for (j = n - 1;j > i;j--) {
			if (A[j - 1] > A[j]) {
				swap(A[j - 1], A[j]);
				flag = true;
			}
		}
		i++;
	}
}

int main() {
	STable ST;
	ST_Init(ST, 10);
	ST_print(ST);
	Bubble(ST.elem, 10);
	ST_print(ST);
	return 0;
}