#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 100000

int arr[SIZE+1];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M); getchar();
	
	int f=0, e=0;
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]); getchar();
		e+=arr[i]; f=f>arr[i]?f:arr[i];
	}
	
    int m;
	while(f<=e){
		m=(f+e)/2;
		int c=0, sum=0;
		for(int i=1;i<=N;i++){
			sum+=arr[i];
		
			if(sum>m){
				c++; sum=0; i--;
			}
			else if(i==N){
				c++;
			}
		}
		
		if(c>M)
			f=m+1;
		else
			e=m-1;
	}
	
	printf("%d", m);
		
	return 0;
}