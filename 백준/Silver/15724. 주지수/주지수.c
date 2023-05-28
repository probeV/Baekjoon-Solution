#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 1024
#define INF INT_MAX

int arr[SIZE+1][SIZE+1]; int dp[SIZE+1][SIZE+1];

int main(void){	
	int N,M;
	scanf("%d %d", &N, &M); getchar();
	
	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			scanf("%d", &arr[x][y]); getchar();
		}
	}
	
	for(int y=1;y<=M;y++){
		for(int x=1;x<=N;x++){
			dp[x][y]=dp[x-1][y]+arr[x][y];
		}
	}
	
	int K;
	scanf("%d", &K); getchar();
	
	for(int t=1;t<=K;t++){
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); getchar();
		
		int res=0;
		for(int i=y1;i<=y2;i++){
			res+=dp[x2][i];
			res-=dp[x1-1][i];
		}
		
		printf("%d\n", res);
	}
	
	return 0;
}