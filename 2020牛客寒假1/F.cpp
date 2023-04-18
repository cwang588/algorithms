#include<bits/stdc++.h>
using namespace std;
char col[100005];
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
long long dp[100005][2];
long long ans;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre)
{
	if(col[now]=='W')dp[now][0]=1;
	else dp[now][1]=1;
	long long tot0=0,tot1=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		if(col[now]=='W')
		{
			dp[now][0]+=dp[to][0];
			dp[now][1]+=dp[to][1];
		}
		else dp[now][1]+=dp[to][0];
		tot0+=dp[to][0];
		tot1+=dp[to][1];
	}
	ans+=2*dp[now][1];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		if(col[now]=='B')
			ans+=dp[to][0]*(tot0-dp[to][0]);
		else
		{
			ans+=dp[to][0]*(tot1-dp[to][1]);
			ans+=dp[to][1]*(tot0-dp[to][0]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	long long totb=0;
	for(int i=1;i<=n;++i)cin>>col[i],totb+=(col[i]=='W'?0:1);
	for(int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	printf("%lld\n",ans/2-totb);
	return 0;
}
