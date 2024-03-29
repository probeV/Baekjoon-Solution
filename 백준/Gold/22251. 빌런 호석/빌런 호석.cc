#include <bits/stdc++.h>

using namespace std;

int N, K, P, X;

int res=0;
int revNum [10][10];
int num[10][7]={{1,1,1,1,1,1,0},
                {0,1,1,0,0,0,0}, 
                {1,1,0,1,1,0,1},
                {1,1,1,1,0,0,1},
                {0,1,1,0,0,1,1},
                {1,0,1,1,0,1,1},
                {1,0,1,1,1,1,1},
                {1,1,1,0,0,0,0},
                {1,1,1,1,1,1,1},
                {1,1,1,1,0,1,1}};

void init(){
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            int res=0;

            for(int x=0;x<7;x++){
                res += abs(num[i][x] - num[j][x]);
            }

            revNum[i][j]=res;
            revNum[j][i]=res;
        }
    }

    // for(int i=0;i<=9;i++){
    //     for(int j=0;j<=9;j++){
    //         cout <<  revNum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void DFS(int idx, int changeNum, int change){

    if(idx==0){

        //cout << change << "\n";
        //0 체크
        if(change != 0)
            res++;
        return;
    }

    int curr = (X/(int)pow(10, idx-1)) % 10;

    for(int x=0;x<=9;x++){
        //반전 횟수 체크 + 층수 체크
        if(P >= changeNum  + revNum[curr][x] && N >= change + x*(int)pow(10, idx-1)){
            DFS(idx-1, changeNum+revNum[curr][x], change + x*(int)pow(10, idx-1));
        }
    }


}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> P >> X;

    init();

    DFS(K, 0, 0);

    cout << res-1;

}
