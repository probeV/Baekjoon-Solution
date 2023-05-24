#include <bits/stdc++.h>

#define INF INT_MAX
#define SIZE 110

using namespace std;

vector<pair<int, int> > route[SIZE];
vector<int> reverse_route[SIZE];

priority_queue<pair<int, int> > pq;

int n, m, startNode, endNode;

int res[SIZE]; int parent[SIZE]; bool visited[SIZE]; 

void bellman(){
	for(int i=1;i<=n;i++){
		res[i]=-INF;
		parent[i]=i;
	}

	res[startNode]=0;
	pq.push({0, startNode});
	
	int count=0; 
	
	while(!pq.empty()){
		count=count+1;
		
		int curr_node=pq.top().second;
		int curr_weight=pq.top().first;
		pq.pop();
		
		if(res[curr_node] > curr_weight) continue;
		
		for(int i=0;i<route[curr_node].size();i++){
			int next_node=route[curr_node][i].first;
			int next_weight=route[curr_node][i].second;
			
			if(res[next_node] < res[curr_node]+next_weight){
				if(count > m){
					//사이클 있고 경로에 포함 됨  
					if(visited[next_node]){
						cout << -1;
						exit(0);
					}
					return; 
				}
				
				res[next_node]=res[curr_node]+next_weight;
				pq.push({res[next_node], next_node});
				parent[next_node]=curr_node;
			}
		}
	}
}

int main(void) {
	
	cin >> n >> m;
	startNode = 1; endNode = n;
	
	for(int i=1;i<=m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		route[u].push_back({v,w});
		reverse_route[v].push_back(u);
	}
	
	queue<int> q;
	q.push(n);
	visited[n]=true;
	while(!q.empty()){
		int curr=q.front();
		q.pop();
		
		
		for(int i=0;i<reverse_route[curr].size();i++){
			int next=reverse_route[curr][i];
			if(!visited[next]){
				visited[next]=true;
				q.push(next);			
			}
		}
	}
		
	bellman();
	
	int i=endNode; vector<int> temp;
	int count=0;
	while(i!=startNode){
		temp.push_back(i);
		i=parent[i];
	}
	
	if(count > m)
		cout << -1;
	else{
		cout << startNode << " ";
		for(int i=temp.size()-1;i>=0;i--){
			cout << temp[i] << " ";
		}
	}
	
	return 0;
}

