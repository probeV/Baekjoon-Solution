#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4000001
bool decimal[SIZE]={false};
int arr[300000]={0};
int decimal_num=0;

void Erasto(){
	for (int i=2;i<=SIZE;i++){
		if (decimal[i]==false){
			arr[decimal_num++]=i;
			for (int j=2;j*i<=SIZE;j++){
				decimal[i*j]=true;
			}
		}
	}
}

int main(void){
	int N;
	int result=0;
	scanf("%d", &N);
	
	Erasto();
	
	int i=0;
	while(arr[i]!=0 && arr[i]<=N){
		int j=i;
		int temp=0;
		while(arr[j]!=0 && temp<=N){
			temp+=arr[j];
			if (temp==N){
				result++;
				break;	
			}	
			j++;
		}
		i++;
	}
	
 	printf("%d", result);
	return 0;
}