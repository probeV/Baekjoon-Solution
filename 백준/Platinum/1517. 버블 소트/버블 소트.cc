#include <bits/stdc++.h>

using namespace std;

int N;

typedef struct Tree{
    long long count;
    vector<int> subArray;
}Tree;

class SegmentTree{
private:
    vector<Tree> tree;
    vector<int> data;
    int size;

    Tree init(int node, int start, int end){
        if(start == end){
            tree[node].count = 0;
            tree[node].subArray.push_back(data[start]);
            return tree[node];
        }
            
        int mid = (start + end)/2;
        Tree leftResult = init(node*2, start, mid);
        Tree rightResult = init(node*2+1, mid+1, end);
        tree[node].count += leftResult.count + rightResult.count;
        
        // Merge Sort
        int l=0,r=0;
        vector<int> leftArr = leftResult.subArray, rightArr = rightResult.subArray;
        while(l < leftArr.size() && r < rightArr.size()){
            if(leftArr[l] <= rightArr[r]){
                tree[node].subArray.push_back(leftArr[l]);
                l++;
            }
            else{
                tree[node].subArray.push_back(rightArr[r]);
                tree[node].count+=leftArr.size()-l;
                r++;
            }
        }

        if(l >= leftArr.size()){
            for(int i=r;i<rightArr.size();i++){
                tree[node].subArray.push_back(rightArr[i]);
            }
        }
        else{
            for(int i=l;i<leftArr.size();i++){
                tree[node].subArray.push_back(leftArr[i]);
            }
        }
        return tree[node];
    }

    long long query(int node, int start, int end, int left, int right){
        if(left > end || right < start)
            return 0;

        if(left >= start && right <= end){
            return tree[node].count;
        }

        int mid = (start + end)/2;
        return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
    }

public:
    SegmentTree(vector<int> input){
        size=input.size();
        data=input;
        tree.resize(size*4);
        init(1, 0, size-1);
    }

    long long query(int left, int right){
        return query(1, 0, size-1, left, right);
    }
};


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

    cout << segmentTree.query(0,N-1);

}
