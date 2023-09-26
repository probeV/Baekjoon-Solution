#include <bits/stdc++.h>

using namespace std;

#define SIZE 200010

string input;
int beforeNum = 0;
long result = 0;

int main(void) {
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			beforeNum++;
		}
		else if (input[i] == ')' && input[i-1]=='(') {
			beforeNum--;
			result += beforeNum;
		}
		else if (input[i] == ')' && input[i - 1] == ')') {
			beforeNum--;
		}
	}

	cout << result;

}