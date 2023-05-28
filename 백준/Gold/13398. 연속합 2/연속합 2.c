#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 100000

int arr[SIZE+1];
int dp[SIZE+1][2];

int main(void){
	int N;
	scanf("%d", &N); getchar();
	
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]); getchar();
	}
	
	dp[1][0]=arr[1];
	dp[1][1]=arr[1];
	int max=arr[1];
	for(int i=2;i<=N;i++){
		dp[i][0]=arr[i] > dp[i-1][0]+arr[i] ? arr[i] : dp[i-1][0]+arr[i];
		dp[i][1]=dp[i-1][0] > dp[i-1][1]+arr[i] ? dp[i-1][0] : dp[i-1][1]+arr[i];
		max = max > (dp[i][1] > dp[i][0] ? dp[i][1] : dp[i][0] )? max : (dp[i][1] > dp[i][0] ? dp[i][1] : dp[i][0] );
	}

	printf("%d", max);

	return 0;
}