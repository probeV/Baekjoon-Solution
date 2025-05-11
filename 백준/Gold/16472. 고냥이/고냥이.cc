#include<bits/stdc++.h>
using namespace std;

int N, res=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    string arr;
    cin >> arr;

    vector<int> alpa(26);
    int cnt=0, len=0;
    int left=0;
    for(int right=0;right<arr.size();right++){
        int remove = arr[left]-97;
        int add = arr[right]-97;
        
        if(alpa[add]==0){
            cnt++;
        }
        alpa[add]++;
        len++;

        if(cnt > N){
            alpa[remove]--;
            len--;
            if(alpa[remove]==0){
                cnt--;
            }
            left++;
        }
        
        res = res > len ? res : len;
    }
    cout << res;
}