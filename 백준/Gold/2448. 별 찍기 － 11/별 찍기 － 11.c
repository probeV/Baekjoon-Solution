#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 3072

char res[SIZE+1][SIZE*2+1];

void d(int x, int y, int n){
	if(n==3){
		res[y][x]='*';
		res[y+1][x-1]='*'; res[y+1][x+1]='*';
		res[y+2][x-2]='*'; res[y+2][x-1]='*'; res[y+2][x]='*'; res[y+2][x+1]='*'; res[y+2][x+2]='*';
		return;
	}
	
	d(x,y,n/2);
	d(x-n/2,y+n/2,n/2);
	d(x+n/2,y+n/2,n/2);
}

int main(void){
	int N;
	scanf("%d", &N); getchar();
	
	d(N,1,N);
	
	for(int y=1;y<=N;y++){
		for(int x=1;x<=2*N-1;x++){
			if(res[y][x]=='*')
				printf("%c", res[y][x]);
			else
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}