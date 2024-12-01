#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;
vector<int> arr, mv, isVisited;

void BFS(int x){

    queue<int> q;

    isVisited[x]=1;
    q.push(x);

    while(!q.empty()){
        int curr = q.front();
        int cnt  = isVisited[curr];
        q.pop();

        for(int i=0;i<2;i++){
            int next = curr + mv[i]*(int)pow(-1,i);

            if(next <= 0 || next > F) continue;

            if(!isVisited[next]){
                isVisited[next]=cnt+1;
                q.push(next);
            }
        }
    }
}

int main(){
    cin >> F >> S >> G;

    arr.resize(F+1);
    isVisited.resize(F+1);
    mv.resize(2);

    for(int i=0;i<2;i++)
        cin >> mv[i];

    BFS(S);

    if(isVisited[G]!=0)
        cout << isVisited[G]-1;
    else
        cout << "use the stairs";
}