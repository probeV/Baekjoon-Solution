#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 200000
#define INF INT_MAX

int arr[SIZE+1];

int compare(const void *x, const void *y){
	if(*(int *)x > *(int *)y)
		return 1;
	else if(*(int *)x < *(int *)y)
		return -1;
	return 0;
}

int main(void){	
	int N, C;
	scanf("%d %d", &N, &C); getchar();
	
	int front=0, end=0;
	for(int i=1;i<=N;i++){
		scanf("%d", &arr[i]); getchar();
		end = end > arr[i] ? end : arr[i];
	}	
	
	qsort(arr, N+1, sizeof(int), compare);

	int res=0;
	while(front <= end){
		int mid=(front + end)/2;
		
		int y=1; int count=1;
		for(int x=1;x<=N;x++){
			if(arr[x]-arr[y]>=mid){
				count++;
				y=x;
			}
		}
		
		if(count >= C){
			res = res > mid ? res : mid;
			front = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	
	printf("%d", res);
	
	return 0;
}