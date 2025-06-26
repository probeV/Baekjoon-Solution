#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<int> st;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){ // 괄호 닫혔을 때 
            if(!st.empty() && st.top()=='('){ // 올바르게 닫힌 경우
                st.pop();
            }
            else { // 올바르지 않은 괄호 
                answer = false;
                break;
            }
        }
    }
    
    // 남은 괄호 남아 있으면 
    if(!st.empty()){
        answer = false;
    }

    return answer;
}