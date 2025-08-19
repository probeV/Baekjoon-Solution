#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

void BFS(int n, map<int, vector<int> > &arr, vector<int> &answer, int &max_turn){
    queue<pair<int, int> > q;   // pair<int, int> --> 현재 node, 현재 turn
    vector<bool> isVisited(n+1, false);
    int cnt=0;
    
    answer[cnt]=0;
    isVisited[1]=true;
    q.push({1, cnt});
    
    while(!q.empty()){
        int curr_node = q.front().first;
        int curr_turn = q.front().second;
        q.pop();
        
        if(curr_turn == cnt){
            cnt++;
        }
            
        for(auto next_node : arr[curr_node]){
            
            if(isVisited[next_node]) // next_node를 아직 방문했으면 pass
                continue;
            
            answer[next_node]=cnt;
            isVisited[next_node]=true;
            q.push({next_node, cnt});
        }
    }
    
    max_turn = cnt;
}

// 1번 노드에서 가장 멀리 떨어진 노드의 갯수 
int solution(int n, vector<vector<int>> edge) {
    int a = 0; int max_turn=0;
    map<int, vector<int> > arr;
    vector<int> answer(n+1,0);
    
    for(int i=0;i<edge.size();i++){
        int start = edge[i][0];
        int end   = edge[i][1];
        
        arr[start].push_back(end);
        arr[end].push_back(start);
    }
    
    BFS(n, arr, answer, max_turn);
    
    // 최댓값 개수 찾기
    cout << max_turn << " :: ";
    for(auto t : answer){
        cout << t << " ";
        if(t==max_turn-1){
            a++;
        }
    }
    
    return a;
}