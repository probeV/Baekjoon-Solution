#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int> > > absHeap;

int main(){
    cin >> N;

    for(int i=1;i<=N;i++){
        int tmp; cin >> tmp;

        switch (tmp)
        {
        case 0:
            if(absHeap.size() == 0) cout << 0 << "\n";
            else{
                cout << absHeap.top().second << "\n";
                absHeap.pop();
            }
            break;
        default:
            absHeap.push({abs(tmp), tmp});
            break;
        }
    }

}