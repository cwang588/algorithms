#include<bits/stdc++.h>
using namespace std;
bool usd[10005];
void work(int n)
{
	memset(usd,0,sizeof(usd));
	usd[n+1]=true;
	int now=0;
	for(int i=1;i<n;++i)
	{
		while(usd[++now])
		{
			if(now==n+1)now=1;
			if(!usd[now])break;
		}
		while(usd[++now])
		{
			if(now==n+1)now=1;
			if(!usd[now])break;
		}
		usd[now]=true;
	}
	for(int i=1;i<=n;++i)if(!usd[i])printf("%d  %d\n",n,i);
}
int main()
{
	for(int i=1;i<=100;++i)
		work(i);
	return 0;
}
