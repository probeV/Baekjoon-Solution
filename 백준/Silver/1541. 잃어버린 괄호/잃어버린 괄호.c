#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

char queue[51];
int stack1[51], stack2[51], top1 = -1, top2 = -1;
int front = 0, rear = 0, visitedminus=false;

int integer() {
	int N = rear - front - 1, result = 0;
	for (; N >= 0; N--) {
		result = result + (queue[front++]-'0') * pow(10, N);
	}
	return result;
}

void plus() {
	stack1[++top1] = integer();
	front++;
}

void minus() {
	stack2[++top2] = integer();
	front++;
}

int main(void) {
	scanf("%s", queue);
	int len = strlen(queue), result1 = 0, result2 = 0;
	while (front < len) {
		if (visitedminus == false && (queue[rear] == '+' || queue[rear] == '-' || queue[rear] == '\0')) {
			plus();
			if(queue[rear] == '-')	visitedminus = true;
		}
		else if (visitedminus==true && (queue[rear] == '+' || queue[rear] == '-' || queue[rear] == '\0')) {
			minus();
		}
		rear++;
	}
	while (top1 != -1) {
		result1 = result1 + stack1[top1--];
	}
	while (top2 != -1) {
		result2 = result2 + stack2[top2--];
	}
	printf("%d", result1 - result2);
	return 0;
}
