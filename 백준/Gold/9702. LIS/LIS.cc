#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 501

int T, N, L, res;
vector<int> seq, LIS;
vector<int>::iterator it;

bool isSeq[MAXSIZE];

int main(void){
    cin >> T;

    for(int k=1;k<=T;k++){
        cin >> N;

        seq.clear();
        LIS.clear();
        L=0; res=0;

        //순열 입력 받기
        int ipt;
        for(int i=1;i<=N;i++){
            cin >> ipt;
            seq.push_back(ipt);
        }

        for(int start=0;start<N;start++){
            LIS.clear();
            L=0;
            for (int i = start; i < N; i++)
            {
                // LIS가 비어있거나 LIS의 마지막 보다 클 때 -> push back
                if (LIS.empty() || LIS.back() < seq[i])
                {
                    LIS.push_back(seq[i]);
                    L++;
                }
                else
                {
                    it = upper_bound(LIS.begin(), LIS.end(), seq[i]);
                    *it = seq[i];

                    int newL = it - LIS.begin();

                    if (newL > L)
                        L = newL;
                }

                res+=L;

                //cout << L << " ";
            }
            //cout << "\n";
        }

        cout << "Case #" << k << ": " << res << "\n";
    }
}