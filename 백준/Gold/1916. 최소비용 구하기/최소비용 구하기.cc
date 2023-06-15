#include <bits/stdc++.h>

using namespace std;

#define SIZE 100010

int N, M, startNode, endNode;

int dist[1010];

vector<pair<int, int> > route[SIZE];

void Dijk(){
	priority_queue<pair<int, int> > pq;
	
	pq.push({0, startNode});
	dist[startNode]=0;
	
	while(!pq.empty()){
		int curr_node=pq.top().second;
		int curr_cost=pq.top().first;
		pq.pop();
		
		if(dist[curr_node] < curr_cost) continue;
		
		for(int i=0;i<route[curr_node].size();i++){
			int next_node=route[curr_node][i].second;
			int next_cost=route[curr_node][i].first;
			
			if(dist[next_node]>next_cost+curr_cost){
				dist[next_node]=next_cost+curr_cost;
				pq.push({dist[next_node], next_node});
			}
		}
		
	}
}

void init(){
	for(int i=0;i<=N;i++){
		dist[i]=INT_MAX;
	}
}

int main(void) {
	//input
	cin >> N;
	cin >> M;
	for(int i=1;i<=M;i++){
		int u, v, w;
		cin >> u >> v >> w;
		route[u].push_back({w,v});
	}
	cin >> startNode;
	cin >> endNode;
	
	init();
	Dijk();
	
	cout << dist[endNode];
	return 0;
}