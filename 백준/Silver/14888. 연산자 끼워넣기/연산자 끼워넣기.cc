#include<bits/stdc++.h>

using namespace std;

int N, M = INT_MIN, m=INT_MAX;

void DFS(vector<int> num, vector<int> &info, vector<int> &res, int x){
    if(res.size() == N-1){
        for(int i=1;i<N;i++){
            switch (res[i-1]){
                case 1:
                    num[i+1]=num[i]+num[i+1];
                    break;
                case 2:
                    num[i+1]=num[i]-num[i+1];
                    break;
                case 3:
                    num[i+1]=num[i]*num[i+1];
                    break;
                case 4:
                    num[i+1]=num[i]/num[i+1];
                    break;
            }
        }

        if(M < num[N]) M = num[N];

        if(m > num[N]) m = num[N];

        return;
    }

    for(int i=x+1;i<N;i++){
        for(int j=1;j<=4;j++){
            //cout << i << " " << info[j] << "\n";

            if(info[j] > 0){
                res.push_back(j);
                info[j]--;
            }
            else continue;

            DFS(num, info, res, i);

            res.pop_back();
            info[j]++;
        }
    }
}

int main(){
    cin >> N;

    vector<int> num(N+1);
    for(int i=1;i<=N;i++){
        cin >> num[i];
    }

    vector<int> info(5);
    for(int i=1;i<=4;i++){
        cin >> info[i];
    }

    vector<int> res;
    DFS(num, info, res, 0);

    cout << M << "\n" << m;
}