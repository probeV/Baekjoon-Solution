#include<bits/stdc++.h>

using namespace std;

int M, N;

vector<int> arr;
vector<vector<int> > res;

int main(){
    cin >> M >> N;

    arr.resize(2*M);
    res.resize(M+1, vector<int>(M+1));

    for(int i=1;i<=N;i++){
        int idx=1;
        for(int j=1;j<=3;j++){
            int temp;
            cin >> temp;

            for(int k=1;k<=temp;k++){
                arr[idx++]+=j-1;
            }
        }
    }

    // for(int i=1;i<=2*M-1;i++) 
    //     cout << arr[i] << " "; 
    // cout << "\n";

    int idx=1;
    for(int y=M;y>=1;y--){
        res[y][1]=arr[idx++];
    }
    idx--;  
    for(int x=1;x<=M;x++){
        res[1][x]=arr[idx++];
    }

    for(int y=2;y<=M;y++){
        for(int x=2;x<=M;x++){
            res[y][x] = max(res[y-1][x-1] ,max(res[y-1][x], res[y][x-1]));
        }
    }

    for(int y=1;y<=M;y++){
        for(int x=1;x<=M;x++){
            cout << res[y][x]+1 << " ";
        }
        cout << "\n";
    }
}