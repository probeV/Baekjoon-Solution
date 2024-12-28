#include <bits/stdc++.h>

using namespace std;

#define DIVISION 1000000007

int N, M, K;

class SegmentTree{
private:
    vector<int> tree;
    vector<int> data;
    int size;

    int init(int node, int start, int end){
        if(start == end)
            return tree[node]=data[start];

        int mid = (start + end)/2;
        return tree[node] = ((long long)init(node*2, start, mid) * init(node*2 + 1, mid+1, end))%DIVISION;
    }
    
    void update(int node, int start, int end, int index, int value){
        if(index > end || index < start)
            return;

        if(start == end){
            tree[node]=value;
            return;
        }

        int mid = (start + end)/2;
        update(node*2, start, mid, index, value);
        update(node*2+1, mid+1, end, index, value);
        tree[node]=((long long)tree[node*2]*tree[node*2 + 1])%DIVISION;
    }

    int query(int node, int start, int end, int left, int right){
        if(left > end || right < start)
            return 1;

        if(left <= start && right >= end)
            return tree[node];

        int mid = (start + end)/2;
        return ((long long)query(node*2, start, mid, left, right) * query(node*2+1, mid+1, end, left, right))%DIVISION;
    }

public:
    SegmentTree(vector<int> input){
        size = input.size();
        data=input;
        tree.resize(size*4);
        init(1, 0, size-1);
    }

    void update(int index, int value){
        update(1, 0, size-1, index, value);
    }

    int query(int left, int right){ 
        return query(1, 0, size-1, left, right);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    vector<int> input(N);
    for(int i=0;i<N;i++){
        cin >> input[i];
    }

    SegmentTree segmentTree(input);

    int a, b, c;
    for(int i=1;i<=M+K;i++){
        cin >> a >> b >> c;

        if(a==1){
            segmentTree.update(b-1,c);
        }
        else if(a==2){
            cout << segmentTree.query(b-1,c-1)%DIVISION << "\n";
        }
        
    }
}
