#include <bits/stdc++.h>

using namespace std;

int N, M;

int BinarySearch(vector<int> &arr, int target) {
    int front = 0, end = arr.size() - 1;
    int mid;

    while (front <= end) {
        mid = (front + end) / 2;

        if (arr[mid] <= target) {
            front = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return arr.size() - front;  // target보다 큰 원소의 개수 반환
}

class SegmentTree {
private:
    vector<vector<int>> tree;
    vector<int> data;
    int size;

    vector<int> build(int node, int start, int end) {
        if (start == end)
            return tree[node] = {data[start]};

        int mid = (start + end) / 2;
        vector<int> leftResult = build(node * 2, start, mid);
        vector<int> rightResult = build(node * 2 + 1, mid + 1, end);

        // Merge Sort
        merge(leftResult.begin(), leftResult.end(),
              rightResult.begin(), rightResult.end(),
              back_inserter(tree[node]));

        return tree[node];
    }

    int query(int node, int start, int end, int left, int right, int value) {
        if (end < left || start > right) {
            return 0;
        }

        if (start >= left && end <= right) {
            return BinarySearch(tree[node], value);
        }

        int mid = (start + end) / 2;
        return query(node * 2, start, mid, left, right, value) +
               query(node * 2 + 1, mid + 1, end, left, right, value);
    }

public:
    SegmentTree(vector<int> input) {
        size = input.size();
        data = input;
        tree.resize(size * 4, vector<int>());
        build(1, 0, size - 1);
    }

    int query(int left, int right, int value) {
        return query(1, 0, size - 1, left, right, value);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    SegmentTree segmentTree(input);

    cin >> M;
    int i, j, k;
    for (int z = 0; z < M; z++) {
        cin >> i >> j >> k;

        // i ~ j 범위에서 k보다 큰 원소의 개수 출력
        cout << segmentTree.query(i - 1, j - 1, k) << "\n";
    }

    return 0;
}
