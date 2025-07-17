#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, n, m;
    vector<int> a, b;

    cin >> T;

    cin >> n;
    for(int i=0;i<n;i++){
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int tmp; cin >> tmp;
        b.push_back(tmp);
    }

    // 누적합
    vector<int> sumA(n+1,0), sumB(m+1,0);
    for(int i=0;i<n;i++){
        sumA[i+1]=a[i]+sumA[i];
    }
    for(int i=0;i<m;i++){
        sumB[i+1]=b[i]+sumB[i];
    }

    // 부 배열들의 합, 그 합의 경우의 수
    map<int, long long> A, B; // 합, 그 합의 경우의 수
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int curr = sumA[j]-sumA[i-1];
            if(A.find(curr)!=A.end()){ // A에 curr이 존재할 때
                A[curr]++;
            }
            else{
                A[curr]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            int curr = sumB[j]-sumB[i-1];
            if(B.find(curr)!=B.end()){ // B에 curr이 존재할 때
                B[curr]++;
            }
            else{
                B[curr]=1;
            }
        }
    }

    long long answer = 0;
    for(auto [key, value] : A){
        //cout << key << " " << value << "\n";
        if(B.find(T-key)!=B.end()){ // T-key, 즉 A,B 부 배열 합이 T가 만들어질 때
            answer += value * B[T-key];
        }
    }
    // 0 1 4 5 7
    // 0 1 4 6
    cout << answer;
}