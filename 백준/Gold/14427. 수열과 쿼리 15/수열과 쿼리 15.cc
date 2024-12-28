#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr, tree;

class SegmentTree{
private:
    vector<pair<int,int> > tree;
    vector<int> data;
    int size;

    pair<int, int> init(int node, int start, int end){
        if (start == end){
            return tree[node] = {data[start], start};
        }

        int mid = (start + end)/2;
        pair<int, int> left = init(node*2, start, mid);
        pair<int, int> right = init(node*2+1, mid+1, end);

        return tree[node] = (left.first <= right.first ? left : right);
    }

    void update(int node, int start, int end, int index, int value){
        if(index < start || index > end) return;

        if(start == end){
            tree[node] = {value,start};
            return;
        }

        int mid = (start + end)/2;
        update(node*2, start, mid, index, value);
        update(node*2+1, mid+1, end, index, value);

        tree[node]=tree[node*2].first <= tree[node*2+1].first ? tree[node*2] : tree[node*2+1];
    }

    pair<int, int> query(int node, int start, int end, int left, int right){
        if(right < start || left > end) return {INT_MAX, -1};

        if(left <= start || right >= end) return tree[node];

        int mid = (start + end)/2;
        pair<int, int> leftResult = query(node*2, start, mid, left, right);
        pair<int, int> rightResult = query(node*2+1, mid+1, end, left, right);

        return (leftResult.first <= rightResult.first ? leftResult : rightResult);
    }

public:
    SegmentTree(vector<int>& input){
        size = input.size();
        data = input;
        tree.resize(size*4);
        init(1,0,size-1);
    }

    void update(int index, int value){
        update(1,0,size-1,index-1,value);
    }

    int getIndexOfMin() {
        return query(1, 0, size - 1, 0, size - 1).second + 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N*4);

    int tmp;
    for(int i=1;i<=N;i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    SegmentTree segmentTree(arr);

    cin >> M;
    for(int i=1;i<=M;i++){
        cin >> tmp;

        if(tmp==1){
            int i, v;
            cin >> i >> v;
            segmentTree.update(i,v);
        }
        else if(tmp==2){
            cout << segmentTree.getIndexOfMin() << "\n";
        }
    }

}