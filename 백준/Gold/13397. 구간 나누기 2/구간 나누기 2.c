#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 

#define SIZE 5000

int arr[SIZE+1];

main(void){	
	int N,M;
	scanf("%d %d", &N, &M); getchar();
	
	int front=0, end=0;
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]); getchar();
		if(end < arr[i])
			end = arr[i];
	}
	
	int mid, res=INT_MAX;
	while(front <= end){
		mid=(front + end)/2;
		
		int count=0, sub=0;
		int max=0, min=INT_MAX;
		for(int i=1;i<=N;i++){
			max = max > arr[i] ? max : arr[i];
			min = min < arr[i] ? min : arr[i];
			
			sub=max-min;
			
			if(sub>mid){
				count++;
				i--;
				sub=0; max=0; min=INT_MAX;
			}
			else if(i==N){
				count++;
			}
		}
		
		if(count <= M){
			res = res < mid ? res : mid;
			end = mid-1;
		}
		else
			front = mid+1;
	}
	
	printf("%d", res);
	
	return 0;
}
