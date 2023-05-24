#include <bits/stdc++.h>

#define SIZE 100001

using namespace std;

int n;

int arr[SIZE];

int c; 

void solution(){
	stack<int> s; c=0;
	bool visited[SIZE];
	memset(visited, false, SIZE);
	
	s.push(-1);
	
	for(int i=1;i<=n;i++){
		if(visited[i]) continue;
			
		int x=i;
		while(!visited[x]){
			s.push(x);
			visited[x]=true;
			x=arr[x];
		}
		
		//사이클 존재
		int temp=1;
		while(s.top()!=x && s.top()!=-1){
			temp++;
			s.pop();
		}
		
		if(s.top()!=-1){
			c+=temp;
			s.pop();
			while(s.top()!=-1)	s.pop();
		}
	}
}

int main(void){
	int T;
	cin >> T;
	for(int k=1;k<=T;k++){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> arr[i];
		}
		
		solution();
		
		cout << n-c <<"\n";
	}
	return 0;	
}