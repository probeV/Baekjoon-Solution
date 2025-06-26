#include <string>
#include <vector>

using namespace std;

int answer = 1e9;

void DFS(string begin, string target, vector<bool> &isVisited, vector<string> &words, int n){
    if(begin == target && answer > n) {
        answer = n;
    }
    
    for(int i=0;i<words.size();i++){
        if(isVisited[i]) continue; // 이미 방문한 적 있으면 
        
        string curr = words[i];
        
        int cnt=0;
        for(int x=0;x<curr.size();x++){ // 다른 글자가 몇개인지 체크
            if(begin[x]-curr[x]!=0){
                cnt++;
            }
        }
        
        if(cnt==1){ // 1개 바뀌었을 때
            isVisited[i]=true;
            DFS(curr, target, isVisited, words, n+1);
            isVisited[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> isVisited(words.size(), false);
    
    DFS(begin, target, isVisited, words, 0);
    
    if(answer == 1e9) answer = 0;
    
    return answer;
}