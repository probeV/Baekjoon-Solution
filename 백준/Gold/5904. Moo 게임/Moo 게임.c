#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h> 

#define SIZE 2500

int target=0;
int count=0;

void c(int n){
	for(int i=1;i<=3;i++){
		if(++count==target){
			if(i==1){
				printf("m");
				exit(0);
			}
			else{
				printf("o");
				exit(0);	
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(++count==target){
			printf("o");
			exit(0);
		}
	}
}

void d(int n){
	if(n==0){
		for(int i=1;i<=3;i++){
			if(++count==target){
				if(i==1){
					printf("m");
					exit(0);
				}
				else{
					printf("o");
					exit(0);	
				}
			}
		}
		return;
	}
	
	d(n-1);
	c(n);
	d(n-1);
}

int main(void){	
	scanf("%d", &target);
	
	int t=3, c=0;
	while(target>t){
		c++;
		t=2*t+3+c;
	}
	
	d(c);

	return 0;
}