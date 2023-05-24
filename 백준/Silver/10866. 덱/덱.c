#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 10000

typedef struct Deque {
	int num;
	int front, rear;
	int data[MAX_SIZE];
}Deque;

int empty(Deque* d) {
	return d->front == d->rear;
}

void init(Deque * d) {
	d->num = 0;
	d->front = 0;
	d->rear = 0;
}

void push_frontX(Deque* d, int x) {
	d->data[d->front] = x;
	d->front = (MAX_SIZE + d->front - 1) % MAX_SIZE;
	d->num++;
}

void  push_backX(Deque* d, int x) {
	d->rear = (d->rear + 1) % MAX_SIZE;
	d->data[d->rear] = x;
	d->num++;
}

int pop_front(Deque* d) {
	if (empty(d)) return -1;
	d->front = (d->front + 1) % MAX_SIZE;
	d->num--;
	return d->data[d->front];
}

int pop_back(Deque* d) {
	int temp;
	if (empty(d)) return -1;
	temp = d->data[d->rear];
	d->rear = (MAX_SIZE + d->rear - 1) % MAX_SIZE;
	d->num--;
	return temp;
}

int size(Deque* d) {
	return d->num;
}

int front(Deque* d) {
	if (empty(d)) return -1;
	return d->data[(d->front + 1) % MAX_SIZE];
}

int back(Deque* d) {
	if (empty(d)) return -1;
	return d->data[d->rear];
}

int main(void) {
	int num, order[20],x ;
	Deque d;
	init(&d);
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s", order);
		getchar();
		if (strcmp(order, "push_front") == 0) {
			scanf("%d", &x);
			getchar();
			push_frontX(&d, x);
		}
		else if (strcmp(order, "push_back") == 0) {
			scanf("%d", &x);
			getchar();
			push_backX(&d, x);
		}
		else if (strcmp(order, "pop_front") == 0) printf("%d\n", pop_front(&d));
		else if (strcmp(order, "pop_back") == 0) printf("%d\n", pop_back(&d));
		else if (strcmp(order, "size") == 0) printf("%d\n", size(&d));
		else if (strcmp(order, "empty") == 0) printf("%d\n", empty(&d));
		else if (strcmp(order, "front") == 0) printf("%d\n", front(&d));
		else if (strcmp(order, "back") == 0) printf("%d\n", back(&d));
	}
	return 0;
}