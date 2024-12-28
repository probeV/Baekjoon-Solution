#include <bits/stdc++.h>

using namespace std;

int N, M, K;

class SegmentTree{
private:
    vector<long long> tree;
    vector<long long> data;
    int size;

    long long init(int node, int start, int end){
        if(start == end)
            return tree[node]=data[start];

        int mid = (start + end)/2;
        return tree[node] = init(node*2, start, mid) + init(node*2 + 1, mid+1, end);
    }
    
    void update(int node, int start, int end, int index, long long value){
        if(index > end || index < start)
            return;

        if(start == end){
            tree[node]=value;
            return;
        }

        int mid = (start + end)/2;
        update(node*2, start, mid, index, value);
        update(node*2+1, mid+1, end, index, value);
        tree[node]=tree[node*2]+tree[node*2 + 1];
    }

    long long query(int node, int start, int end, int left, int right){
        if(left > end || right < start)
            return 0;

        if(left <= start && right >= end)
            return tree[node];

        int mid = (start + end)/2;
        return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
    }

public:
    SegmentTree(vector<long long> input){
        size = input.size();
        data=input;
        tree.resize(size*4);
        init(1, 0, size-1);
    }

    void update(int index, long long value){
        update(1, 0, size-1, index, value);
    }

    long long query(int left, int right){ 
        return query(1, 0, size-1, left, right);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    vector<long long> input(N);
    for(int i=0;i<N;i++){
        cin >> input[i];
    }

    SegmentTree segmentTree(input);

    int a, b;
    long long c;
    for(int i=1;i<=M+K;i++){
        cin >> a >> b >> c;

        if(a==1){
            segmentTree.update(b-1,c);
        }
        else if(a==2){
            cout << segmentTree.query(b-1,c-1) << "\n";
        }
        
    }
}
