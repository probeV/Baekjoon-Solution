#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    for(int i=0;i<works.size();i++){
        pq.push(works[i]);
    }
    
    for(int i=0;i<n;i++){
        int curr = pq.top();
        pq.pop();
        
        if(curr > 0)
            pq.push(curr-1);
        else
            pq.push(0);
    }
    
    while(!pq.empty()){
        int curr = pq.top();
        answer += curr*curr;
        pq.pop();
    }
    
    return answer;
}
// N 시간 동안 피로도 최소화 

// 남은 일의 작업량 ^ 2 -> 평탄화 시키기?
// 그리디 하게 접근? -> 최대 최소 구하고 -> 최댓값을 깍아내려간다 
// 최댓값 깎은 후 다시 최댓값 조회 -> 2*10^4 * 10^6 = 10^10 -> 1초 이상 시간 초과?
// Priority_queue 사용 -> 깎아내고 push 하고 top()^2 -> pop()