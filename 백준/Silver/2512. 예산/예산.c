#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 10000
#define INF INT_MAX
 
#define min(a,b) (((a) < (b)) ? (a) : (b))

int arr[SIZE+1];
	
int main(void){	
	int N, M;
	scanf("%d", &N); getchar();
	
	for(int i=1;i<=N;i++)
		scanf("%d", &arr[i]); getchar(); 
	
	scanf("%d", &M); getchar();
	int end=M; int front=0;
	
	int res=0;
	while(front <= end){
		int mid=(front+end)/2;
		int sum=0; int max=0;
		for(int i=1;i<=N;i++){
			if(arr[i] <= mid){
				sum += arr[i];
				max = max > arr[i] ? max : arr[i];
			}
			else{
				sum += mid;
				max = max > mid ? max : mid;
			}
		}
		
		if(sum > M)
			end = mid - 1;
		else{
			front = mid + 1;
			res = res > max ? res : max;
		}
	}
	
	printf("%d", res);

	return 0;
}
