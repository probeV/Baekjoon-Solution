#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE 1010
#define INF INT_MAX

typedef struct{
	int x,y;
}Q;

char arr[SIZE+1][SIZE+1]; int temp[SIZE+1][SIZE+1]; int res[SIZE+1][SIZE+1];
Q queue[SIZE*SIZE+1]; int fro, end; int count=0;
int W[SIZE*SIZE+1];
bool visited[SIZE+1][SIZE+1];

int Mx[4]={1,-1,0,0}; int My[4]={0,0,1,-1};

void BFS(int x, int y, int N, int M){
	int w=0; count++;
	
	fro=1; end=0;
	
	queue[++end].x=x; queue[end].y=y;
	visited[y][x]=true;
	temp[y][x]=count;
	
	while(fro<=end){
		w++;
		
		for(int i=0;i<4;i++){
			int Px=queue[fro].x+Mx[i];
			int Py=queue[fro].y+My[i];
			
			if(Px<=0 || Px>M || Py<=0 || Py>N)	continue;
			
			if(!visited[Py][Px] && arr[Py][Px]=='0'){
				visited[Py][Px]=true;
				temp[Py][Px]=count;
				queue[++end].x=Px;
				queue[end].y=Py;
			}
		}
		
		fro++;
	}
	W[count]=w;
}

bool find(int check[], int i, int target){
	for(int j=0;j<=i;j++){
		if(check[j]==target)	return false;
	}
	return true;
}

int main(void) {
	//input 
	int N, M;
	scanf("%d %d", &N, &M); getchar();
	for(int y=1;y<=N;y++){
		scanf("%s", &arr[y][1]); getchar();
	}
	
	//BFS 
	for(int y=1;y<=N;y++){
		for(int x=1;x<=M;x++){
			if(arr[y][x]=='0' && !visited[y][x]){
				BFS(x,y, N, M);
			}	
		}
	}
			
	for(int y=1;y<=N;y++){
		for(int x=1;x<=M;x++){
			if(arr[y][x]=='1'){
				res[y][x]=1;
				
				int check[4]={0};
				
				for(int i=0;i<4;i++){
					int Px=x+Mx[i];
					int Py=y+My[i];
			
					if(Px<=0 || Px>M || Py<=0 || Py>N)	continue;
					
					if(find(check, i, temp[Py][Px]) && arr[Py][Px]=='0'){
						check[i]=temp[Py][Px];
						res[y][x]=(res[y][x]+W[temp[Py][Px]])%10;
					}
				}
			}
		}
	}

	//output
	for(int y=1;y<=N;y++){
		for(int x=1;x<=M;x++){
			printf("%d", res[y][x]);
		}
		printf("\n");
	}
	
	return 0;
}