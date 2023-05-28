#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1010

typedef struct{
	int x, y;
}Q;

int M, N;

char arr[SIZE][SIZE];
Q queue[SIZE]; int fro, end;
bool visited[SIZE][SIZE];

int Mx[4]={1,-1,0,0}; int My[4]={0,0,1,-1};

void BFS(int x, int y){
	fro=1; end=0;
		
	visited[y][x]=true;
	queue[++end].x=x;
	queue[end].y=y;
	
	while(fro<=end){
		if(queue[fro].y==M){
			printf("YES");
			exit(0);
		}
		
		for(int i=0;i<4;i++){
			int currX=queue[fro].x+Mx[i];
			int currY=queue[fro].y+My[i];
			
			if(currX<=0 || currX>N || currY<=0 || currY>M) continue;
			
			if(arr[currY][currX]=='0' && !visited[currY][currX]){
				visited[currY][currX]=true;
				queue[++end].x=currX;
				queue[end].y=currY;
			}
		}
		fro++;
	}
	
	
}

int main(void){
	scanf("%d %d", &M, &N); getchar();
	
	for(int i=1;i<=M;i++){
		scanf("%s", &arr[i][1]); getchar();
	}
	
	for(int x=1;x<=N;x++){
		if(arr[1][x]=='0' && !visited[1][x])
			BFS(x,1);
	}
	
	printf("NO");
	return 0;
}