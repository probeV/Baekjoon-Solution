#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int compare(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end(), compare);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  
    
    int curr_time=0, idx=0;
    for(int x=1;x<=jobs.size();x++){
        // 현재 pq가 비어있고 다음 jobs이 들어오지 못하는 상황일 때 현재 시간 재설정
        if(pq.empty() && jobs[idx][0] > curr_time){
            curr_time = jobs[idx][0];
        }
        
        // jobs의 요청 시간이 현재 시간보다 작으면 pq에 넣기
        for(int i=idx;i<jobs.size();i++){
            if(jobs[i][0] <= curr_time){
                pq.push({jobs[i][1], jobs[i][0]});
                idx=i+1;
            }
            else break;
        }
        
        // 시작할 수 있는 jobs들 중에서 소요시간이 가장 짧은 일 부터 하기
        answer += pq.top().first - pq.top().second + curr_time;
        curr_time=curr_time+pq.top().first;
        pq.pop();
    }
    
    return answer/jobs.size();
}