#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 50

typedef struct{
	int p;
	int num;
}Arr;

Arr arr[SIZE+1];
long long dp[500001]; bool d[500001];

void est(){
	d[1]=true;
	for(int i=2;i<500000;i++){
		if(!d[i]){
			for(int j=2;i*j<500000;j++)
				d[i*j]=true;
		}
	}
}

int main(void){
	int N;
	scanf("%d", &N); getchar();
	
	int total=0, z=0;
	for(int i=1;i<=N;i++){
		int temp;
		scanf("%d", &temp); getchar();
		total+=temp;
		
		if(temp==0){
			z++;
			continue;
		}
		
		int k=0;
		while(arr[k].p!=temp && arr[k].p!=0)
			k++;
		arr[k].p=temp; arr[k].num++;
	}

	est();
	
	dp[0]=1;
	int k=0;
	while(arr[k].p!=0){ 
		for(int i=total;i>=0;i--){
			for(int j=1;j<=arr[k].num;j++){
				if(i-arr[k].p*j<0) break;
				dp[i]=dp[i]+dp[i-arr[k].p*j];
			}
		}
		k++;
	}
	
	long long res=0;
	for(int i=1;i<=total;i++){
		if(!d[i])
			res+=dp[i];
	}
	
	if(z!=0)
		printf("%lld", res*(z+1));
	else
		printf("%lld", res);

	return 0;
}