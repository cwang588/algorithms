#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt,v;
}e[400005];
int Head[200005],cnt;
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long dp[200005][2];
long long ans;
void dfs1(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		if(e[i].v)dp[now][1]+=dp[to][1]+dp[to][0];
		else dp[now][0]+=dp[to][0];
	}
}
void dfs2(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		if(e[i].v)dp[to][1]+=dp[now][1]-dp[to][1]+dp[now][0]-dp[to][0];
		else dp[to][0]+=dp[now][0]-dp[to][0];
		dfs2(to,now);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		++dp[x][z];
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)ans+=dp[i][0]+dp[i][1];
	printf("%lld\n",ans);
	return 0;
}
