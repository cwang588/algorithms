#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[2][100005];
int cnt,Head[2][100005];
void add(int x,int y)
{
	++cnt;
	e[0][cnt].from=x;
	e[0][cnt].to=y;
	e[0][cnt].nxt=Head[0][x];
	Head[0][x]=cnt;
	e[1][cnt].from=y;
	e[1][cnt].to=x;
	e[1][cnt].nxt=Head[1][y];
	Head[1][y]=cnt;
}
queue<int>q;
int n,m,t;
bool usd[100050],sl[100005];
int col[100005],ans[100005],sum;
bool vis[100005];
bool dfs(int now,int pre)
{
	vis[now]=true;
	for(int i=Head[0][now];i;i=e[0][i].nxt)
	{
		int to=e[0][i].to;
		if(to==t)
		{
			if(!sl[now])return true;
			else continue;
		}
		if(col[to]!=col[now])
		{
			if(col[to])return true;
			else continue;
		}
		if(vis[to])continue;
		if(dfs(to,now))return true;
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	int num=0;
	for(int i=Head[1][t];i;i=e[1][i].nxt)
	{
		int to=e[1][i].to;
		if(to==t)continue;
		col[to]=++num;
		sl[to]=true;
		q.push(to);
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=Head[1][now];i;i=e[1][i].nxt)
		{
			int to=e[1][i].to;
			if(!col[to]&&to!=t)
			{
				col[to]=col[now];
				q.push(to);
			}
		}
	}
	vis[t]=true;
	for(int i=Head[1][t];i;i=e[1][i].nxt)
	{
		int to=e[1][i].to;
		if(to==t)continue;
		usd[to]=dfs(to,t);
		if(!usd[to])ans[++sum]=to;
	}
	sort(ans+1,ans+1+sum);
	printf("%d\n",sum);
	for(int i=1;i<=sum;++i)printf("%d\n",ans[i]);
	return 0;
}
