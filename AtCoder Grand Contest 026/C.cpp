#include<bits/stdc++.h>
using namespace std;
int n;
char s[105],t[105];
bool usd[105];
long long ans;
void dfs(int now,int num)
{
	if(now==n)
	{
		int tot=0;
		bool ky=true;
		for(int i=n;i>=1;--i)
		{
			if(!usd[i])
			{
				++tot;
				if(s[i]!=t[tot])
				{
					ky=false;
					break;
				}
			}
		}
		if(ky)ans+=2;
		return;
	}
	int re=now-num;
	if(num<n/2)
	{
		usd[now+1]=true;
		t[num+1]=s[now+1];
		dfs(now+1,num+1);
		usd[now+1]=false;
	}
	if(now-num<n/2)dfs(now+1,num);
}
int main()
{
	scanf("%d",&n);
	n*=2;
	for(int i=1;i<=n;++i)cin>>s[i];
	dfs(0,0);
	printf("%lld\n",ans/2);
	return 0;
}
