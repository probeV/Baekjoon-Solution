#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct Linkedlist {
	int data;
	struct Linkedlist* link;
}Linkedlist;

int visited[101] = { false, };
Linkedlist* adj_list[101] = { NULL, };

void insert(int comp1, int comp2) {
	Linkedlist* l1 = (Linkedlist*)malloc(sizeof(Linkedlist));
	l1->link = adj_list[comp1];
	l1->data = comp2;
	adj_list[comp1] = l1;
	Linkedlist* l2 = (Linkedlist*)malloc(sizeof(Linkedlist));
	l2->link = adj_list[comp2];
	l2->data = comp1;
	adj_list[comp2] = l2;
}

void DFS(Linkedlist *w) {
	for (; w != NULL ; w = w->link) {
		if (visited[w->data] == false) {
			visited[w->data] = true;
			DFS(adj_list[w->data]);
		}
	}
}

int main(void) {
	int computernum, pairnum, num1, num2, result = 0;
	scanf("%d", &computernum);
	scanf("%d", &pairnum);
	for (int i = 0; i < pairnum; i++) {
		scanf("%d %d", &num1, &num2);
		insert(num1, num2);
	}
	visited[1] = true;
	DFS(adj_list[1]);
	for (int i = 1; i <= computernum; i++) {
		if (visited[i] == true) result++;
	}
	printf("%d", result-1);
	return 0;
}