#include <string>
#include <vector>

using namespace std;

int answer=0;

void DFS(int curr, vector<int> numbers, int target, int res){
    if(curr == numbers.size() && res==target){
        answer++;
        return;
    }
    
    if(curr == numbers.size()){
        return;
    }
    
    DFS(curr+1, numbers, target, res+numbers[curr]);
    DFS(curr+1, numbers, target, res-numbers[curr]);
}

int solution(vector<int> numbers, int target) {

    DFS(0,numbers,target, 0);
    
    return answer;
}