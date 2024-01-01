#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int N, M;
int res = INT_MAX, cur_res;
char ipt[MAX][MAX];

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> &ipt[i][1];

    for (int str_x = 1; str_x <= M - 7; str_x++)
    {
        for (int str_y = 1; str_y <= N - 7; str_y++)
        {
            // start

            for (int i = 1; i <= 2; i++)
            {
                char cur_color;
                char cur_ipt[MAX][MAX];
                cur_res = 0;

                if(i==1)
                    cur_ipt[str_y][str_x]='B';
                else    
                    cur_ipt[str_y][str_x]='W';

                for (int y = str_y; y < str_y + 8; y++)
                {
                    for (int x = str_x; x < str_x + 8; x++)
                    {
                        // 맨 왼쪽의 맨 위쪽 시작일 때
                        if (x == str_x && y == str_y)
                        {
                            if (cur_ipt[y][x] != ipt[y][x])
                                cur_res++;
                        }
                        // 맨 왼쪽 일 때
                        else if (x == str_x)
                        {
                            if (cur_ipt[y - 1][x] == 'B')
                                cur_ipt[y][x] = 'W';
                            else if (cur_ipt[y - 1][x] == 'W')
                                cur_ipt[y][x] = 'B';

                            if (cur_ipt[y][x] != ipt[y][x])
                                cur_res++;
                        }
                        // 새로 쓴 색과 같을 때
                        else if (ipt[y][x] == cur_ipt[y][x - 1])
                        {
                            cur_res++;
                            if (ipt[y][x] == 'B')
                                cur_ipt[y][x] = 'W';
                            else if (ipt[y][x] == 'W')
                                cur_ipt[y][x] = 'B';
                        }
                        // 새로 쓴 색과 다를 때
                        else
                        {
                            cur_ipt[y][x] = ipt[y][x];
                        }
                    }
                }

                if (res > cur_res)
                {
                    res = cur_res;
                }
                // end
            }
        }
    }

    cout << res;
}