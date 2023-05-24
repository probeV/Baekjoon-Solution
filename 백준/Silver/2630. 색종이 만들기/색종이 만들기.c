#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 128
#define INF INT_MAX

int arr[SIZE+1][SIZE+1]; int res[2];

bool check(int x, int y, int n){
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
		res[arr[y][x]]++;
		return;
	}
	
	if(check(x,y,n)){
		res[arr[y][x]]++;
	}
	else{
		d(x,y,n/2);
		d(x+n/2,y,n/2);
		d(x,y+n/2,n/2);
		d(x+n/2,y+n/2,n/2);
	}
}

int main(void){	
	int N;
	scanf("%d", &N); getchar();
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d", &arr[i][j]); getchar();
		}
	}
	
	d(1,1,N);
	
	printf("%d\n%d", res[0], res[1]);
	
	return 0;
}