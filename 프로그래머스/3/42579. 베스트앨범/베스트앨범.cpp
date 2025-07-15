#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

// 장르별 가장 많이 재생된 노래를 두 개 씩 

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 장르별로 속한 노래 재생횟수 -> 장르 선택
    map<string, int> genreTotal;
    for(int i = 0; i < genres.size(); i++){
        genreTotal[genres[i]] += plays[i];
    }

    // 장르 내에서 많이 재생된 노래
    map<string, vector<pair<int, int>>> genreSongs;
    for(int i = 0; i < plays.size(); i++){
        genreSongs[genres[i]].push_back({plays[i], i});
    }
    
    // 장르별 정렬 
    vector<pair<int, string> > sortedGenreTotal;
    for(auto [key,value] : genreTotal){
        sortedGenreTotal.push_back({value, key});
    }
    sort(sortedGenreTotal.begin(), sortedGenreTotal.end(), greater<pair<int, string>>());
    
    // 장르 내에서 재생 수 정렬
    for(auto &[key, value] : genreSongs){
        sort(value.begin(), value.end(),[](const pair<int, int> &a, const pair<int, int> &b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
    }
    
    for(int i=0;i<sortedGenreTotal.size();i++){
        string g = sortedGenreTotal[i].second;
        int n = sortedGenreTotal[i].first;
        
        vector<pair<int, int> > curr = genreSongs[g];
        for(int j=0;j<curr.size();j++){
            if(j>=2) break;
            answer.push_back(curr[j].second);
        }   
    }
    
    
    // 디버깅: 장르별 총 재생횟수 출력
    cout << "=== 장르별 총 재생횟수 ===" << endl;
    for(auto [key, value] : genreTotal){
        cout << key << ": " << value << "\n";
    }
    
    for(int i=0;i<sortedGenreTotal.size();i++){
        cout << sortedGenreTotal[i].first << ", " << sortedGenreTotal[i].second << " // ";
    }

    // 디버깅: 장르별 노래들 출력
    cout << "\n=== 장르별 노래들 ===" << endl;
    for(auto [key,value] : genreSongs){
        cout << key << ": ";
        for(auto [num, idx] : value){
            cout << "(" << num << ", " << idx << ")" << " ";
        }
        cout << "\n";
    }
    
    
//     for(auto i = g.begin(); i < g.end(); i++){
        
//     }
    
    
    return answer;
}