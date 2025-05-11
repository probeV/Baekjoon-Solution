#include<bits/stdc++.h>
using namespace std;

int N, K;
int res=0;

int main(){
    cin >> N >> K;

    vector<int> fire;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(tmp >= K)
            res++;
        else 
            fire.push_back(tmp);
    }

    sort(fire.begin(), fire.end());

    int left=0, right=fire.size()-1;
    while(left < right){
        int sum = fire[left]+fire[right];

        if(sum >= K){
            left++; right--;
            res++;
        }
        else{
            if(fire[left] < fire[right]){
                left++;
            }
            else{
                right--;
            }
        }
    }

    if(res==0)
        cout << -1;
    else
        cout << res;
}