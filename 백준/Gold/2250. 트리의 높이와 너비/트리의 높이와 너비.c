#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 
#include <math.h>

#define SIZE 10000

typedef struct{
	int l,r;
}Arr;

Arr arr[SIZE]; bool visited[SIZE+1];
int w=1; int x[SIZE+1]; int res_h=1; int res_w=0;

void sol(int h){
	if(x[h]==0)
		x[h]=w++;
	else{
		if(res_w < w-x[h]){
			res_w = w-x[h]; res_h=h;
		}
		else if(res_w == w-x[h])
			res_h=res_h < h ? res_h : h;
		w++;
	}
}

void dfs(int p, int h){
	if(arr[p].l==-1 && arr[p].r==-1){
		sol(h);
		return;
	}
	
	if(arr[p].l!=-1)
		dfs(arr[p].l, h+1);
		
	sol(h);
		
	if(arr[p].r!=-1)
		dfs(arr[p].r, h+1);
	
}

int main(void){
	int N;
	scanf("%d", &N);
	getchar();
	
	for(int i=1;i<=N;i++){
		int p, l, r;
		scanf("%d %d %d", &p, &l, &r);
		arr[p].l=l; arr[p].r=r;
		if(l!=-1)
			visited[l]=true;
		if(r!=-1)
			visited[r]=true;
	}
	
	int root;
	for(int i=1;i<=N;i++)
		if(!visited[i])
			root=i;
	
	dfs(root, 1);
	
	printf("%d %d", res_h, res_w+1);

	return 0;
}