#include<bits/stdc++.h>

using namespace std;

int N, B, W; // 최대 개수 B, 최소개수 W

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B >> W;

    vector<char> arr(N);
    for(int i=0;i<N;i++){
        cin >>arr[i];
    }

    int left=0;
    int cntW=0, cntB=0, len=0, res=0;
    for(int right=0;right<N;right++){
        if(arr[right]=='W'){
            cntW++;
            len++;
        }
        else{ // arr[right]=='B'
            if(cntB >= B){ // B 최대 개수가 넘어 갔다면 

                if(cntW >= W){ // W 최소 개수를 넘겼다면
                    // 준표가 원하는 조건에 맞는 구간이 O
                    res = res < len ? len : res; 
                }

                while(cntB >= B){ // left에서 B가 하나 빠질때 까지
                    len--;
                    if(arr[left]=='W'){
                        cntW--;
                    }
                    else{ // arr[left]=='B'
                        cntB--;
                    }
                    left++;
                }

                cntB++;
                len++;
            }
            else{ // B 최대 개수가 넘어가지 않았다면
                cntB++;
                len++;
            }
        }
    }

    if(cntW>=W && cntB<=B) {
        res = res < len ? len : res; 
    }
    cout << res;
}   


