#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 50

int dp[SIZE+1][SIZE+1][SIZE+1][SIZE+1];
int game[SIZE+1][SIZE+1];

int main(void){
	int N,M,C;
	scanf("%d %d %d", &N, &M, &C);
	getchar();
	
	for(int i=1;i<=C;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		getchar();
		game[y][x]=i;
	}
	
	if(game[1][1]==0)
		dp[1][1][0][0]=1;
	else
		dp[1][1][1][game[1][1]]=1;
	
	for(int j=1;j<=M;j++){
		for(int i=1;i<=N;i++){
			if(game[j][i]==0){
				for(int l=0;l<=C;l++){
					for(int c=0;c<=l;c++){
						dp[j][i][c][l]=(dp[j][i][c][l]+dp[j-1][i][c][l]+dp[j][i-1][c][l])%1000007;
					}
				}
			}
			else{
				for(int l=0;l<game[j][i];l++){
					for(int c=0;c<=l;c++){
						dp[j][i][c+1][game[j][i]]=(dp[j][i][c+1][game[j][i]]+dp[j-1][i][c][l]+dp[j][i-1][c][l])%1000007;
					}
				}
			}
		}
	}
	
	for(int i=0;i<=C;i++){
		int sum=0;
		for(int j=0;j<=C;j++)
			sum+=dp[M][N][i][j];
		printf("%d ", sum%1000007);
	}
	
	return 0;
}