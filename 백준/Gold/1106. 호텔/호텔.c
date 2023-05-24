#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 20
#define INF 2147483647

int dp[20000]={0};

typedef struct {
	int m;
	int p;
}Arr;

int compare(const void *x,const void *y){
	if (((Arr *)x)->p > ((Arr *)y)->p )
		return 1;
	else if (((Arr *)x)->p < ((Arr *)y)->p )
		return -1;
	return 0;
}

int main(void){
	int C; int N; Arr arr[SIZE+1];
	scanf("%d %d", &C, &N);
	
	for(int i=0;i<N;i++)
		scanf("%d %d", &arr[i].m, &arr[i].p);
	
	qsort((Arr *)arr, N, sizeof(Arr), compare);
	
	int break_point=0;
	
	for(int c=0;c<N;c++){
		int i=0;
		while(true){
			i++;
			if(i-arr[c].p < 0 || (dp[i-arr[c].p]==0 && i-arr[c].p!=0)) continue;
			
			if(dp[i-arr[c].p]+arr[c].m < dp[i] || dp[i]==0)
				dp[i]=dp[i-arr[c].p]+arr[c].m;
				
			if(i>=C && i%arr[c].p==0){
				break_point = break_point > i ? break_point : i;
				break;
			}
		}
	}
	
	int result=INF;
	
	for(int i=C;i<=break_point;i++){
		if(dp[i]!=0)
			result = result < dp[i] ? result : dp[i];
	}
	
	printf("%d", result);
	
	return 0;
}
