#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 64

char arr[SIZE+2][SIZE+2];

bool c(int x, int y, int n){
	for(int i=x;i<x+n;i++){
		for(int j=y;j<y+n;j++){
			if(arr[y][x]!=arr[j][i])
				return false;
		}
	}
	return true;
}

void d(int x, int y, int n){
	if(n==1){
		printf("%d", arr[y][x]-48);
		return;
	}

	if(c(x,y,n))
		printf("%d", arr[y][x]-48);
	else{
		printf("(");
		d(x,y,n/2);
		d(x+n/2,y,n/2);
		d(x,y+n/2,n/2);
		d(x+n/2,y+n/2,n/2);
		printf(")");
	}

}

int main(void){
	int N;
	scanf("%d", &N); getchar();
	
	for(int i=1;i<=N;i++){
		scanf("%s", &arr[i][1]); getchar();
	}
	

	d(1,1,N);

		
	return 0;
}