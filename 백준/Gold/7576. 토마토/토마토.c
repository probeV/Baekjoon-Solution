#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0

typedef struct Queue {
	int x;
	int y;
}Queue;

Queue q[10000001];
int box[1001][1001];
int front = 0, rear = 0, daycount = 0, day = 0;

int empty() {
	return front == rear;
}

int main(void) {
	int M, N, already=false;
	scanf("%d %d", &M, &N);
	for (int j = 1; j <= N; j++) {
		for (int k = 1; k <= M; k++) {
			scanf("%d", &box[j][k]);
			if (box[j][k] == 1) {
				q[rear].x = k;
				q[rear++].y = j;
			}
			if (box[j][k] == 0) already = true;
		}
	}

	if (already == false) {   //모든 토마토가 익어있는 상태
		printf("0");
		return 0;
	}

	//너비 우선 탐색
	daycount = rear - 1;
	while (!empty()) {
		int X = q[front].x;
		int Y = q[front++].y;
		if (X >= 2) { //왼쪽 토마토
			if (box[Y][X - 1] == 0) {
				box[Y][X - 1] = 1;
				q[rear].x = X - 1;
				q[rear++].y = Y;
			}
		}
		if (X <= M - 1) {  //오른쪽 토마토
			if (box[Y][X + 1] == 0) {
				box[Y][X + 1] = 1;
				q[rear].x = X + 1;
				q[rear++].y = Y;
			}
		}
		if (Y >= 2) {   //아래쪽 토마토
			if (box[Y - 1][X] == 0) {
				box[Y - 1][X] = 1;
				q[rear].x = X;
				q[rear++].y = Y - 1;
			}
		}
		if (Y <= N - 1) {   //위쪽 토마토
			if (box[Y + 1][X] == 0) {
				box[Y + 1][X] = 1;
				q[rear].x = X;
				q[rear++].y = Y + 1;
			}
		}
		if (daycount == front - 1) {
			day++;
			daycount = rear - 1;
		}
	}
		
	//모두 익지 못하는 상황 체크
	for (int j = 1; j <= N; j++) {
		for (int k = 1; k <= M; k++) {
			if (box[j][k] == 0) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", day-1); //모두 익었을 때
	return 0;
}