#include <bits/stdc++.h>

using namespace std;

int N, M, L; // 휴게소의 개수, 추가 휴게소, 고속도로의 길이이

vector<int> arr, dist;
int res=0;

bool countDiv(int x){
    int cnt=0;
    for(int i=dist.size()-1;i>=0;i--){
        int curr = dist[i];

        if(curr <= x){
            break;
        }

        cnt += curr / x;
        if(curr%x==0) cnt--;
    }


    if(cnt <= M){
        res = x;
        return true;
    }
    else
        return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> L;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    dist.push_back(arr[1]); dist.push_back(L-arr[N]);
    for(int i=1;i<N;i++){
        dist.push_back(arr[i+1]-arr[i]);
    }
    sort(dist.begin(), dist.end());

    int left = 1, right = L;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(countDiv(mid)){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << res;
}
