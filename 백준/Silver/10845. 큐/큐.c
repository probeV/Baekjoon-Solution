#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10000

typedef struct QueueType{
	int num;
	int front, near;
	int data[MAX_SIZE];
}QueueType;

void init(QueueType* q) {
	q->front = 0;
	q->near = 0;
	q->num = 0;
}

int empty(QueueType *q) {
	return (q->front == q->near);
}

void push(QueueType* q, int x) {
	q->data[++(q->near)] = x;
	q->num++;
}

int pop(QueueType *q) {
	if (empty(q)) return -1;
	q->num--;
	return q->data[++(q->front)];
}

int size(QueueType *q) {
	return q->num;
}

int front(QueueType* q) {
	if (empty(q)) return -1;
	return q->data[(q->front)+1];
}

int back(QueueType* q) {
	if (empty(q)) return -1;
	return q->data[(q->near)];
}

int main(void) {
	QueueType q;
	int n, x;
	char order[10];
	scanf("%d", &n);
	init(&q);
	for (int i = 0; i < n; i++) {
		scanf("%s", order);
		if (strcmp(order, "push")==0) {
			getchar();
			scanf("%d", &x);
			push(&q, x);
		}
		else if (strcmp(order, "pop")==0) printf("%d\n", pop(&q));
		else if (strcmp(order, "size")==0) printf("%d\n", size(&q));
		else if (strcmp(order, "empty")==0) printf("%d\n", empty(&q));
		else if (strcmp(order, "front")==0) printf("%d\n", front(&q));
		else if (strcmp(order, "back")==0) printf("%d\n", back(&q));
	}
	return 0;
}