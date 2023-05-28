#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

int q[100000], list[101] = { 0, }, visited[101] = { 0, };
int front = 0, rear = 0, temp = 0, result = 0;;

int empty() {
	return front == rear;
}

void BFS() {
	temp = rear;
	while (!empty()) {
		int x = q[front++];
		if (x == 100) break;


		for (int i = x; i <= x + 6; i++) {
			if (list[i] != false) {
				q[rear++] = list[i];
			}
			else if(visited[i]==false) {
				visited[i] = true;
				q[rear++] = i;
			}
		}


		if (front == temp) {
			result++;
			temp = rear;
		}
	}
}

int main(void) {
	int N, M, n1, n2;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &n1, &n2);
		list[n1] = n2;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &n1, &n2);
		list[n1] = n2;
	}
	q[rear++] = 1;
	BFS();
	printf("%d", result);
	return 0;
}