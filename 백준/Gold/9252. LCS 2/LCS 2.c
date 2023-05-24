#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 

#define SIZE 1000

char arr1[SIZE+2]; char arr2[SIZE+2];
int dp[SIZE+1][SIZE+1];
char result[SIZE+1];

int main(void){
	arr1[0]=' '; arr2[0]=' ';
	scanf("%s", &arr1[1]);
	getchar();
	scanf("%s", &arr2[1]);
	
	int l1=strlen(arr1)-1; int l2=strlen(arr2)-1;
	
	for(int i=1;i<=l2;i++){
		for(int j=1;j<=l1;j++){
			if(arr1[j]==arr2[i])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
		}
	}
	
	printf("%d\n", dp[l2][l1]);
	
	int i=l2; int j=l1; int c=dp[l2][l1]; result[c]='\0';
	while(dp[i][j]!=0){
		if(dp[i-1][j]==dp[i][j]-1 && dp[i][j-1]==dp[i][j]-1){
			result[--c]=arr1[j];
			i--; j--;
		}
		else if(dp[i][j-1]==dp[i][j])
			j--;
		else
			i--;
	} 
	
	printf("%s", result);
	
	return 0;
}