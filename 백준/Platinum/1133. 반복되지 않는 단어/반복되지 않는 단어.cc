#include <bits/stdc++.h>

using namespace std;

#define start 65
#define SIZE 51

int K, N, A;

string str;
char temp[SIZE];

bool Check(int idx) {
	//지금까지의 확인된 string
	string curr = str.substr(1, idx);

	//찾아야할 문자 개수들
	for (int i = curr.length() / K; i >= 1; i--) {

		//curr의 오른쪽 끝에서 비교에 기준이되는 문자열
		string next = curr.substr(idx - i, i);

		for (int j = 2; j <= K; j++) {
			//연속된 문자열이 있나 체크해야 하는 문자열
			string check = curr.substr(idx - j * i, i);
			int check_idx = check.find(next);

			//연속된 문자열이 존재하지 않음
			if (check_idx != 0) break;
			//연속된 문자열이 존재함
			else if (j == K) return false;
		}
	}
	return true;
}

void Backtracking(int idx) {
	if (idx == N + 1) {
		for (int i = 1; i <= N; i++) {
			cout << str[i];
		}
		exit(0);
	}

	//지금 인덱스의 알파벳이 넘어가지 않았을 때
	while (str[idx] < start + A) {
		//연속된 문자열이 없을 때 다음 인덱스로 넘어가기
		if (Check(idx))
			Backtracking(idx + 1);

		//연속된 문자열이 있을 때 
		//지금 인덱스의 값을 다음 알파벳으로 넘어가기
		temp[idx] = temp[idx] + 1;
		str = string(temp);
	}

	//지금 인덱스가 다음 알파벳으로 넘어갔을 경우 그 전 인덱스의 문제
	//이 때 idx가 1일때는 진짜 못만드는 경우
	if (idx == 1) {
		cout << -1;
		exit(0);
	}

	temp[idx] = 'A';
	str = string(temp);
	return;
}

int main(void) {
	cin >> K >> N >> A;

	memset(temp, 'A', SIZE);
	str = string(temp);

	Backtracking(1);



	return 0;
}