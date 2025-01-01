#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
private:
    vector<long long> tree;
    vector<int> data;
    vector<long long> lazy;
    int size;

    long long init(int node, int start, int end){
        if(start == end)
            return tree[node]=data[start];

        int mid = (start + end)/2;
        return tree[node] = init(node*2, start, mid) + init(node*2 + 1, mid+1, end);
    }

    void propagate(int node, int start, int end){
        if(lazy[node]!=0){
            tree[node]+= (end-start+1)*lazy[node];

            if(start!=end){
                lazy[node*2]+=lazy[node];
                lazy[node*2+1]+=lazy[node];
            }

            lazy[node]=0;
        }
    }
    
    void updateRange(int node, int start, int end, int left, int right, int value){
        propagate(node, start, end);

        if(left > end || right < start)
            // 범위 밖
            return;

        if(left <= start && right >= end){
            // 범위 안
            tree[node]+=(end-start+1)*value;
            if(start!=end){
                lazy[node*2]+=value;
                lazy[node*2+1]+=value;
            }
            return;
        }

        int mid = (start + end)/2;
        updateRange(node*2, start, mid, left, right, value);
        updateRange(node*2+1, mid+1, end, left, right, value);
        tree[node]=tree[node*2]+tree[node*2 + 1];
    }

    long long query(int node, int start, int end, int left, int right){
        propagate(node, start, end);

        if(left > end || right < start)
            return 0;

        if(left <= start && right >= end)
            return tree[node];

        int mid = (start + end)/2;
        return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
    }

public:
    SegmentTree(vector<int> input){
        size = input.size();
        data=input;
        tree.resize(size*4);
        lazy.resize(size*4);
        init(1, 0, size-1);
    }

    void updateRange(int left, int right, int value){
        updateRange(1, 0, size-1, left, right, value);
    }

    long long query(int left, int right){ 
        return query(1, 0, size-1, left, right);
    }
};

int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> input(N);
    for(int i=0;i<N;i++){
        cin >> input[i];
    }
    
    SegmentTree segmentTree(input);

    cin >> M;
    for(int i=1;i<=M;i++){
        int order;
        cin >> order;

        if(order==1){
            int left,right,value;
            cin >> left >> right >> value;
            segmentTree.updateRange(left-1, right-1, value);
        }
        else if(order==2){
            int q;
            cin >> q;
            cout << segmentTree.query(q-1,q-1) << "\n";
        }
    }

}
