#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 300
#define INF INT_MAX

int arr[SIZE+1]; int dp[2][SIZE+1];

int main(void){	
	int N;
	scanf("%d", &N); getchar();
	
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]); getchar();
	}
	
	dp[0][1]=arr[1]; dp[0][2]=arr[2];
	for(int x=1;x<=N-1;x++){
		for(int y=0;y<=1;y++){
			if(dp[y][x]!=0){
				if(y==0){
					if(dp[0][x+2] < dp[y][x]+arr[x+2])
						dp[0][x+2]=dp[y][x]+arr[x+2];
					if(dp[y+1][x+1] < dp[y][x]+arr[x+1])
						dp[y+1][x+1]=dp[y][x]+arr[x+1];
				}
				else{
					if(dp[0][x+2] < dp[y][x]+arr[x+2])
						dp[0][x+2]=dp[y][x]+arr[x+2];
				}
			}
		}
	}
//	for(int x=1;x<=N;x++)
//		printf("%d %d\n", dp[0][x], dp[1][x]);
	printf("%d", dp[0][N] > dp[1][N] ? dp[0][N] : dp[1][N]);
	
	return 0;
}