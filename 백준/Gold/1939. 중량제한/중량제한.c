#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE 100010
#define INF INT_MAX

#define min(x,y) (((x) > (y)) ? (y) : (x))
#define max(x,y) (((x) < (y)) ? (y) : (x))

int N, M;

typedef struct {
	int node;
	int child;
	int weight;
}Node;

typedef struct{
	int node;
	int weight;	
}H;

int startNode, endNode;

H* Heap[SIZE]; int HeapSize[SIZE];
Node node[SIZE]; int sizeArr[SIZE];

H queue[SIZE]; int fro, end; int res[SIZE];

void Heap_check(int root, int idx){
	while(idx>1){
		//부모가 더 작을 때  
		if(Heap[root][idx/2].weight < Heap[root][idx].weight){
			int tempN=Heap[root][idx/2].node;
			int tempW=Heap[root][idx/2].weight;
			
			Heap[root][idx/2].weight=Heap[root][idx].weight;
			Heap[root][idx/2].node=Heap[root][idx].node;
			
			Heap[root][idx].node=tempN;
			Heap[root][idx].weight=tempW;
			
			idx=idx/2;
		}
		else
			break; 
	}
}

void Heap_make(int root, int child, int weight){
	//Heap에 연결  
	if(Heap[root]==NULL){
		H* heap=(H *)malloc(sizeof(H)*(sizeArr[root]+1));
		Heap[root]=heap;
	}
	
	HeapSize[root]++;
	
	int idx=HeapSize[root];
	Heap[root][idx].node=child;
	Heap[root][idx].weight=weight;
		
	Heap_check(root, idx);
}

void Dijkstra(){
	fro=1; end=1;
	
	res[startNode]=INF;
	
	queue[end].node=startNode;
	queue[end++].weight=INF;
	
	while(fro!=end){
		int curr=queue[fro].node;
		int temp=queue[fro].weight;
		fro++;
		
		if(res[curr] > temp) continue;
		
		for(int i=1;i<=HeapSize[curr];i++){
			int next=Heap[curr][i].node; int w=Heap[curr][i].weight;
			
			int new_w=min(res[curr], w);
			
			if(res[next] < new_w){
				res[next]=new_w;
				queue[end].node=next;
				queue[end++].weight=w;
			}	
		}
	}
}

int main(void) {
	//input 
	scanf("%d %d", &N, &M); getchar();
	int A, B, C;
	for(int i=1;i<=M;i++){
		scanf("%d %d %d", &A, &B, &C); getchar();
		node[i].node=A; node[i].child=B; node[i].weight=C;
		sizeArr[A]++; sizeArr[B]++;
	}
	scanf("%d %d", &startNode, &endNode); getchar();
	
	for(int i=1;i<=M;i++){
		Heap_make(node[i].node, node[i].child, node[i].weight);
		Heap_make(node[i].child, node[i].node, node[i].weight);
	}
	
	Dijkstra();
	
	printf("%d", res[endNode]);
	
	return 0;
}