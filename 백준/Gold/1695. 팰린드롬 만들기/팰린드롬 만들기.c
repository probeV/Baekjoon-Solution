#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 5000
#define min(a,b) (((a) < (b)) ? (a) : (b) )

int dp[SIZE+1][SIZE+1];
int arr[SIZE+1];

int main(void){	
	int N;
	scanf("%d", &N); getchar();
	
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]); getchar();
	}
	
	for(int x=1;x<=N-1;x++){
		if(arr[x]!=arr[x+1]){
				dp[x][x+1]=1;
		}	
	}
	
	for(int dia=2;dia<=N-1;dia++){
		for(int x=1;x+dia<=N;x++){
			if(arr[x]!=arr[x+dia]){
				dp[x][x+dia]=min(dp[x][x+dia-1], dp[x+1][x+dia])+1;
				dp[x][x+dia]=min(dp[x+1][x+dia-1]+2, dp[x][x+dia]);
			}
			else
				dp[x][x+dia]=dp[x+1][x+dia-1];	
		}
	}
	
	printf("%d", dp[1][N]);
	return 0;
}