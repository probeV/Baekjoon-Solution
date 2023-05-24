#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 300000
#define INF INT_MAX

typedef struct{
	int h;
	int price;
}Arr;

Arr arr[SIZE+1];
long long dp[SIZE+1];

int compare(const void *x, const void *y){
	if(((Arr *)x)->h > ((Arr *)y)->h)
		return 1;
	else if(((Arr *)x)->h < ((Arr *)y)->h)
		return -1;
	return 0;
}

int main(void){	
	int N, S;
	scanf("%d %d", &N, &S); getchar();
	
	for(int i=1;i<=N;i++){
		scanf("%d %d", &arr[i].h, &arr[i].price); getchar();
	}
	
	qsort((Arr *)arr, N+1, sizeof(Arr), compare);
	
	dp[1]=arr[1].price; int m=0; int max=0;
	for(int i=1;i<=N;i++){
		while(arr[i].h-arr[m].h >= S && m <= i){
			max = max > dp[m] ? max : dp[m];
			m++;
		}
		dp[i]=max+arr[i].price;
	}
	
	max=0;
	for(int i=1;i<=N;i++){
		max = max > dp[i] ? max : dp[i];
	}
	
	printf("%d", max);
	
	return 0;
}
