#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 1000000

bool d[SIZE+1];

typedef struct{
	int x;
	int num;
}Arr;

Arr arr[SIZE+1];
int in[101];

void est(){
	for(int i=2;i<=SIZE;i++){
		if(!d[i]){
			for(int j=2;j*i<=SIZE;j++)
				d[i*j]=true;
		}
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	getchar();
	
	for(int i=1;i<=N;i++){
		scanf("%d", &in[i]);
		getchar();
	}
	
	for(int i=1;i<=N;i++){
		int temp=in[i];
		int j=2;
		while(temp!=1){
			int c=0;
			if(!d[j] && temp%j==0){
				temp/=j;
				c++;
			}
			
			if(c==0)
				j++;
			else{
				int k=0;
				while(arr[k].x!=j && arr[k].x!=0)
					k++;
				arr[k].x=j; arr[k].num+=c;
				j=2;
			}
		}
	}
	
	int res_s=1, res_n=0;
	
	int k=0;
	while(arr[k].x!=0){
		if(arr[k].num>=N){
			int p=arr[k].num/N;
			
			res_s*=(int)pow(arr[k].x, p);
			
			for(int i=1;i<=N;i++){
				int temp=in[i];
				int c=0;
				while(temp%arr[k].x==0){
					temp/=arr[k].x;
					c++;
				}
				
				if(c<p)
					res_n+=p-c;
			}
		}
		k++;
	}
	
	printf("%d %d", res_s, res_n);

	return 0;
}