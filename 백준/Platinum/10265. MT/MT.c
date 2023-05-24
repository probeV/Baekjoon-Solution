#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define SIZE 1001
#define INF INT_MAX

#define max(x,y) (((x) > (y)) ? (x) : (y))

int N, K;
int arr[SIZE];

bool visited[SIZE];

// 정방향 그래프, 역방향 그래프  
int graph[SIZE]; bool invertedGraph[SIZE][SIZE];

//SCC 구하기 위한 stack
int stack[SIZE]; int top=-1;

// SCC
int sccSize[SIZE]; int Root[SIZE]; bool Pre[SIZE];

typedef struct{
	int num, code;
}M; 
//가능 인원 체크  
M maxSize[SIZE];

int dp[SIZE];
int res=0;

int compare(const void *x, const void *y){
	if(((M *)x)->code > ((M *)y)->code)
		return 1;
	else if(((M *)x)->code < ((M *)y)->code)
		return -1;
	else
		return 0;
}

void DP(){
	//SCC를 기준으로 정렬  
	qsort((M *)maxSize, N+1, sizeof(M), compare);
	
	dp[0]=-1;
	for(int i=1;i<=N;i++){
		//DP 
		for(int x=K;x>=0;x--){
			if(x-maxSize[i].num<0) continue;
			
			if(dp[x-maxSize[i].num]!=0 && dp[x]==0 && dp[x-maxSize[i].num]!=maxSize[i].code){
				dp[x]=maxSize[i].code;
				res=max(res,x);
			}
		}
	}
}

void DFS(int n) {
    if (visited[n])
        return;

    visited[n] = true;
    DFS(graph[n]);

    stack[++top]=n;
}

int Scc(int n, int root, int count) {
    if (visited[n])
        return count-1;

    visited[n] = true;
    Root[n] = root;
    Pre[root]=true;

    for (int i=1;i<=N;i++) {
    	if(invertedGraph[n][i])
        	count = Scc(i, root, count + 1);
    }

    return count;
}

int check(int n, int size, int root) {
    if (visited[n])
        return size;

    visited[n] = true;
    //현재가 root 일 때 
    if(root == n)
		maxSize[n].num=sccSize[Root[n]];
	//root 아닐 때 
	else
		maxSize[n].num=sccSize[Root[n]]+size;
		
	maxSize[n].code=Root[root];
    size=max(maxSize[n].num, size);
	
    for (int i=1;i<=N;i++) {
    	//같은 SCC는 탐색 x 
    	if(invertedGraph[n][i] && Root[n]!=Root[i]){
    		int temp=check(i, size, root);
			size = max(temp, size);
        }
    }
    return size;
}

int main() {
    scanf("%d %d", &N, &K); getchar();
    for (int i = 1; i <= N; i++) {
    	int temp;
        scanf("%d", &temp); getchar(); 
        graph[i] = temp;
        invertedGraph[temp][i]=true;
    }

    //DFS
    for(int i = 1; i <= N; i++)
        DFS(i);
	
    //SCC
    memset(visited, 0, sizeof(visited));
    while (top!=-1) {
        int t = stack[top--];
        sccSize[t] = Scc(t, t, 1);
    }
	
    memset(visited, 0, sizeof(visited));
    int size;
	
	for(int j=1;j<=N;j++){
		//SCC 아닌거 걸러내기  
		if(!Pre[j] || (sccSize[j]==1 && graph[j]!=j))	continue;

		size=0;
		
    	for (int i = 1; i <= N; i++) {
        	if ((sccSize[i]!=1 || (sccSize[i]==1 && graph[i]==i) && j==Root[i])) {
    	    	//SCC 총 개수 초기화  
        	    size = check(i, size, i);
	        }
    	}
	}
	
	DP();

	printf("%d", res);
	return 0;
}