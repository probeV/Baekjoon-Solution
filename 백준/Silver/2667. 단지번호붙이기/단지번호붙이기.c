#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

typedef  struct Queue {
	int X;
	int Y;
}Queue;

Queue q[625];
int front = 0, rear = 0, result = 0;
int visited[25][25] = { 0, }, num[20];

int empty() {
	return front == rear;
}

void BFS(int N, int **arr) {
	int anum = 0;
	while (!empty()) {
		anum++;
		int X = q[front].X, Y = q[front++].Y;
		if (X > 0) {
			if (arr[Y][X - 1] == 1 && visited[Y][X - 1] == false) {
				visited[Y][X - 1] = true;
				q[rear].X = X - 1;
				q[rear++].Y = Y;
			}
		}
		if (X < N - 1) {
			if (arr[Y][X + 1] == 1 && visited[Y][X + 1] == false) {
				visited[Y][X + 1] = true;
				q[rear].X = X + 1;
				q[rear++].Y = Y;
			}
		}
		if (Y > 0) {
			if (arr[Y-1][X] == 1 && visited[Y-1][X] == false) {
				visited[Y - 1][X] = true;
				q[rear].X = X;
				q[rear++].Y = Y-1;
			}
		}
		if (Y < N - 1) {
			if (arr[Y+1][X] == 1 && visited[Y+1][X] == false) {
				visited[Y + 1][X] = true;
				q[rear].X = X;
				q[rear++].Y = Y+1;
			}
		}
	}
	num[result] = anum;
	result++;
}

int main(void) {
	char tempstring[25];
	int N;
	scanf("%d", &N);
	int** arr = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * N);
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", tempstring);
		for (int j = 0; j < N; j++) {
			arr[i][j] = tempstring[j]-'0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				visited[i][j] = true;
				q[rear].X = j;
				q[rear++].Y = i;
				BFS(N, arr);
			}
		}
	}
	printf("%d\n", result);
	int temp;
	for (int i = 0; i < result-1; i++)
	{
		for (int j = 0; j < result - i-1; j++)
		{
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < result; i++) {
		printf("%d\n", num[i]);
	}
	return  0;
}