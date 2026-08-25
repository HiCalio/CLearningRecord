#include<stdio.h>
#include<string.h>
int main() {
	char a[20], backup_a[20] =" ";
	int length = 0,result=0;
	gets(a);
	length = strlen(a);
	for (int i = 0;i < length;i++) {
		backup_a[length - i - 1] = a[i];
	}
	result = strcmp(a, backup_a);
	if (result < 0) {
		printf("%d", -1);
	}
	else if(result>0){
		printf("%d", 1);
	}
	else {
		printf("%d", 0);
	}
	return 0;
}