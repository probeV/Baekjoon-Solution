#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 

#define SIZE 100

typedef struct{
	int time;
	int score;
}Arr;

Arr arr[SIZE+1]; int dp[10001];

int main(void){
	int N, T;
	scanf("%d %d", &N, &T);

	for(int i=1;i<=N;i++)
		scanf("%d %d", &arr[i].time, &arr[i].score);
	
	int max=0;
	for(int i=1;i<=N;i++){
		for(int t=T;t>=arr[i].time;t--){
			if(dp[t]<dp[t-arr[i].time]+arr[i].score)
				dp[t]=dp[t-arr[i].time]+arr[i].score;
		}
	}
	
	printf("%d", dp[T]);
	return 0;
}