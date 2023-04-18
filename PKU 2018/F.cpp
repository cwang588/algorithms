#include<cstdio>
#define mod 1000000007
using namespace std;
int a[200005];
bool usd[200005];
int lian[200005];
int num,n,sum;
int xh[200005];
bool l[200005];
void dfs(int x,int now,int tot)
{
	if(x>n)
	{
		lian[++sum]=tot-1;
		return;
	}
	if(usd[x])
	{
		return;
	}
	xh[x]=now;
	usd[x]=true;
	dfs(a[x],now,tot+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long ans=1;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			if(!usd[i])
				dfs(i,++num,1);
		int re=n;
		for(int i=1;i<=sum;++i)
		{
			ans*=c(re,lian[i])*mi(lian[i]+1,lian[i]-1);
			re-=lian[i];
		}
	}
	return 0;
}
