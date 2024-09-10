#include<bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int> > arr;
vector<int> r;

int main(){
    cin >> N;

    arr.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    r.resize(N+1, 1);
    for(int i=1;i<=N;i++){
        int curr_x = arr[i].first;
        int curr_y = arr[i].second;

        for(int j=i+1;j<=N;j++){
            int next_x = arr[j].first;
            int next_y = arr[j].second;

            // curr이 덩치가 더 클 때
            if(curr_x > next_x && curr_y > next_y){
                r[j]++;
            }
            // next가 덩치가 더 클 때
            else if(curr_x < next_x && curr_y < next_y){
                r[i]++;
            }
            // 덩치를 비교할 수 없을 때
            else{
                continue;
            }
        }
    }

    for(int i=1;i<=N;i++){
        cout << r[i] << " ";
    }
}