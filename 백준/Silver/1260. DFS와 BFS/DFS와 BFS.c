#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0

int DFS_BFS_LIST[1001][1001] = { false, };

int visited[1001] = { false, };   //visited 배열

int front = 1, rear = 1;   //BFS
int  Queue[1001];

void init() {
	for (int i = 0; i < 1001; i++) {
		visited[i] = false;
	}
}

int empty() {
	return front == rear;
}

void insert(int vertex1, int vertex2) {
	DFS_BFS_LIST[vertex1][vertex2] = true;
	DFS_BFS_LIST[vertex2][vertex1] = true;
}

void DFS(int v, int vertexnum) {
	int w;
	visited[v] = true; // 정점 v의 방문 표시
	printf("%d ", v); // 방문한 정점 출력
	for (w = 1; w <= vertexnum; w++) // 인접 정점 탐색
		if (DFS_BFS_LIST[v][w] && !visited[w])
			DFS(w, vertexnum);
}

void BFS(int v, int vertexnum) {
	Queue[rear++] = v;
	visited[v] = true;
	printf("%d ", v);
	while (!empty()) {
		v = Queue[front++];
		for (int w = 1; w <= vertexnum; w++) {
			if (DFS_BFS_LIST[v][w] && !visited[w]) {
				visited[w] = true;
				printf("%d ", w);
				Queue[rear++] = w;
			}
		}
	}
}

int main(void) {
	int vertexnum, edgenum, vertex1, vertex2, startvertex;
	scanf("%d %d %d", &vertexnum, &edgenum, &startvertex);
	for (int i = 0; i < edgenum; i++) {
		scanf("%d %d", &vertex1, &vertex2);
		insert(vertex1, vertex2);
	}
	DFS(startvertex, vertexnum);
	printf("\n");
	init();
	BFS(startvertex, vertexnum);
	return 0;
}