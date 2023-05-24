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

Queue q1[10000], q2[10000];
int front1 = 0, rear1 = 0, result1 = 0, front2 = 0, rear2 = 0, result2 = 0;
int visited1[100][100] = { 0, }, visited2[100][100] = { 0, };
char arr[100][100];

int empty1() {
	return front1 == rear1;
}
int empty2() {
	return front2 == rear2;
}

void BFS1(int N, char color) {
	while (!empty1()) {
		int X = q1[front1].X, Y = q1[front1++].Y;
		if (X > 0) {
			if (arr[Y][X - 1] == color && visited1[Y][X - 1] == false) {
				visited1[Y][X - 1] = true;
				q1[rear1].X = X - 1;
				q1[rear1++].Y = Y;
			}
		}
		if (X < N - 1) {
			if (arr[Y][X + 1] == color && visited1[Y][X + 1] == false) {
				visited1[Y][X + 1] = true;
				q1[rear1].X = X + 1;
				q1[rear1++].Y = Y;
			}
		}
		if (Y > 0) {
			if (arr[Y - 1][X] == color && visited1[Y - 1][X] == false) {
				visited1[Y - 1][X] = true;
				q1[rear1].X = X;
				q1[rear1++].Y = Y - 1;
			}
		}
		if (Y < N - 1) {
			if (arr[Y + 1][X] == color && visited1[Y + 1][X] == false) {
				visited1[Y + 1][X] = true;
				q1[rear1].X = X;
				q1[rear1++].Y = Y + 1;
			}
		}
	}
	result1++;
}
void BFS2(int N, char color) {
	while (!empty2()) {
		int X = q2[front2].X, Y = q2[front2++].Y;
		if (X > 0) {
			if (arr[Y][X - 1] == color && visited2[Y][X - 1] == false) {
				visited2[Y][X - 1] = true;
				q2[rear2].X = X - 1;
				q2[rear2++].Y = Y;
			}
		}
		if (X < N - 1) {
			if (arr[Y][X + 1] == color && visited2[Y][X + 1] == false) {
				visited2[Y][X + 1] = true;
				q2[rear2].X = X + 1;
				q2[rear2++].Y = Y;
			}
		}
		if (Y > 0) {
			if (arr[Y - 1][X] == color && visited2[Y - 1][X] == false) {
				visited2[Y - 1][X] = true;
				q2[rear2].X = X;
				q2[rear2++].Y = Y - 1;
			}
		}
		if (Y < N - 1) {
			if (arr[Y + 1][X] == color && visited2[Y + 1][X] == false) {
				visited2[Y + 1][X] = true;
				q2[rear2].X = X;
				q2[rear2++].Y = Y + 1;
			}
		}
	}
	result2++;
}


int main(void) {
	int N;
	char temp[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		for (int j = 0; j < N; j++) {
			arr[i][j] = temp[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited1[i][j] == false) {
				visited1[i][j] = true;
				q1[rear1].X = j;
				q1[rear1++].Y = i;
				BFS1(N, arr[i][j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'G') {
				arr[i][j] = 'R';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited2[i][j] == false) {
				visited2[i][j] = true;
				q2[rear2].X = j;
				q2[rear2++].Y = i;
				BFS2(N, arr[i][j]);
			}
		}
	}

	printf("%d %d", result1, result2);
	return 0;

}