#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 1500
#define INF 2100000000


int At[SIZE+1][SIZE+1]; int Bt[SIZE+1][SIZE+1];
int A[SIZE+1][SIZE+1]={0}; int B[SIZE+1][SIZE+1]={0};
int DP[SIZE+1][SIZE+1]={0};

int main(void){
	int Y, X;
	scanf("%d %d", &Y, &X);
	getchar();

	char f; int num;

	for(int i=1;i<=Y;i++){
		for(int j=1;j<=X;j++){
			scanf("%c%d", &f, &num);
			getchar();
			
			if(f=='A') 
				At[i][j]=num;
			else
				Bt[i][j]=num;
		}
	}

//누적합 초기화 
	for(int j=Y-1;j>=1;j--){
		for(int i=1;i<=X;i++){
			A[j][i]=A[j+1][i]+At[j+1][i];
		}
	}
	
	for(int j=2;j<=Y;j++){
		for(int i=2;i<=X;i++){
			B[j][i]=B[j-1][i]+Bt[j-1][i];
		}
	}	

//DP 초기값 
	for(int i=1;i<=Y;i++)
		DP[i][1]=A[i][1];
		
	for(int i=1;i<=X;i++)
		DP[1][i]=DP[1][i-1]+A[1][i];

	for(int i=2;i<=X;i++){
		for(int j=2;j<=Y;j++){
			int dia = DP[j-1][i-1]+A[j][i]+B[j][i];
			int left = DP[j][i-1]+A[j][i]+B[j][i];
			int up = DP[j-1][i]-A[j-1][i]+A[j][i];
			
			int result=(dia>up ? dia : up) > left ? (dia>up ? dia : up) : left;
			
			DP[j][i]=result;
		}
	}

	printf("%d", DP[Y][X]);
	
	return 0;
}