#include<bits/stdc++.h>

using namespace std;

int N;
vector<vector<char> > arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin.get();

    arr.resize(N+2, vector<char>(N+2));
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            char c = cin.get();
            arr[y][x]=c;
        }
        cin.get();
    }

    //심장 찾기
    int heart_x, heart_y;
    for(int y=1;y<=N;y++){
        for(int x=1;x<=N;x++){
            if(arr[y][x]=='*' && arr[y+1][x]=='*' && arr[y][x+1]=='*' && arr[y-1][x]=='*' && arr[y][x-1]=='*'){
                heart_x = x;
                heart_y = y;
            }
        }
    }
    cout << heart_y << " " << heart_x << "\n";

    //왼쪽 팔, 오른쪽 팔
    int l_arm=0, r_arm=0;
    for(int x=heart_x-1;x>=1;x--){
        if(arr[heart_y][x]=='*'){
            l_arm++;
        }
    }
    for(int x=heart_x+1;x<=N;x++){
        if(arr[heart_y][x]=='*'){
            r_arm++;
        }
    }

    //허리
    int back=0;
    for(int y=heart_y+1;y<=N;y++){
        if(arr[y][heart_x]=='*'){
            back++;
        }
    }

    // 왼쪽 다리, 오른쪽 다리
    int l_leg=0, r_leg=0;
    for(int y=heart_y+1;y<=N;y++){
        if(arr[y][heart_x-1]=='*'){
            l_leg++;
        }
    }
    for(int y=heart_y+1;y<=N;y++){
        if(arr[y][heart_x+1]=='*'){
            r_leg++;
        }
    }

    cout << l_arm << " " << r_arm << " " << back << " " << l_leg << " " << r_leg;

}