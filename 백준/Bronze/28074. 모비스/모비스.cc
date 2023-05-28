#include <bits/stdc++.h>

using namespace std;

#define SIZE 101

bool visited[5];

int main(void){
    char inputArr[SIZE];
    
    cin >> inputArr;
    
    int c=0;
    for(int i=0;i<strlen(inputArr);i++){
    	char a=inputArr[i];
    	if(a=='M' && !visited[0]){
    		visited[0]=true;
    		c++;
		}
		else if(a=='O' && !visited[1]){
    		visited[1]=true;
    		c++;
		}
		else if(a=='B' && !visited[2]){
    		visited[2]=true;
    		c++;
		}
		else if(a=='I' && !visited[3]){
    		visited[3]=true;
    		c++;
		}
		else if(a=='S' && !visited[4]){
    		visited[4]=true;
    		c++;
		}
	}
	
	if(c==5)
		cout << "YES";
	else
		cout <<"NO";
		
	return 0;
}
