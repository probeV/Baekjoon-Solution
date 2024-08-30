#include<bits/stdc++.h>

using namespace std;

struct info
{
    int x1;
    int y1;
    int x2;
    int y2;
};

int N, M;
vector<vector<int> > arr;
vector<info> order;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    arr.resize(N+1, vector<int>(N+1, 0));
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            cin >> arr[y][x];
        }
    }

    order.resize(M+1);
    for(int i=1;i<=M;i++){
        cin >> order[i].y1 >> order[i].x1 >> order[i].y2 >> order[i].x2;
    }

    for(int x=1;x<=N;x++){
        for(int y=1;y<=N;y++){
            arr[y][x] = arr[y][x-1] + arr[y-1][x] + arr[y][x] - arr[y-1][x-1];
        }
    }

    // for(int y=1;y<=N;y++){
    //     for(int x=1;x<=N;x++){
    //         cout << arr[y][x] << " ";
    //     }
    //     cout << "\n";
    // }

    // 전체 -  왼쪽 y축 전체 - 위쪽 x 축 전체 + 왼쪽, 위쪽 곂치는 부분
    for(int i=1;i<=M;i++){
        int x1 = order[i].x1; int y1 = order[i].y1;
        int x2 = order[i].x2; int y2 = order[i].y2;
        
        int res = arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1];

        cout << res << "\n";
    }

}