#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE 51
#define INF INT_MAX

typedef struct{
	int x,y;
}Q;

typedef struct{
	int w, code;
}W;

int arr[SIZE+1][SIZE+1]; W result[SIZE+1][SIZE+1];
bool visited[SIZE+1][SIZE+1];
Q queue[SIZE*SIZE+1]; int front, end;

int count=0; int max=0;

void check(int a, bool *list){
	for(int i=3;i>=0;i--){
		list[i]=a%2;
		a/=2;
	}
}

void BFS(int x, int y, int N, int M){
	
	count++;
	
	queue[++end].x=x;
	queue[end].y=y;
	visited[queue[front].y][queue[front].x]=true;
	
	int temp=0;
	
	while(front <= end){
		bool list[4]={0}; //아래, 오른, 위, 왼 
		check(arr[queue[front].y][queue[front].x], list);
		
	
		temp++;

		//Add Queue 
		//Down 
		if(!list[0] && !visited[queue[front].y+1][queue[front].x]){
			visited[queue[front].y+1][queue[front].x]=true;
			queue[++end].x=queue[front].x;
			queue[end].y=queue[front].y+1;
		}
		//Right
		if(!list[1] && !visited[queue[front].y][queue[front].x+1]){
			visited[queue[front].y][queue[front].x+1]=true;
			queue[++end].x=queue[front].x+1;
			queue[end].y=queue[front].y;
		}
		//Up
		if(!list[2] && !visited[queue[front].y-1][queue[front].x]){
			visited[queue[front].y-1][queue[front].x]=true;
			queue[++end].x=queue[front].x;
			queue[end].y=queue[front].y-1;
		}
		//Left
		if(!list[3] && !visited[queue[front].y][queue[front].x-1]){
			visited[queue[front].y][queue[front].x-1]=true;
			queue[++end].x=queue[front].x-1;
			queue[end].y=queue[front].y;
		}
		front++;
	}
	
	max = temp > max ? temp : max;
	
	for(int y=1;y<=M;y++)
		for(int x=1;x<=N;x++)
			if(visited[y][x] && result[y][x].w==0){
				result[y][x].w=temp;
				result[y][x].code=count;
			}
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M); getchar();
	
	for(int j=1;j<=M;j++){
		for(int i=1;i<=N;i++){
			scanf("%d", &arr[j][i]);
			getchar();
		}
	}
	
	for(int y=1;y<=M;y++){
		for(int x=1;x<=N;x++){
			if(!visited[y][x]){
				front=1; end=0;
				BFS(x,y, N, M);
			}
		}
	}
	
//	for(int y=1;y<=M;y++){
//		for(int x=1;x<=N;x++){
//			printf("%d.%d ", result[y][x].w, result[y][x].code);
//		}
//		printf("\n");
//	}
	
	int r=max;
	for(int y=1;y<=M;y++){
		for(int x=1;x<=N;x++){
			bool list[4]={0};
			check(arr[y][x], list);
			
			//Down
			if(list[0] && y<M && result[y][x].code != result[y+1][x].code) 
				r = r > result[y][x].w+result[y+1][x].w ? r : result[y][x].w+result[y+1][x].w;	
			//Right
			if(list[1] && x<N && result[y][x].code != result[y][x+1].code)
				r = r > result[y][x].w+result[y][x+1].w ? r : result[y][x].w+result[y][x+1].w;
		}
	}
	
	printf("%d\n%d\n%d", count, max, r);
	return 0;	
}