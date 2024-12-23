#include<bits/stdc++.h>

using namespace std;

int T, N;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int i=1;i<=T;i++){
        cin >> N;
        vector<int> arr;
        arr.resize(N);
        for(int j=0;j<N;j++){
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());

        int target_L = arr[N-1], target_R = arr[N-1];
        int res=0;
        for(int j=N-2;j>=0;){

            if(res < target_L - arr[j]){
                res = target_L - arr[j];
            }
            target_L = arr[j];
            j--;

            if(j<0) break;
            
            if(res < target_R - arr[j]){
                res = target_R - arr[j];
            }
            target_R = arr[j];
            j--;
        }

        if(res < abs(target_L - target_R))
            res = res < abs(target_L - target_R);

        cout << res << "\n";
    }
}


// 2, 4, 5, 7, 9
// 2, 9, 7, 4, 5    -> 7 
// 2, 5, "9", 7, 4  -> 4

// 2, 4, 5, 7, 9, 12
// 2, 5, 9, "12", 7, 4  -> 5

// 정렬 후 
// 가장 큰거 가운데 나두고 왼쪽 오른쪽 하나씩 분배 
