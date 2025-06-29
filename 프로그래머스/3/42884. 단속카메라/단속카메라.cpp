#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 모든 차량은 단속용 카메라 한번은 만나게 -> 최소 몇대 설치?
// 진입 지점, 나간지점

// 곂치는 곳 최대한 활용 -> 그냥 앞에서 부터 그리디하게?
//   시작 지점으로 정렬? -> [-20, -15], [-18, -13], [-14,-5], [-5,-3]
//   범위 큰 순서 대로? x 

// 
int cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), cmp);
    int tmp=routes[0][1];
    for(int i=1;i<routes.size();i++){
        if(tmp >= routes[i][0]) continue;
        
        tmp=routes[i][1];
        answer++;
    }
    
    
    return answer;
}