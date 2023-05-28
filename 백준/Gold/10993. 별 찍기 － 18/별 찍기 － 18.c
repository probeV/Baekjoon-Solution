#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 2187

char arr[SIZE+1][SIZE+1];

int hight[11];

void star(int x, int y, int N){
	
	if(N==0) return;
	
	if(N%2==0){
		for(int i=0;i<hight[N];i++){
			arr[y-i][x-i]='*'; arr[y-i][x+i]='*';
		}
		for(int i=0;i<hight[N];i++){
			arr[y-hight[N]+1][x-i]='*'; arr[y-hight[N]+1][x+i]='*';
		}
		
		star(x,y-hight[N]+2,N-1);
	}
	else{
		for(int i=0;i<hight[N];i++){
			arr[y+i][x-i]='*'; arr[y+i][x+i]='*';
		}
		for(int i=0;i<hight[N];i++){
			arr[y+hight[N]-1][x-i]='*'; arr[y+hight[N]-1][x+i]='*';
		}
		
		star(x,y+hight[N]-2,N-1);
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	
	hight[1]=1;
	for(int i=2;i<=N;i++)
		hight[i]=hight[i-1]*2+1;
		
	if (N%2==0)
		star(hight[N],hight[N],N);
	else
		star(hight[N], 1, N);
	if (N%2==0){
		for (int i=1;i<=hight[N];i++){
			for(int j=1;j<=2*hight[N]-i+1;j++){
				if(arr[i][j]=='\0')
					printf(" ");
				else
					printf("%c", arr[i][j]);
			}
			if(i!=hight[N])
				printf("\n");
		}
	}
	else{
		for (int i=1;i<=hight[N];i++){
			for(int j=1;j<=hight[N]+i;j++){
				if(arr[i][j]=='\0')
					printf(" ");
				else
					printf("%c", arr[i][j]);
			}
			if (i!=hight[N])
				printf("\n");
		}
	}

	return 0;
}