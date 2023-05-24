#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
#define INF 1000

void init(int** visited, int width, int hight) {
	for (int i = 0; i < hight; i++) {
		for (int j = 0; j < width; j++) {
			visited[i][j] = false;
		}
	}
}

void DFS(int** visited, int width, int hight, int X, int Y) {
	visited[Y][X]=INF;
	if (X != width - 1) {
		if (visited[Y][X + 1] == true) {
			DFS(visited, width, hight, X + 1, Y);
		}
	}
	if (X != 0) {
		if (visited[Y][X - 1] == true) {
			DFS(visited, width, hight, X - 1, Y);
		}
	}
	if (Y != hight - 1) {
		if (visited[Y + 1][X] == true) {
			DFS(visited, width, hight, X, Y + 1);
		}
	}
	if (Y != 0) {
		if (visited[Y - 1][X] == true) {
			DFS(visited, width, hight, X, Y - 1);
		}
	}
}

int main(void) {
	int testnum, width, hight, num, X, Y;
	scanf("%d", &testnum);
	for (int i = 0; i < testnum; i++) {
		int result = 0;
		scanf("%d %d %d", &width, &hight, &num);

		int** visited = (int**)malloc(sizeof(int*) * hight);
		for (int j = 0; j < hight; j++) {
			visited[j] = (int*)malloc(sizeof(int) * width);
		}

		init(visited, width, hight);	//visited 배열 정리
		for (int j = 0; j < num; j++) {
			scanf("%d %d", &X, &Y);
			visited[Y][X] = true;
		}

		int X = 0, Y = 0;

		while (X != width - 1 || Y != hight - 1) {
			while (visited[Y][X] != true && (X != width - 1 || Y != hight - 1)) {
				if (X == width - 1 && Y < hight) {
					Y++;
					X = 0;
				}
				else if (X < width) {
					X++;
				}
			}
			if (visited[Y][X] == true) {
				DFS(visited, width, hight, X, Y);
				result++;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}