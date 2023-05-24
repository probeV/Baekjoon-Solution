#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 2187

char arr[SIZE+1][SIZE+1];

void star(int x, int y, int N){
	if (N==3){
		for(int i=0;i<3;i++){
			arr[y][x-i]='*';
			arr[y+1][x-i]='*';
			arr[y+2][x-i]='*';
		}
		arr[y+1][x-1]='\0';
		return;
	}
	
	star(x,y,N/3); star(x-N/3,y,N/3); star(x-2*N/3,y,N/3);
	star(x-2*N/3,y+N/3,N/3); star(x,y+N/3,N/3);
	star(x,y+2*N/3,N/3); star(x-N/3,y+2*N/3,N/3); star(x-2*N/3,y+2*N/3,N/3);
}


int main(void){
	int N;
	scanf("%d", &N);
	
	star(N,1,N);
	
	for (int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(arr[i][j]=='\0')
				printf(" ");
			else
				printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}