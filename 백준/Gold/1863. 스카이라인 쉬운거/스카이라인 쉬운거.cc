#include <bits/stdc++.h>

using namespace std;

int n, res=0;
stack<int> s;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int temp1, temp2;
    for(int i=1;i<=n;i++){
        cin >> temp1 >> temp2;
        
        if((s.empty() || s.top() < temp2) && temp2 !=0){
            s.push(temp2);
            res++;
        }
        else if(!s.empty() || s.top() > temp2){
            while(!s.empty() && s.top() > temp2){
                s.pop();
            }
            
            if((s.empty() || s.top() < temp2) && temp2!=0){
                s.push(temp2);
                res++;
            }
        }
    }  

    cout << res;  
}