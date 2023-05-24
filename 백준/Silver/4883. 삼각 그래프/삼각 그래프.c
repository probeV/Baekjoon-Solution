#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 

#define SIZE 100000
#define INF INT_MAX

#define min(a,b) (((a) < (b)) ? (a) : (b))

int arr[SIZE+1][4];
	
int main(void){	
	int case_num=1;
	while(true){
		int dp[SIZE+1][4]={0};
		int N;
		scanf("%d", &N); getchar();
		
		if(N==0)
			break;
		
		for(int i=1;i<=N;i++){
			scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);
			getchar();
		}
		
		for(int i=2;i<=3;i++){
			dp[1][i]=dp[1][i-1]+arr[1][i];
		}
		dp[1][1]=INF;
		
		for(int y=2;y<=N;y++){
			for(int x=1;x<=3;x++){
				if(x==1){
					dp[y][x]=min(dp[y-1][x+1], dp[y-1][x])+arr[y][x];
				}
				else if(x==2){
					int temp1=min(dp[y][x-1], dp[y-1][x-1]);
					int temp2=min(dp[y-1][x], dp[y-1][x+1]);
					dp[y][x]=min(temp1, temp2)+arr[y][x];
				}
				else{
					int temp=min(dp[y][x-1], dp[y-1][x-1]);
					dp[y][x]=min(temp, dp[y-1][x])+arr[y][x];
				}
			}
		}
		printf("%d. %d\n", case_num++, dp[N][2]);
	}
	return 0;
}
