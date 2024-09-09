#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    int N, M;
    cin >> N >> M;

    unordered_set<string> keywords;  // 메모장의 키워드들을 저장할 unordered_set
    string keyword;

    // 메모장에 있는 키워드 입력받기
    for (int i = 0; i < N; ++i) {
        cin >> keyword;
        keywords.insert(keyword);
    }

    string line;

    // 글에서 사용된 키워드를 입력받고 처리하기
    cin.ignore();  // 버퍼 비우기 (개행 문자 처리)
    for (int i = 0; i < M; ++i) {
        getline(cin, line);  // 한 줄 전체 입력

        stringstream ss(line);
        while (getline(ss, keyword, ',')) {
            keywords.erase(keyword);
        }

        // 남은 메모장의 키워드 개수 출력
        cout << keywords.size() << "\n";
    }

    return 0;
}
