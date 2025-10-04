#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
priority_queue<int, vector<int>, greater<int> > rooms;

int main(){
    cin >> N;
    
    for(int i=1;i<=N;i++){
        int S, T;
        cin >> S >> T;

        pq.push({S,T});
    }

    while(!pq.empty()){
        pair<int, int> curr = pq.top(); pq.pop();

        if(rooms.empty()){
            rooms.push(curr.second);
            continue;
        }

        if(rooms.top() > curr.first){
            rooms.push(curr.second);
        }
        else{
            rooms.pop();
            rooms.push(curr.second);
        }
    }

    cout << rooms.size();

}