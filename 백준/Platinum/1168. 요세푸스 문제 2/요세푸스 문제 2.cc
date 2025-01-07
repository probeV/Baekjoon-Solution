#include<bits/stdc++.h>

using namespace std;

int N, K;

class SegmentTree{
private:
    vector<int> tree;
    vector<int> data;
    int size;

    int build(int node, int start, int end){
        if(start==end)
            return ++tree[node];

        int mid = (start + end)/2;
        return tree[node] = build(node*2, start, mid) + build(node*2+1, mid+1, end);
    }

    int query(int node, int start, int end, int target){
        tree[node]--;

        if(start==end)
            return start;

        int mid = (start+end)/2;

        if(tree[node*2] >= target){
            // 왼쪽으로 
            return query(node*2, start, mid, target);
        }
        else{
            // 오른쪽으로 
            return query(node*2+1, mid+1, end, target-tree[node*2]);
        }
    }
public:
    SegmentTree(vector<int> input){
        data=input;
        size = input.size();
        tree.resize(size*4, 0);
        build(1,1,size);
    }

    int query(int X){
        return query(1,1,size,X);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    vector<int> input(N+1);
    for(int i=1;i<=N;i++){
        cin >> input[i];
    }
    SegmentTree segmentTree(input);

    int target=K;
    cout << "<";
    while(N--){
        cout << segmentTree.query(target);
        //cout << target;

        if(N!=0){
            cout << ", ";
            target = (target+K-1)%N;
            if(target == 0) target=N;
        }
        else{
            cout << ">";
        }
        
    }
}


//        7
//    4       3
//  2   2   2   1
// 1 1 1 1 1 1 

// 1 2 3 4 5 6 7

// 1 2 3 4 5 6 7 -> target : 3 / 3
// 1 2 4 5 6 7   -> target : 5 / 6
// 1 2 4 5 7     -> target : 2 / 2
// 1 4 5 7       -> target : 4 / 7
// 1 4 5         -> target : 3 / 5
// 1 4           -> target : 1 / 1
// 4             -> target : 1 / 4