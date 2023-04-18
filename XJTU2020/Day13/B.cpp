#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[2][200005];
int cnt1,cnt2,Head[2][100005],rd[2][100005];
long long dp[2][100005];
void add(int x,int y)
{
	++cnt1;
	e[0][cnt1].from=x;
	e[0][cnt1].to=y;
	e[0][cnt1].nxt=Head[0][x];
	Head[0][x]=cnt1;
	++cnt2;
	e[1][cnt2].from=y;
	e[1][cnt2].to=x;
	e[1][cnt2].nxt=Head[1][y];
	Head[1][y]=cnt2;
	++rd[0][y];
	++rd[1][x];
}
int num[100005],root[100005],sum,ans[100005];
bool cut[100005],usd1[100005],usd2[100005];
void dfs1(int now,int pre)
{
	usd1[now]=true;
	for(int i=Head[0][now];i;i=e[0][i].nxt)
	{
		int to=e[0][i].to;
		if(usd1[to])continue;
		num[to]=num[now];
		dfs1(to,now);
	}
	for(int i=Head[1][now];i;i=e[1][i].nxt)
	{
		int to=e[1][i].to;
		if(usd1[to])continue;
		num[to]=num[now];
		dfs1(to,now);
	}
}
queue<int>q1,q2;
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<=n;++i)
		{
			if(!rd[0][i])q1.push(i),dp[0][i]=1;
			if(!rd[1][i])q2.push(i),dp[1][i]=1;
		}
		while(!q1.empty())
		{
			int now=q1.front();
			q1.pop();
			for(int i=Head[0][now];i;i=e[0][i].nxt)
			{
				int to=e[0][i].to;
				dp[0][to]+=dp[0][now];
				--rd[0][to];
				if(!rd[0][to])q1.push(to);
			}
		}
		while(!q2.empty())
		{
			int now=q2.front();
			q2.pop();
			for(int i=Head[1][now];i;i=e[1][i].nxt)
			{
				int to=e[1][i].to;
				dp[1][to]+=dp[1][now];
				--rd[1][to];
				if(!rd[1][to])q2.push(to);
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(!usd1[i])
			{
				num[i]=++sum;
				root[sum]=i;
				dfs1(i,0);
			}
		}
		for(int i=1;i<=n;++i)if(dp[0][i]*dp[1][i]==dp[0][root[num[i]]])cut[i]=true;
		for(int i=1;i<=cnt1;++i)++rd[1][e[1][i].to];
		for(int i=1;i<=n;++i)if(!usd)
		for(int i=1;i<=n;++i)if(!cut[i])++ans[i];
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(root[num[x]]!=root[num[y]])printf("%d\n",ans[x]+ans[y]);
			else printf("%d\n",max(ans[x],ans[y]));
		}
	}
	return 0;
}
