#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

typedef struct XY {
	int x;
	int y;
}XY;

int Fishnum[7] = { 0, }, Field[21][21];
XY Fish[7][401];
int BabySharcksize = 2, sizeupcount = 0, resulttime = 0;
XY BabySharck;
XY Targetfish;

XY q[401];
int front = 1, rear = 1;

int empty() {
	return front == rear;
}

void BFS(int N) {
	while (true) {

		//타겟 초기화
		Targetfish.x = 0; Targetfish.y = 0;

		//Distance 배열에 상어가 갈 수 있는 곳 거리 모두 표시
		int Distance[21][21] = { 0, };
		front = 1;
		rear = 1;
		q[rear].x = BabySharck.x;
		q[rear++].y = BabySharck.y;
		int distancecount = rear - 1, distance = 1;
		while (!empty()) {  //BFS 이용
			int X = q[front].x;
			int Y = q[front++].y;
			if (X >= 2) {
				if (Field[Y][X - 1] <= BabySharcksize && Distance[Y][X - 1] == 0) {
					Distance[Y][X - 1] = distance;
					q[rear].x = X - 1;
					q[rear++].y = Y;
				}
			}
			if (X <= N - 1) {
				if (Field[Y][X + 1] <= BabySharcksize && Distance[Y][X + 1] == 0) {
					Distance[Y][X + 1] = distance;
					q[rear].x = X + 1;
					q[rear++].y = Y;
				}
			}
			if (Y >= 2) {
				if (Field[Y - 1][X] <= BabySharcksize && Distance[Y - 1][X] == 0) {
					Distance[Y - 1][X] = distance;
					q[rear].x = X;
					q[rear++].y = Y - 1;
				}
			}
			if (Y <= N - 1) {
				if (Field[Y + 1][X] <= BabySharcksize && Distance[Y + 1][X] == 0) {
					Distance[Y + 1][X] = distance;
					q[rear].x = X;
					q[rear++].y = Y + 1;
				}
			}
			if (distancecount == front - 1) {
				distance++;
				distancecount = rear - 1;
			}
		}

		//먹을 수 있는 물고기들의 좌표를 Fish배열을 이용하여 좌표를 찾은 후
		//그 좌표가 최적의 거리인지 체크 Distance배열에서 확인 후 Targetfish 초기화 해주기
		int tempx, tempy;
		for (int i = 1; i < BabySharcksize && i < 7; i++) {
			for (int j = 1; j <= Fishnum[i]; j++) {
				if (Fish[i][j].y == -1 && Fish[i][j].x == -1) continue;
				else if (Targetfish.x == 0 && Targetfish.y == 0 && Distance[Fish[i][j].y][Fish[i][j].x] != 0) { //첫번째 타겟 설정 할때 + 먹을 수 있어도 못가는 곳은 빼기
					Targetfish.y = Fish[i][j].y;
					Targetfish.x = Fish[i][j].x;
					tempx = j; tempy = i;
				}
				else if (Distance[Targetfish.y][Targetfish.x] > Distance[Fish[i][j].y][Fish[i][j].x] && Distance[Fish[i][j].y][Fish[i][j].x] != 0) {
					Targetfish.y = Fish[i][j].y;
					Targetfish.x = Fish[i][j].x;
					tempx = j; tempy = i;
				}
				else if (Distance[Targetfish.y][Targetfish.x] == Distance[Fish[i][j].y][Fish[i][j].x] && Targetfish.y >= Fish[i][j].y && Distance[Fish[i][j].y][Fish[i][j].x] != 0) { //가장 위쪽
					if (Targetfish.y == Fish[i][j].y && Targetfish.x >= Fish[i][j].x) {   //y좌표도 똑같을 때 가장 왼쪽 꺼
						Targetfish.y = Fish[i][j].y;
						Targetfish.x = Fish[i][j].x;
						tempx = j; tempy = i;
					}
					else if(Targetfish.y > Fish[i][j].y) {  //y좌표 다를때
						Targetfish.y = Fish[i][j].y;
						Targetfish.x = Fish[i][j].x;
						tempx = j; tempy = i;
					}
				}

			}
		}
		
		//printf("\n");//test
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		printf("%d ", Distance[i][j]);
		//	}
		//	printf("\n");
		//}
	
		//printf("Target X Y : %d %d\n", Targetfish.x, Targetfish.y);  //test




		//먹을 수 있는 것이 있으면! 아기 상어가 이동하면서 먹음
		//상어의 사이즈, 사이즈카운트, 시간 체크
		if (Targetfish.x != 0 && Targetfish.y != 0) {  // 먹기
			if (BabySharcksize - 1 == sizeupcount) {
				BabySharcksize++;
				//printf("size : %d ", BabySharcksize); //test
				sizeupcount = 0;
			}
			else sizeupcount++;
			resulttime = resulttime + Distance[Targetfish.y][Targetfish.x];
			//printf("time : %d\n", resulttime);  //test
		}
		else {
			printf("%d", resulttime);
			return;
		}//못 먹었으면 끝내기

		//아기 상어가 먹은 물고기 없애기+아기 상어 위치 초기화해주기+원래 상어 위치 0 채워넣기
		Field[BabySharck.y][BabySharck.x] = 0;
		BabySharck.x = Targetfish.x; BabySharck.y = Targetfish.y;
		Field[BabySharck.y][BabySharck.x] = 9;
		Fish[tempy][tempx].x = -1;	Fish[tempy][tempx].y = -1;

		//printf("\n");   //test
		//printf("------------------------------------------\n");   //test
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		printf("%d ", Field[i][j]);
		//	}
		//	printf("\n");
		//}

	}
}

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &Field[i][j]);
			if (Field[i][j] == 9) {
				BabySharck.x = j;
				BabySharck.y = i;
			}
			else if (Field[i][j] == 0);
			else {
				Fish[Field[i][j]][++Fishnum[Field[i][j]]].x = j;
				Fish[Field[i][j]][Fishnum[Field[i][j]]].y = i;
			}
		}
	}
	BFS(N);
	return 0;
}