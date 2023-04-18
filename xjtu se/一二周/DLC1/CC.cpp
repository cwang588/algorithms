#include<bits/stdc++.h>
using namespace std;
const int N=300005;
struct edge
{
	int from,to,nxt;
}e[600005];
int Head[300005],cnt;
int fa[N],son[N],dep[N],sz[N],id[N],v[N],top[N],V[N],sum[3][N<<2],col[3][N<<2],depth[N];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs1(int now,int pre,int depth)
{
	fa[now]=pre;
	dep[now]=depth;
	sz[now]=1;
	int Max=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now,depth+1);
		sz[now]+=sz[to];
		if(sz[to]>Max)
		{
			Max=sz[to];
			son[now]=to;
		}
	}
}
int cntt;
int n,m;
void dfs2(int now,int topf)
{
	id[now]=++cntt;
	v[cntt]=V[now];
	top[now]=topf;
	if(son[now])dfs2(son[now],topf);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==fa[now]||to==son[now])continue;
		dfs2(to,to);
	}
}
int f[500005][25],lg[500005];
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
	dfs1(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int o=lca(x,y),len=depth[x]+depth[y]-depth[o];
	} 
	return 0;
}
