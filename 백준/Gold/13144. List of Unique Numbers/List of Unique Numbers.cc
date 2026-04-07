#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N+1);
    for(int i = 1; i <= N; i++) cin >> arr[i];

    unordered_map<int,int> cnt;  // 현재 윈도우 내 원소 등장 횟수
    long long res = 0;
    int l = 1;

    for(int r=1;r<=N;r++){
      cnt[arr[r]]++;

      while(cnt[arr[r]] > 1){
        cnt[arr[l]]--;
        l++;
      }

      res += (r-l+1);
    }

  cout << res;
}