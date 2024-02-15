#include <iostream>
#include <vector>
#include<algorithm>
#define MAX 2000
/*
백준 4198 열차정렬
*/
using namespace std;
int main() {
	int t[MAX] = { -1, };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	int lis[MAX] = { 0, };
	int lds[MAX] = { 0, };

	vector<int> lisV;
	vector<int> ldsV;
	for (int idx = 0; idx < n; idx++) {
		lisV.push_back(t[idx]);
		ldsV.push_back(t[idx]);
		for (int i = idx + 1; i < n; i++) {
			if (t[i] > lisV.back())
				lisV.push_back(t[i]);
			else if(t[i] > lisV.front()) {
				auto it = upper_bound(lisV.begin()+1, lisV.end(), t[i]);
				*it= t[i];
			}
			
			if (t[i] < ldsV.back())
				ldsV.push_back(t[i]);
			else if (t[i] < ldsV.front()) {
				auto it = upper_bound(ldsV.begin()+1, ldsV.end(), t[i],greater<int>());
				*it = t[i];
			}
		}
		lis[idx] = lisV.size();
		lisV.clear();
		lds[idx] = ldsV.size();
		ldsV.clear();
	}
	int m = 0;
	if (n != 0)
		m = lis[0] + lds[0] - 1;

	for (int i = 1; i < n; i++) {
		m = max(m, lis[i] + lds[i] - 1);
	}
	printf("%d", m);
	return 0;
}