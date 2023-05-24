#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define true 1
#define false 0

int top = -1;
char  stack[MAX_SIZE];

int Operator(char x) {
	switch (x){
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '/': case '*': return 2;
	}
}

void push(char x) {
	stack[++top] = x;
}

char pop() {
	return stack[top--];
}

char peek() {
	return stack[top];
}

int main(void) {
	char arr[MAX_SIZE], temp;
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++) {
		temp = arr[i];
		switch (temp){
		case '+': case'-': case'/': case'*':
			while (top != -1 && Operator(temp) <= Operator(peek())) {
				printf("%c", pop());
			}
			push(temp);
			break;
		case '(':
			push(arr[i]);
			break;
		case ')':
			temp = pop();
			while (temp != '(') {
				printf("%c", temp);
				temp = pop();
			}
			break;
		default:
			printf("%c", arr[i]);
			break;
		}
	}
	for (; top != -1; top--) printf("%c", stack[top]);
	return 0;
}