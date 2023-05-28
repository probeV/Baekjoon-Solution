#include <bits/stdc++.h>

using namespace std;

#define SIZE 101

int N, M;	

int numArr[3][4]; 

int result=0;

void DFS(int pre_x ,int c ,int total){
	if(c==N){
		if(total >= M){
			result++;
		}
		return;
	}
			
	for(int i=1;i<=2;i++){
		for(int j=1;j<=3;j++){
			if(pre_x==j)
				DFS(j,c+1,total+numArr[i][j]/2);
			else
				DFS(j,c+1,total+numArr[i][j]);
		}
	}
}

int main(void){
	cin >> N >> M;
	
	for(int i=1;i<=3;i++)
		cin >> numArr[1][i];
	for(int i=1;i<=3;i++)
		cin >> numArr[2][i];
		
	DFS(0,0,0); 
	
	cout << result;
	
	return 0;
}
