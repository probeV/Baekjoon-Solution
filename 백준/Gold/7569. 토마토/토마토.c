#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0

typedef struct Queue {
	int x;
	int y;
	int z;
}Queue;

Queue q[1000001];
int box[101][101][101];
int front = 0, rear = 0, daycount = 0, day = 0;

int empty() {
	return front == rear;
}

int main(void) {
	int M, N, H, already=false;
	scanf("%d %d %d", &M, &N, &H);
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				scanf("%d", &box[j][k][i]);
				if (box[j][k][i] == 0) already = true;
			}
		}
	}
	if (already == false) {   //모든 토마토가 익어있는 상태
		printf("0");
		return 0;
	}

	//너비 우선 탐색
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (box[j][k][i] == 1) {
					q[rear].x = k;
					q[rear].y = j;
					q[rear++].z = i;
				}
			}
		}
	}
	daycount = rear - 1;
	while (!empty()) {
		int X = q[front].x;
		int Y = q[front].y;
		int Z = q[front++].z;
		if (Z >= 2) {  //한칸 위 토마토 익음
			if (box[Y][X][Z - 1] == 0) {
				box[Y][X][Z - 1] = 1;
				q[rear].x = X;
				q[rear].y = Y;
				q[rear++].z = Z - 1;
			}
		}
		if (Z <= H - 1) {  //한칸 아래 토마토 익음
			if (box[Y][X][Z + 1] == 0) {
				box[Y][X][Z + 1] = 1;
				q[rear].x = X;
				q[rear].y = Y;
				q[rear++].z = Z + 1;
			}
		}
		if (X >= 2) { //왼쪽 토마토
			if (box[Y][X - 1][Z] == 0) {
				box[Y][X - 1][Z] = 1;
				q[rear].x = X - 1;
				q[rear].y = Y;
				q[rear++].z = Z;
			}
		}
		if (X <= M - 1) {  //오른쪽 토마토
			if (box[Y][X + 1][Z] == 0) {
				box[Y][X + 1][Z] = 1;
				q[rear].x = X + 1;
				q[rear].y = Y;
				q[rear++].z = Z;
			}
		}
		if (Y >= 2) {   //아래쪽 토마토
			if (box[Y - 1][X][Z] == 0) {
				box[Y - 1][X][Z] = 1;
				q[rear].x = X;
				q[rear].y = Y - 1;
				q[rear++].z = Z;
			}
		}
		if (Y <= N - 1) {   //위쪽 토마토
			if (box[Y + 1][X][Z] == 0) {
				box[Y + 1][X][Z] = 1;
				q[rear].x = X;
				q[rear].y = Y + 1;
				q[rear++].z = Z;
			}
		}
		if (daycount == front - 1) {
			day++;
			daycount = rear - 1;
		}
	}
		

	for (int i = 1; i <= H && already == true; i++) {  //모두 익지 못하는 상황 체크
		for (int j = 1; j <= N && already == true; j++) {
			for (int k = 1; k <= M && already == true; k++) {
				if (box[j][k][i] == 0) already = false;
			}
		}
	}
	if (already == false) {
		printf("-1");
		return 0;
	}
	printf("%d", day-1); //모두 익었을 때
	return 0;
}