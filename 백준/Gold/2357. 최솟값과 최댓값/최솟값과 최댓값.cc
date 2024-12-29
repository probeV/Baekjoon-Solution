#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
private:
    vector<pair<int,int> > tree;
    vector<int> data;
    int size;

    pair<int,int> init(int node, int start, int end){
        if(start == end){
            tree[node].first = data[start];
            tree[node].second = data[start];
            return tree[node];
        }

        int mid = (start + end)/2;
        pair<int, int> leftResult = init(node*2, start, mid);
        pair<int, int> rightResult = init(node*2 + 1, mid+1, end);
        tree[node].first = leftResult.first < rightResult.first ? leftResult.first : rightResult.first;
        tree[node].second = leftResult.second > rightResult.second ? leftResult.second : rightResult.second;
        return tree[node];
    }

    pair<int,int> query(int node, int start, int end, int left, int right){
        if(left > end || right < start)
            return {INT_MAX, 0};

        if(left <= start && right >= end)
            return tree[node];

        int mid = (start + end)/2;
        pair<int, int> leftResult = query(node*2, start, mid, left, right);
        pair<int, int> rightResult = query(node*2+1, mid+1, end, left, right);
        return {leftResult.first < rightResult.first ? leftResult.first : rightResult.first, leftResult.second > rightResult.second ? leftResult.second : rightResult.second};
    }

public:
    SegmentTree(vector<int> input){
        size = input.size();
        data=input;
        tree.resize(size*4);
        init(1, 0, size-1);
    }

    pair<int,int> query(int left, int right){ 
        return query(1, 0, size-1, left, right);
    }
};

int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<int> input(N);
    for(int i=0;i<N;i++){
        cin >> input[i];
    }

    SegmentTree segmentTree(input);

    int a, b;
    for(int i=1;i<=M;i++){
        cin >> a >> b;

        pair<int, int> res = segmentTree.query(a-1,b-1);
        cout << res.first << " " << res.second << "\n";
        
    }
}
