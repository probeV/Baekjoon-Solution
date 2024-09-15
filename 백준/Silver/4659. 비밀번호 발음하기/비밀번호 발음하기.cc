#include<bits/stdc++.h>

using namespace std;

vector<string> arr;

void out(string temp, bool t){
    
    if(t)
        cout << "<" << temp << "> is acceptable.\n";
    else
        cout << "<" << temp << "> is not acceptable.\n";
}

int main(){
    string temp;

    cin >> temp;

    while (temp != "end")
    {
        bool isUsed = false;
        int cntM = 0, cntG=0;

        for(int i=0;i<temp.size();i++){
            
            if(temp[i]=='a' || temp[i]=='e' || temp[i]=='i' ||temp[i]=='o' || temp[i]=='u'){
                isUsed = true;
                cntM++;
                cntG=0;
            }
            else{
                cntG++;
                cntM=0;
            }

            if(cntG >= 3 || cntM >=3){
                out(temp,false);
                break;
            }

            if(i>=1 && temp[i]==temp[i-1] && !(temp[i] == 'e' || temp[i] == 'o')){
                out(temp, false);
                break;
            }

            if(i==temp.size()-1 && isUsed){
                out(temp, true);
            }
            else if(i==temp.size()-1 && !isUsed)
                out(temp, false);
        }

        cin >> temp;
    }
}