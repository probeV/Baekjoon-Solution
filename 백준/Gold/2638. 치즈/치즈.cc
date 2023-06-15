#include <bits/stdc++.h>

using namespace std;

#define SIZE 110

int N, M, result=0;

int Arr[SIZE][SIZE];

bool visited[SIZE][SIZE];

pair<int, int> Mv[4]={{1,0}, {-1,0}, {0,1}, {0,-1}};

vector<pair<int, int> > Cheese;

void BFS(int x, int y){
	queue<pair<int, int> > q;
	
	q.push({x,y});
	visited[y][x]=true;
	
	while(!q.empty()){
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int next_x=curr_x+Mv[i].first;
			int next_y=curr_y+Mv[i].second;
			
			if(next_x<=0 || next_x > M || next_y<=0 || next_y > N) continue;
			
			if(visited[next_y][next_x] || Arr[next_y][next_x]==1) continue;
			
			q.push({next_x, next_y});
			visited[next_y][next_x]=true;
		}
	}
}

bool CheeseCheck(int x, int y){

	visited[y][x]=true;
	
	int count=0;
	for(int i=0;i<4;i++){
		int next_x=x+Mv[i].first;
		int next_y=y+Mv[i].second;
			
		if(next_x<=0 || next_x > M || next_y<=0 || next_y > N) continue;
			
		if(Arr[next_y][next_x]==1) continue;
			
		if(Arr[next_y][next_x]==0 && visited[next_y][next_x])
			count++;
	}
	
	if(count >= 2)
		return true;
	return false;
}

//바깥 공기 체크 
void CheckOut(){
	for(int y=1;y<=N;y++){
		if(y==1 || y==N){
			for(int x=1;x<=M;x++)
				if(Arr[y][x]==0 && !visited[y][x])
					BFS(x,y);
		}
		else{
			if(Arr[y][1]==0  && !visited[y][1])
				BFS(1,y);
			if(Arr[y][M]==0 && !visited[y][M])
				BFS(M,y);
		}
	}
}

void Solution(){
	while(true){
		result++;
		
		memset(visited, false, sizeof(visited));
		//바깥 공기 체크  
		CheckOut();
		
		vector<pair<int, int> > cand;
		
		for(int i=0;i<Cheese.size();i++){
			int x=Cheese[i].first; int y=Cheese[i].second;
			if(Arr[y][x]==1 && !visited[y][x])
				if(CheeseCheck(Cheese[i].first, Cheese[i].second))
					cand.push_back({Cheese[i].first, Cheese[i].second});
		}
		
		for(int i=0;i<cand.size();i++){
			Arr[cand[i].second][cand[i].first]=0;
		}	
		
		bool t=false;
		for(int i=0;i<Cheese.size();i++){
			if(Arr[Cheese[i].second][Cheese[i].first]==1)
				t=true;
		}
		
		if(!t) break;
	}
}

int main(void) {
	//input
	cin >> N >> M;
	for(int y=1;y<=N;y++){
		for(int x=1;x<=M;x++){
			cin >> Arr[y][x];
			if(Arr[y][x]==1){
				Cheese.push_back({x,y});
			}
		}
	}
	
	Solution();
	
	cout << result;
	return 0;
}