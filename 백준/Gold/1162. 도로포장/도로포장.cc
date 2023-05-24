#include <bits/stdc++.h>

#define N_SIZE 10010
#define M_SIZE 50010
#define K_SIZE 30
#define Q_SIZE 1000000
#define INF LLONG_MAX

using namespace std;

int N, M, K;

typedef struct{
	int node;
	int weight;	
}H;

typedef struct{
	int node;
	int count;
	long long weight;
}Q;

//출잘점, 도착점 
int startNode, endNode;

long long W[N_SIZE][K_SIZE];

vector<vector<pair<int, int> > > arr;

//큐 정의  
priority_queue<pair<long long, pair<int, int> > > pq;

//결과값 저장 배열 next node idx / 포장 도로 개수  
long long res[N_SIZE][K_SIZE];

void init(){
	for(int i=0;i<=N;i++){
		for(int j=0;j<=K;j++){
			res[i][j]=INF;
		}
	}
}

void Dijkstra(){
	init();
	
	pq.push({0, {startNode, 0}});
	res[1][0]=0;
	
	while(!pq.empty()){
		int curr=pq.top().second.first;
		int cnt=pq.top().second.second;
		long long curr_w=-pq.top().first;
		pq.pop();
		
		if(res[curr][cnt] < curr_w) continue;
		
		//힙 탐색  
		for(int i=0;i<arr[curr].size();i++){
			int next = arr[curr][i].first;
			long long w=arr[curr][i].second;
			
			if(res[next][cnt] > res[curr][cnt]+w){
				res[next][cnt]=res[curr][cnt]+w;
				
				pq.push({-res[next][cnt], {next, cnt}});
			}
			
			if(cnt<K && res[next][cnt+1] > res[curr][cnt]){
				res[next][cnt+1]=res[curr][cnt];
					
				pq.push({-res[curr][cnt], {next, cnt+1}});
			}
		}
	}
}

int main(void) {
	//input 
	cin >> N >> M >> K;
	
	arr.resize(N+1);
	
	for(int i=1;i<=M;i++){
		int start, end, weight;
		cin >> start >> end >> weight;
		arr[start].push_back({end, weight});
		arr[end].push_back({start, weight});
	}
	startNode=1; endNode=N;
	
	Dijkstra();

	long long ans=INF;
	for(int i=0;i<=K;i++){
		ans=min(ans, res[endNode][i]);
	}	
	
	printf("%lld", ans);

	return 0;
}