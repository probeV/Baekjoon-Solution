#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE 9
#define INF INT_MAX

int arr[SIZE+1][SIZE+1];

int check(int *list, int x, int y){
	bool v1[SIZE+1]={0}; bool v2[SIZE+1]={0}; bool v3[SIZE+1]={0};
	//possible num search
	//row search
	for(int i=1;i<=SIZE;i++)
		v1[arr[i][x]]=(arr[i][x]!=0);
	//column search
	for(int i=1;i<=SIZE;i++)
		v2[arr[y][i]]=(arr[y][i]!=0);
	//box search
	if(x>=1 && x<4)
		x=1;
	else if(x>=4 && x<7)
		x=4;
	else
		x=7;
		
	if(y>=1 && y<4)
		y=1;
	else if(y>=4 && y<7)
		y=4;
	else
		y=7;
			
	for(int j=0;j<3;j++)
		for(int i=0;i<3;i++)
			v3[arr[j+y][i+x]]=(arr[j+y][i+x]!=0);
			
	//check
	int t=0;
	for(int i=1;i<=SIZE;i++)
		if(!v1[i] && !v2[i] && !v3[i])
			list[++t]=i;
			
	return t;
}

void move(int *x, int *y){
	//output
	if(*x==SIZE && *y==SIZE){
		for(int j=1;j<=SIZE;j++){
			for(int i=1;i<=SIZE;i++){
				printf("%d ", arr[j][i]);
			}
			printf("\n");
		}
		exit(0);
	}
	
	if((*x)<SIZE && (*y)<=SIZE){
		(*x)++;
	}
	else if((*x)==SIZE && (*y)<SIZE){
		(*x)=1; (*y)++;
	}
}

void Backtracking(int x, int y){
	while(arr[y][x]!=0)
		move(&x, &y);
	
	if(arr[y][x]==0){
		int list[SIZE+1]={0};
		int num=check(list, x, y);
		if(num!=0){
			for(int i=1;i<=num;i++){
				arr[y][x]=list[i];
				Backtracking(x,y);
				arr[y][x]=0;
			}
		}        
	}
	return;
}

int main(void) {
	//input 
	for(int y=1;y<=SIZE;y++){
		for(int x=1;x<=SIZE;x++){
			scanf("%d", &arr[y][x]);
			getchar();
		}
	}
	
	Backtracking(1,1);
	
	return 0;
}