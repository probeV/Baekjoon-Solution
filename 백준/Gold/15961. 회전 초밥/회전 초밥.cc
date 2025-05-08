#include<bits/stdc++.h>
using namespace std;

int N, d, k, c; // 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> d >> k >> c;

    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    vector<int> kind(d+1,0);
    int cnt=0;

    // 초기 윈도우 설정
    for (int i = 0; i < k; i++) {
        if (kind[arr[i]] == 0) cnt++;
        kind[arr[i]]++;
    }

    int result = cnt + (kind[c] == 0 ? 1 : 0);
    for(int i=1;i<N;i++){
        int remove = arr[(i-1)%N];
        int add = arr[(i+k-1)%N];

        kind[remove]--;
        if(kind[remove] == 0) cnt--;

        if(kind[add]==0) cnt++;
        kind[add]++;

        int total = cnt + (kind[c] == 0 ? 1 : 0);
        result = max(result, total);
    }

    cout << result << '\n';
}