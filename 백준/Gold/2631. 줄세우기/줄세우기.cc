#include <bits/stdc++.h>

#define MAXSIZE 201

using namespace std;

int N;
vector<int> arr;
vector<int> pos;

int LIS[MAXSIZE];
int cnt=0;

void position(int x){
    for(int i=0;i<cnt;i++){
        if(LIS[i]>x){
            LIS[i]=x;
            pos.push_back(i);
            return;
        }
    }
    LIS[cnt]=x;
    pos.push_back(cnt++);
}

int main(){
    cin >> N;

    for(int i=1;i<=N;i++){
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }

    LIS[cnt]=arr[0];
    pos.push_back(cnt++);

    for(int i=1;i<N;i++){
        position(arr[i]);
    }

    int max=0;
    for(int i=0;i<N;i++){
        if(max < pos[i]){
            max  = pos[i];
        }
    }

    cout << N-(max+1);
}