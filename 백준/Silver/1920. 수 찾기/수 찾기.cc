#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int N, M;
long long ipt_N[MAX], ipt_M[MAX];

int binarySearch(long long target)
{
    int front = 0;
    int end = N-1;

    while (front <= end)
    {
        int mid = (front + end) / 2;

        if (ipt_N[mid] == target)
        {
            return 1;
        }
        else if (target < ipt_N[mid])
        {
            end = mid - 1;
        }
        else if (target > ipt_N[mid])
        {
            front = mid + 1;
        }
    }
    return 0;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> ipt_N[i];
    }
    sort(ipt_N, ipt_N + N);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> ipt_M[i];
    }

    for(int i=0;i<M;i++){
        cout << binarySearch(ipt_M[i]) << "\n";
    }
}