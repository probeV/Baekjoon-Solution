#include <bits/stdc++.h>
using namespace std;

struct Node {
    int minVal, maxVal; // 구간의 최솟값과 최댓값
};

class SegmentTree {
private:
    vector<Node> tree; // 세그먼트 트리 배열
    vector<int> data;
    int size;

    void build(int node, int start, int end) {
        if (start == end) {
            // 리프 노드: 자신의 값 저장
            tree[node] = {data[start], data[start]};
        } else {
            int mid = (start + end) / 2;
            build(node * 2, start, mid);
            build(node * 2 + 1, mid + 1, end);

            // 구간의 최솟값과 최댓값 계산
            tree[node].minVal = min(tree[node * 2].minVal, tree[node * 2 + 1].minVal);
            tree[node].maxVal = max(tree[node * 2].maxVal, tree[node * 2 + 1].maxVal);
        }
    }

    void update(int node, int start, int end, int index, int value) {
        if (index < start || index > end) return; // 범위 밖

        if (start == end) {
            // 리프 노드 업데이트
            tree[node] = {value, value};
        } else {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, index, value);
            update(node * 2 + 1, mid + 1, end, index, value);

            // 구간의 최솟값과 최댓값 재계산
            tree[node].minVal = min(tree[node * 2].minVal, tree[node * 2 + 1].minVal);
            tree[node].maxVal = max(tree[node * 2].maxVal, tree[node * 2 + 1].maxVal);
        }
    }

    Node query(int node, int start, int end, int left, int right) {
        if (right < start || left > end) {
            // 범위 밖: 의미 없는 큰/작은 값 반환
            return {INT_MAX, INT_MIN};
        }
        if (left <= start && end <= right) {
            // 구간 안: 현재 노드 반환
            return tree[node];
        }

        int mid = (start + end) / 2;
        Node leftResult = query(node * 2, start, mid, left, right);
        Node rightResult = query(node * 2 + 1, mid + 1, end, left, right);

        // 두 자식 노드 결과 병합
        return {
            min(leftResult.minVal, rightResult.minVal),
            max(leftResult.maxVal, rightResult.maxVal)
        };
    }

public:
    SegmentTree(const vector<int>& input) {
        size = input.size();
        data = input;
        tree.resize(size * 4);
        build(1, 0, size - 1);
    }

    void update(int index, int value) {
        update(1, 0, size - 1, index, value);
        data[index] = value; // 원본 데이터 갱신
    }

    bool query(int left, int right) {
        Node result = query(1, 0, size - 1, left, right);
        // 연속된 범위 확인
        return (result.maxVal == right && result.minVal == left);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> input(N);
        for (int i = 0; i < N; ++i) input[i] = i;

        SegmentTree segmentTree(input);

        for (int i = 0; i < K; ++i) {
            int Q, A, B;
            cin >> Q >> A >> B;

            if (Q == 0) {
                // 교환 작업
                int temp = input[A];
                segmentTree.update(A, input[B]);
                segmentTree.update(B, temp);
                swap(input[A], input[B]);
            } else if (Q == 1) {
                // 쿼리 작업
                if (segmentTree.query(A, B)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
