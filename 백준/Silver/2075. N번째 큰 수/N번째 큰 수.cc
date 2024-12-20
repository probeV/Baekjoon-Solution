#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int> > arr;
vector<int> m, idx;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> N;

    arr.resize(N, vector<int>(N));
    m.resize(N);
    idx.resize(N, N-1);

    for(int y=0;y<N;y++){
        for(int x=0;x<N;x++){
            cin >> arr[y][x];

            if(y==N-1) m[x]=arr[y][x];
        }
    }

    for(int i=1;i<N;i++){
        vector<int>::iterator iter= max_element(m.begin(), m.end());

        int target_x = iter - m.begin();
        int target_y = --idx[target_x];

        // cout << *iter << "/" << target_x << " " << target_y << "\n";

        if(target_y >= 0){
            *iter = arr[target_y][target_x];
        }
        else{
            *iter = -1;
        }
        
    }

    cout << *max_element(m.begin(), m.end());
}


// 각 행 마다 정렬 nlogn * n -> 가능하긴함 

// 12,7,9,15,5 -> 최솟값 min_element 찾기 
// 12,7,9,15,6
// 12,7,9,15,16
// 12,8,9,15,16
// 12,10,9,15,16
// 12,10,11,15,16 ...

// 5
// 12 7 9 15 5      -> 5 7 9 12 15
// 13 8 11 19 6     -> 6 8 11 13 19
// 21 10 26 31 16   -> 10 16 21 26 31
// 48 14 28 35 25   -> 14 25 28 35 48
// 52 20 32 41 49   -> 20 32 41 49 52

