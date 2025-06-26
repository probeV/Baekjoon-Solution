#include <string>
#include <vector>

using namespace std;

vector<int> isVisited(200,false);

void DFS(int start, int n, vector<vector<int>> computers){
    isVisited[start]=true;
    
    for(int i=0;i<n;i++){ // start와 연결된 노드 순회
        if(computers[start][i]==1 && !isVisited[i]){ // i 노드가 연결 되어 있고, 아직 방문하지 않았을 때 
            isVisited[i]=true;
            DFS(i,n,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(!isVisited[i]){
            answer++;
            DFS(i, n, computers);
        }
    }
    
    
    return answer;
}