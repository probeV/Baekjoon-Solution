#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int left=0, right=people.size()-1;
    
    while(left <= right){
        // 구명 보트 둘다 넣기
        if(people[left] + people[right] <= limit){
            left++;
            right--;
        }
        // 둘다 불가
        else{
            right--;
        }
        answer++;
    }

    return answer;
}