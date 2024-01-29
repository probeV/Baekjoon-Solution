#include <iostream>
using namespace std;

#define MAX 6

int N;
long long B;
int matrix[MAX][MAX];
int res[MAX][MAX];

// 행렬 곱셈 함수
void MultMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX])
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            result[i][j] = 0;
            for (int k = 1; k <= N; k++)
            {
                result[i][j] += (a[i][k] * b[k][j])%1000;
                result[i][j]=result[i][j]%1000;
            }
        }
    }
}

// 행렬 거듭제곱 함수
void DivideConquer(int A[MAX][MAX], long long num, int result[MAX][MAX])
{
    if (num == 1)
    {
        // 결과에 A 복사
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                result[i][j] = A[i][j]%1000;
            }
        }
        return;
    }

    int temp[MAX][MAX];
    DivideConquer(A, num / 2, temp);

    if (num % 2 == 0)
    {
        MultMatrix(temp, temp, result);
    }
    else
    {
        int temp2[MAX][MAX];
        MultMatrix(temp, temp, temp2);
        MultMatrix(temp2, A, result);
    }
}

int main()
{
    cin >> N >> B;

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            cin >> matrix[y][x];
        }
    }

    DivideConquer(matrix, B, res);

    // 결과 출력 또는 활용
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
