#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, x,y;
    cin >> T;

    for(int i=1;i<=T;i++){
        cin >> x >> y;

        int dis=y-x;

        int j=sqrt(dis);

        int res=2*j-1;

        if((int)pow(j,2)==dis){
            cout << res <<"\n";
        }
        else if((int)pow(j,2)+j >=dis){
            cout << res+1 << "\n";
        }
        else{
            cout << res+2 << "\n";
        }

    }
}