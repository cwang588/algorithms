#include<bits/stdc++.h>
using namespace std;
int rd[100005];
int dp[100005];
queue<int>q;
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)dp[i]=1;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		++rd[y];
	}
	for(int i=1;i<=n;++i)
		if(!rd[i])
			q.push(i);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			dp[to]=max(dp[to],dp[now]+1);
			--rd[to];
			if(!rd[to])q.push(to);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
