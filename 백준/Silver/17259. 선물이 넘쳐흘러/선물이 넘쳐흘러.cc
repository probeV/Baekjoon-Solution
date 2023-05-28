#include <bits/stdc++.h>

#define SIZE 101

using namespace std;

//공장 크기, 직원 수, 선물 개수 
int B, N, M;

//직원 위치 
int Arr[SIZE][SIZE];

//직원 걸리는 시간 정보 
int employee[SIZE];

//직원 상태
int isPos[300];
 
//포장된 선물의 총 개수  
int result=0;

//총 시간
int total=0; 
 
void check_present(int s[]){
	for(int i=3*B-2;i>=1;i--){
		int x,y;
		//선물이 있을 때  
		if(s[i]==1){
			//list 인덱스를 직원  좌표로 변경  
			if(i<B){ //위 벨트 
				x=i-1; y=1;
			}
			else if(i>B && i<2*B-1){ //오른쪽 밸트
				x=B-2; y=i-B;
			}
			else if(i>2*B-1){ //아래 벨트 
				x=3*B-2-i; y=B-2;
			} 
			else continue;
			
			int curr=Arr[y][x];
			//직원이 있을 때 
			if(curr!=0 && (isPos[curr]==0 || total-isPos[curr]>=employee[curr])){
				result++;
				isPos[curr]=total;
				s[i]=0;
			}
		}
	}
}

int end(int s[]){
	for(int i=1;i<=3*B-2;i++)
		if(s[i]==1) return 1;
	return 0;
}

void move(int s[]){
	for(int i=3*B-2;i>=0;i--)
		s[i+1]=s[i];
}

int main(void){
	//input
	cin >> B >> N >> M;
	//직원 정보 
	for(int i=1;i<=N;i++){
		int x, y, s;
		cin >> y >> x >> s;
		employee[i]=s;
		Arr[y][x]=i;
	}
	
	//선물 
	int s[3*B];
	memset(s, 0, 3*B*sizeof(int));
	do{
		total++;
		move(s);
		if(total<=M)
			s[1]=1;
		check_present(s);
	}while(total<M || end(s));
	
	cout << result;
}