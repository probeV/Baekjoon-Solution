#include<stdio.h>
int main(){
	int h,m;
	scanf("%d",&h);
	scanf("%d",&m);
	m=m-45;
	if(m<0){
		if(h==0){
			h=23;	
		}
		else{
			h=h-1;	
		}
		m=60+m;
		printf("%d %d\n",h,m);
		return 0;
	}
	printf("%d %d\n",h,m);
	return 0;
}