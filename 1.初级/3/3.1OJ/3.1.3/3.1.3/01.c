#include<stdio.h>
int main() {
	int rmb_10, rmb_5, rmb_2, rmb_1,sum=0,count=0,a=0;
	for (rmb_10 = 1;rmb_10<=10;rmb_10++) {
		for (rmb_5 = 1;rmb_5 <= 20;rmb_5++) {
			for (rmb_2 = 1;rmb_2 <= 50;rmb_2++) {
				for (rmb_1 = 1;rmb_1 <= 100;rmb_1++) {
					sum = 10 * rmb_10 + 5 * rmb_5 + 2 * rmb_2 + 1 * rmb_1;
					a = rmb_10 + rmb_5 + rmb_2 + rmb_1;
					if (sum == 100&&a==40){
					count = count + 1;
					}
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}