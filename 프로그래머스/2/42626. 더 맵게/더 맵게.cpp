#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;  
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(true){
        // 가장 작은 스코빌 지수 체크
        if(pq.top() >= K) break;
        
        // 모든 음식 K 이상으로 만들 수 없을때
        if(pq.size() <= 1){
            answer=-1;
            break;
        }
        
        // 음식 합치기
        int f1 = pq.top(); pq.pop();
        int f2 = pq.top(); pq.pop();
        
        pq.push(f1+f2*2);
        
        answer++;
    }
    
    return answer;
}