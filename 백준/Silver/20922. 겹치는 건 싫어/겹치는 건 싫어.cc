#include<bits/stdc++.h>

using namespace std;

int N, K;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    int res=0;
    map<int, pair<int, int> > temp;
    int cnt=0;
    for(int i=1;i<=N;i++){

        // map에 이미 있으면 
        if(temp.find(arr[i]) != temp.end()){
            // 최대 갯수보다 적은지 체크
            if(temp[arr[i]].second < K){
                temp[arr[i]].second++;
                cnt++;
            }
                
            else{
                // 초기화
                i=temp[arr[i]].first;
                temp.clear();
                cnt=0;
                //cout << i;
            }
        }
        // map에 값 추가
        else{
            temp[arr[i]].first=i;
            temp[arr[i]].second=1;
            cnt++;
        }

        // 더 큰 부분 수열 이면
        if(cnt > res) res = cnt;
    }

    cout << res;
}