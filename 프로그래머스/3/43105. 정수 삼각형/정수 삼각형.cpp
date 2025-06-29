#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp = triangle; 
    int n = triangle.size();
    
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<triangle[i].size();j++){
            int curr = triangle[i][j];
            int left  = triangle[i+1][j]   + curr;
            int right = triangle[i+1][j+1] + curr;
            
            if(left > right){
                triangle[i][j]=left;
            }
            else{
                triangle[i][j]=right;
            }
        }
    }
    
    return triangle[0][0];
}

// 거쳐간 숫자의 합 최댓값 
// 그리디 하게 큰 숫자들만 더하면서? 7 -> 8 -> 1 -> 7 -> 5 = 28 x
// DP -> 합 하며 내려가며 곂치는 부위에서는 가장 큰수가 되도록 -> 2^(t-1) 개 
// 7 -> 10, 15 -> 18, (11, v16), 15 -> ...
// 밑에서 부터 올라가게?