#include<bits/stdc++.h>

using namespace std;

# define MAXSIZE 2000001

int N;

class SegmentTree{
private:
    vector<int> tree;
    int size;

    void update(int node, int start, int end, int index){
        if(index < start || index > end) return;

        if(start == end){
            tree[node]++;
            return;
        }

        int mid = (start + end)/2;
        update(node*2, start, mid, index);
        update(node*2+1, mid+1, end, index);
        tree[node]=tree[node*2]+ tree[node*2+1];
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
    SegmentTree(){
        size = MAXSIZE;
        tree.resize(size*4, 0);
    }

    void update(int X){
        update(1,0,size-1,X);
    }

    int query(int X){
        return query(1,0,size-1,X);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    SegmentTree segmentTree;

    while(N--){
        int T, X;
        cin >> T >> X;

        
        if(T==1){
            segmentTree.update(X);
        }
        else if(T==2){
            cout << segmentTree.query(X) << "\n";
        }
    }
}



// 1 3 5

//      3
//    2   1 
//  1   1
// 1 0 1 0 1


// 1 2 3 4 5