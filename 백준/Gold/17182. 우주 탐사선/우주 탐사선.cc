#include<bits/stdc++.h>

using namespace std;

int  N, ana;
vector<vector<int> > arr;
bool isVisited[11];
int ans=INT_MAX;

void dfs(int count, int start,  int res){
    if(count == N){
        //cout << res << " ";
        if(ans > res)
            ans=res;
        return;
    }

    for(int i=0;i<N;i++){
        if(!isVisited[i]){
            isVisited[i] = true;
            dfs(count+1, i, res+arr[start][i]);
            isVisited[i] = false;
        }
    }
}

int main(){
    cin >> N >> ana;
    for(int y=0;y<N;y++){
        vector<int> vec;
        arr.push_back(vec);

        for(int x=0;x<N;x++){
            int temp;
            cin >> temp;

            arr[y].push_back(temp);
        }
    }

    for(int k=0;k<N;k++){
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                arr[a][b] = min(arr[a][b], arr[a][k] + arr[k][b]);
            }
        }
    }

    // for(int a=0;a<N;a++){
    //     for(int b=0;b<N;b++){
    //         cout << arr[a][b]  << " ";
    //     }
    //     cout << "\n";
    // }

    isVisited[ana] = true;
    dfs(1, ana, 0);

    cout << ans;
}