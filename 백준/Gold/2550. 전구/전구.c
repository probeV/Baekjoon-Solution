#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
 
#define SIZE 10000
#define INF INT_MAX

int s[SIZE+1]; int l[SIZE+1];
int arr[SIZE+1];
int LIS[SIZE+1]; int pos[SIZE+1];
int res[SIZE+1];

int b(int target, int end){
	int front=0;
	int mid;
	while(front < end){
		mid = (front + end)/2;
		
		if(LIS[mid]>target)
			end=mid;
		else
			front = mid+1;
	}
	return end;
}

int compare(const void *x, const void *y){
	if(*(int *)x > *(int *)y)
		return 1;
	else if(*(int *)x < *(int *)y)
		return -1;
	return 0;
}

int main(void){	
	int N;
	scanf("%d", &N); getchar();
	
	for(int i=1;i<=N;i++){
		int id;
		scanf("%d", &id); getchar();
		s[id]=i;
	}
	for(int i=1;i<=N;i++){
		int id;
		scanf("%d", &id); getchar();
		l[i]=id;
		arr[i]=s[id];
	}
	
	LIS[0]=-1;
	for(int i=1;i<=SIZE;i++)
		LIS[i]=INF;
		
	int max=0;
	for(int i=1;i<=N;i++){
		int j=b(arr[i], N);
		pos[i]=j;
		LIS[j]=arr[i];
		max = max > j ? max : j;
	}
	
	int count=0;
	for(int i=N;i>=1;i--){
		if(max == pos[i]){
			res[++count]=l[i];
			max--;
		}
	}
	
	qsort(res, count+1, sizeof(int), compare);
	
	printf("%d\n", count);
	for(int i=1;i<=count;i++){
		printf("%d ", res[i]);
	}
	
	return 0;
}