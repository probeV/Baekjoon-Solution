#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int pres[51][51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int size=friends.size();
    
    map<string, int> f;
    vector<int> p(size, 0);
    vector<int> res(size, 0);
    
    for(int i=0;i<size;i++){
        f.insert({friends[i], i});
    }
    
    //선물 주고 받고 체크
    for(int i=0;i<gifts.size();i++){
        int give, get;
        
        //문자열 파싱
        stringstream s(gifts[i]);
        string t1, t2;
        s >> t1 >> t2;
        
        give = f[t1];
        get =  f[t2];
        
        //체크
        pres[give][get]++;
    }
    
    //선물지수 체크
    for(int i=0;i<size;i++){
        int give=0;
        int get=0;
        
        for(int j=0;j<size;j++){
            give += pres[i][j];
            get += pres[j][i];
        }
        
        p[i] = give - get;
    }
    
    //선물 받기 
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            //자기 자신 일때 패스
            if(i==j) continue;
            
            //주고 받은 기록이 있을 때
            if(pres[i][j]!=0 ||  pres[j][i] != 0){
                //내가 준게 더 크면
                if(pres[i][j] > pres[j][i]){
                    res[i]++;
                }
                //주고 받은 수가 같을 때
                else if(pres[i][j] == pres[j][i]){
                    //내 선물지수가 더 크면
                    if(p[i] > p[j]){
                        res[i]++;
                    }
                }
            }
            //주고받은 기록이 하나도 없을 때
            else{
                //내 선물지수가 더 크면
                if(p[i] > p[j]){
                    res[i]++;
                }
            } 
        }
    }
    
    //최댓값 찾기
    int t=-1;
    for(int i=0;i<size;i++){
        if(res[i] > t){
            t=res[i];
        }
    }
    
    answer=t;
    
    return answer;
}