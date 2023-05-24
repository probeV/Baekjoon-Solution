#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 

#define SIZE 2500

char arr[SIZE+2]; bool p[SIZE+1][SIZE+1];
int dp[SIZE+1];


int main(void){	
	arr[0]=' ';
	scanf("%s", &arr[1]); getchar();
	
	int l=strlen(arr)-1;
	
	for(int d=0;d<l;d++){
		for(int x=1;x+d<=l;x++){
			if(arr[x]==arr[x+d] && (d<=1 || p[x+1][x+d-1]))
				p[x][x+d]=true;
		}
	}
	
	for(int i=1;i<=l;i++){
		dp[i]=INT_MAX;
		for(int j=1;j<=i;j++){
			if(p[j][i])
				dp[i]=dp[i]>dp[j-1]+1 ? dp[j-1]+1 : dp[i];
		}
	}
	
	printf("%d", dp[l]);
	
	return 0;
}