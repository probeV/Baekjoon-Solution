#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0

typedef struct Linkedlist {
	int data;
	struct Linkedlist* link;
}Linkedlist;

int front = 1, rear=1;
int visited[1001] = { false, };
Linkedlist* bfs_list[1001] = { NULL, };

int empty() {
	return front == rear;
}

void insert(int vertex1, int vertex2) {
	Linkedlist* node1 = (Linkedlist*)malloc(sizeof(Linkedlist));
	Linkedlist* temp;
	temp = bfs_list[vertex1];
	bfs_list[vertex1] = node1;
	node1->data = vertex2;
	node1->link = temp;
	Linkedlist* node = (Linkedlist*)malloc(sizeof(Linkedlist));
	temp = bfs_list[vertex2];
	bfs_list[vertex2] = node;
	node->data = vertex1;
	node->link = temp;
}

int main(void) {
	int vertexnum, edgenum, vertex1, vertex2, result = 0, Queue[1001];
	scanf("%d %d", &vertexnum, &edgenum);
	for (int i = 0; i < edgenum; i++) {
		scanf("%d %d", &vertex1, &vertex2);
		insert(vertex1, vertex2);
	}
	for (int j = 1, i; j <= vertexnum; j++) {
		if (!visited[j]) {
			Queue[rear++]=j;
			result++;
		}
		while (!empty()) {
			i = Queue[front++];
			for (Linkedlist* w = bfs_list[i]; w; w = w->link) {
				if (!visited[w->data]) {
					visited[w->data] = true;
					Queue[rear++] = w->data;
				}
			}
		}
	}
	printf("%d", result);
	return 0;
}