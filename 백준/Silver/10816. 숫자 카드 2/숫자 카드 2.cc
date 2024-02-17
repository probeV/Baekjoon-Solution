#include <bits/stdc++.h>
using namespace std;

int N = 0;
int M = 0;
int num = 0;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		cout << upper_bound(vec.begin(), vec.end(), num) - lower_bound(vec.begin(), vec.end(), num) << " ";
	}
}