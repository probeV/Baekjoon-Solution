#include<bits/stdc++.h>

using namespace std;

int N, K;
int num[500001];
deque<int> q;

int main(){
    cin >> N >> K;

    for(int i=0;i<N;i++){
        scanf("%1d", &num[i]);
    }

    // for(int i=0; i<N ; i++){
    //     cout << num[i];
    // }
    // cout << "\n";

    for(int i=0; i<N ; i++){
        // q 가 비어있을 때
        if(q.empty()){
            //cout << "empty : " << num[i] << "\n";
            q.push_back(num[i]);
        }
        //q 의 앞보다 더 큰 수가 나왔을 때 
        else if ( q.back() < num[i] ){
            int qsize = q.size();
            // 어디까지 지울껀가? (남은 숫자가 넉넉히 남아 있을 때 만 교체 가능)
            while( !q.empty() && qsize>=i-K+1 && q.back()<num[i] ){
                //cout << "pop : " << q.back() << "\n";
                q.pop_back();
                qsize = q.size();
            }
            //cout << (q.size()>=i-K+1)  << num[i] << "\n";
            q.push_back(num[i]);
        }
        // 가장 뒤에 숫자보다 작거나 같을 때, 새로운 자릿수로 추가 ,
        else if(q.back() >= num[i] && q.size() < N-K){
            //cout << "new : " << num[i] << "\n";
            q.push_back(num[i]);
        }
    }

    while(!q.empty()){
        cout << q.front();
        q.pop_front();
    }
}