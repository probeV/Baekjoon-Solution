#include <iostream>
#include <vector>
#include <set>

#define MAXSIZE 1001

using namespace std;

int C, N;
vector<int> cnt;
set<pair<int, int> > res;

int gcd(int a,int b) 
{
    if(b==0)
        return a;
    else
        return gcd(b, a % b);
}

void dp(){

    for(int x=1;x<=MAXSIZE;x++){

        for(int y=0;y<x;y++){

            int tmp = gcd(x,y);
            int _x = x / tmp;
            int _y = y / tmp;
            
            res.insert({_x,_y});
        }
        cnt[x]= res.size()*2 + 1;
    }
}

int main(){
    cin >> C;
    cnt.resize(MAXSIZE, 0);

    dp();
    
    for(int i=1;i<=C;i++){
        cin >> N;

        cout << cnt[N] << "\n";
    }
}
