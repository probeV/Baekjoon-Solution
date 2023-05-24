#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 300

int arr[SIZE+1];
int b[SIZE+1];

int main(void){
	int N,M;
	scanf("%d %d", &N, &M);
	getchar();
	
	int f=0, e=0;
	
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]); getchar();
		e+=arr[i];
		f=f>arr[i]?f:arr[i];
	}
	
	int res=INT_MAX; int m=0, C=0;
	
	while(f<=e){
		int t=(f+e)/2;
		
		int sum=0, bc=0, te=0, idx=0, c=0;
		int tb[SIZE+1];
		for(int i=1;i<=N;i++){
			sum+=arr[i];
			bc++;
			
			if(sum>t){
				tb[++c]=bc-1; 
				if(te <= sum-arr[i]){
					te=sum-arr[i];
					if(tb[idx] > tb[c])
						idx=c;
				}
				i--;
				sum=0; bc=0;
			}
			else if(i==N){
				tb[++c]=bc; 
				if(te <= sum){
					te=sum;
					if(tb[idx] > tb[c])
						idx=c;
				}
			}
		}
		
		if(c<=M && res > te){
			m=idx; C=c; res=te;
			for(int i=1;i<=M;i++)
				b[i]=tb[i];
		}
		
		if(c>M)
			f=t+1;
		else
			e=t-1;
	}
	
	printf("%d\n", res);
	
	int i=C;
	for(int k=1;k<=C;k++){
		while(M-i!=0 && b[k]!=1 && k!=m){
			printf("1 ");
			b[k]--; i++;
		}
		printf("%d ", b[k]);
	}
	
	return 0;
}