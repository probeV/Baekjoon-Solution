#include <bits/stdc++.h>

using namespace std;

#define MAX 51

int num;
int res[MAX];

vector<vector<int>> path(MAX);
queue<pair<int, int>> q;

int main(void) {
    cin >> num;

    int tmp1, tmp2;

    //입력 받기
    while (1) {
        cin >> tmp1 >> tmp2;

        if (tmp1 == -1 && tmp2 == -1) {
            break;
        }
        else {
            path[tmp1].push_back(tmp2);
            path[tmp2].push_back(tmp1);
        }
    }

    //BFS
    for (int i = 1; i <= num; i++) {
        bool isVisited[MAX];
        memset(isVisited, 0, sizeof(isVisited));

        q.push({i, 0});
        isVisited[i]=true;

        while (!q.empty()) {
            int x = q.front().first;
            int level = q.front().second;
            q.pop();
            
            for (int j = 0; j < path[x].size(); j++)
            {
                //아직 방문하지 않았다면
                if (!isVisited[path[x][j]]) {
                    isVisited[path[x][j]] = true;
                    q.push({path[x][j], level+1});
                    res[i]=level+1;
                }
            }
        }
    }

    //최소값 찾기
    int min=INT_MAX;
    for(int i=1;i<=num;i++){
        if(res[i]<min){
            min=res[i];
        }
    }

    //회장 수 및 후보들 찾기
    int count=0;
    for(int i=1;i<=num;i++){
        if(res[i]==min){
            count++;
        }
    }

    cout << min << " " << count <<"\n";

    for(int i=1;i<=num;i++){
        if(res[i]==min){
            cout << i << " ";
        }
    }
}