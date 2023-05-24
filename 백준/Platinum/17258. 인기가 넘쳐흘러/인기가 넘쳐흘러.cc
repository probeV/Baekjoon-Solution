#include <bits/stdc++.h>

using namespace std;

//최대 사람 수
#define SIZE 301

//최대 수
#define INF INT_MAX

//파티 시간, 초대 사람 수, 친구 수, 최소 인원
int N, M, K, T;

//초대 받은 사람 수 정보, 영선이 친구 입출 조건
int totalArr[SIZE];

//DP 케이스 코드, 시간
int dp[SIZE][SIZE];

//caseNum을 이용하여 같은 케이스 내부에서는 합쳐지지 않도록하는 knasp 응용
void DP(vector<pair<int, int> > caseArr, int caseNum) {
	dp[caseNum][0] = 0;

	//그전 caseNum 그대로 가져오기
	for (int i = 1; i <= N; i++)
		dp[caseNum][i] = dp[caseNum - 1][i];

	for (int i = 0; i < caseArr.size(); i++) {
		for (int j = N; j >= caseArr[i].first; j--) {
			int pre = j - caseArr[i].first;
			//전 케이스에서 값이 존재 할 때
			if (dp[caseNum - 1][pre] != INF) {
				//원래 있던거, 전 케이스에서 현재 꺼 더한거 비교
				dp[caseNum][j] = min(dp[caseNum][j], dp[caseNum - 1][pre] + caseArr[i].second);
			}
		}
	}
}

int case_division(int idx, int caseNum) {
	vector<pair<int, int> > caseArr;

	int i = idx;
	for (; totalArr[i] < T && i <= N; i++) {
		int target = totalArr[i];
		int personCount = T - target;
		int timeCount = 0;
		//case 내의 case

		//바로 왼쪽의 필요인원이 현재보다 작은 경우 포함
		if (i != idx && caseArr[caseArr.size() - 1].second <= personCount)
			timeCount += caseArr[caseArr.size() - 1].first;

		//오른쪽으로 탐색
		for (int j = i; totalArr[j] >= target && totalArr[j] < T && j <= N; j++) {
			timeCount++;
			//다음 인덱스 최적화
			if (totalArr[j] == target)
				i = j;
		}

		//시간, 필요인원 대입
		caseArr.push_back({timeCount, personCount});
	}

	DP(caseArr, caseNum);

	return i-1;
}

void init() {
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++)
		dp[0][i] = INF;
}

int main(void) {
	cin >> N >> M >> K >> T;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < b; j++)
			totalArr[j]++;
	}

	//DP 값 초기화
	init();

	int caseNum = 0; int temp = 0;
	for (int i = 1; i <= N; i++) {
		//case 나누기
		if (totalArr[i] < T) {
			caseNum++;
			i = case_division(i, caseNum);
		}
		//충분한 인원
		else 
			temp++;
	}

	//결과값 찾기
	for (int i = N; i >= 1; i--) {
		if (dp[caseNum][i] <= K) {
			cout << i+temp;
			return 0;
		}
	}

	cout << temp;
	return 0;
}

//3 3 2 3
//1 4
//1 5
//1 4
//
//2 2 2 0