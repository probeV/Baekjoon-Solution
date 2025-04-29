#include<bits/stdc++.h>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int left=0, right=N-1;
    pair<int,int> res={1000000001, 1000000001};
    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum==0 || abs(res.first + res.second) > abs(sum)){
            res.first=arr[left];
            res.second=arr[right];

            if(sum==0)
                break;
        }
        else if(sum < 0){
            left++;
        }
        else{
            right--;
        }
    }
    cout << res.first << " " << res.second;

}