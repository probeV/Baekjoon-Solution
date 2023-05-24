#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
int top, finish;
char stack[50];

int  empty() {
	if (top == -1) return true;
	return false;
}

void pop() {
	if (empty() || stack[top] != '(') {
		finish = true;
	}
	else top-- ;
}

void push(char x) {
	stack[++top] = x;
}

int main(void) {
	int num;
	char arr[50];
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s", arr);
		finish = false; top = -1;
		for (int j = 0; j < strlen(arr) && finish == false; j++) {
			if (arr[j] == ')') {
				pop();
			}
			else {
				push(arr[j]);
			}
		}
		if (finish == true || top != -1) {
			printf("NO\n");
		}
		else if (finish == false && top == -1) printf("YES\n");
	}
	return 0;
}

