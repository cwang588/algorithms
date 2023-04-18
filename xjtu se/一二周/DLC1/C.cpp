#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[600005];
int Head[300050],cnt;
int n,m;
long long sum[5][300005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int depth[500005],f[500005][25],lg[500005];
void dfs(int now,int pre)
{
	f[now][0]=pre;
	for(int i=1;(1<<i)<=depth[now];++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		depth[e[i].to]=depth[now]+1;
		dfs(e[i].to,now);
	}
}
void init()
{
	for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])swap(x,y);
	while(depth[x]>depth[y])
		x=f[x][lg[depth[x]-depth[y]]-1];
	if(x==y)return x;
	for(int k=lg[depth[x]]-1;k>=0;--k)
	{
		if(f[x][k]!=f[y][k])
		{
			x=f[x][k];
			y=f[y][k];
		}
	}
	return f[x][0];
}
void dfss(int now,int pre,int jie)
{
	sum[jie][now]=sum[jie-1][now];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfss(to,now,jie); 
		sum[jie][now]+=sum[jie][to];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int o=lca(x,y),p=f[o][0];
		sum[0][x]-=2;
		sum[0][y]-=2;
		sum[0][o]+=2;
		sum[0][p]+=2;
	}
	for(int i=1;i<=3;++i)
		dfss(1,0,i);
	for(int i=1;i<=n;++i)printf("%lld\n",sum[3][i]);
	return 0;
} 
