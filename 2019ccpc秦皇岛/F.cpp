#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
struct edge
{
	int from,to,nxt;
}e[1000005];
int Head[500005],cnt,dp[500005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[500005];
int sum[500005],num;
void dfs(int now,int pre,int dep)
{
	usd[now]=true;
	dp[now]=dep;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		if(usd[e[i].to])sum[++num]=dep+1-dp[e[i].to];
		else dfs(e[i].to,now,dep+1);
	}
}
long long mi[500005];
void init()
{
	mi[0]=1;
	for(int i=1;i<=500000;++i)mi[i]=mi[i-1]*2%mod;
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(Head,0,sizeof(Head));
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		memset(usd,false,sizeof(usd));
		num=cnt=0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0,1);
		long long ans=1;
		int re=m;
		for(int i=1;i<=num;++i)
		{
			if(sum[i]>0)
			{
				ans=(ans*(mi[sum[i]]-1))%mod;
				re-=sum[i];
			}
		}
		ans=(ans*mi[re])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
