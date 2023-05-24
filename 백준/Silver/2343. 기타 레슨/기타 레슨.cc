#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
int len[100001];
int l,r,m;
int sum=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++)
	{
		cin>>len[i];
		sum+=len[i];
	}
	l=*max_element(len+1,len+1+N);
	r=sum;
	while(l<=r)
	{
		m=(l+r)/2;
		int tmp=0,cnt=0;
		for(int i=1;i<=N;i++)
		{
			if(tmp+len[i]<=m)
				tmp+=len[i];	
			else
			{
				cnt++;
				tmp=len[i];
			}
		}	
		cnt++;
		if(cnt>M)
			l=m+1;
		else
			r=m-1; 
	}
	cout<<l;
	return 0;
}