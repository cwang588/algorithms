#include<bits/stdc++.h>
using namespace std;
long long rating[1000005],a[1000005],sum[1000005],cnt[1000005];
struct edge
{
	int from,to,nxt;
}e[2000005];
int n,k,cntt,Head[1000005],depth[1000005],son[1000005],sz[1000005];
bool usd[1000005];
void add(int x,int y)
{
	++cntt;
	e[cntt].from=x;
	e[cntt].to=y;
	e[cntt].nxt=Head[x];
	Head[x]=cntt;
}
void dfs1(int now,int pre)
{
	depth[now]=depth[pre]+1;
	sz[now]=1;
	int Max=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		sz[now]+=sz[to];
		if(sz[to]>Max)
		{
			Max=sz[to];
			son[now]=to;
		}
	}
}
void query(int now,int pre,int lca)
{
	int d=k+2*depth[lca]-depth[now];
	if(d>0)
	{
		rating[lca]+=sum[d];
		rating[lca]+=cnt[d]*a[now];
	}
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		query(to,now,lca);
	}
}
void update(int now,int pre,int type)
{
	sum[depth[now]]+=a[now]*type;
	cnt[depth[now]]+=type;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		update(to,now,type);
	}
}
void dfs2(int now,int pre,bool keep)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||to==son[now])continue;
		dfs2(to,now,false);
	}
	if(son[now])dfs2(son[now],now,true),usd[son[now]]=true;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		query(to,now,now);
		update(to,now,1); 
	}
	sum[depth[now]]+=a[now];
	++cnt[depth[now]];
	if(son[now])usd[son[now]]=false;
	if(!keep)
	{
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre||usd[to])continue;
			update(to,now,-1);
		}
		sum[depth[now]]-=a[now];
		--cnt[depth[now]];
	}
}
int main()
{
	scanf("%d%d",&n,&k);	
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dfs2(1,0,true);
	for(int i=1;i<=n;++i)printf("%lld ",rating[i]);
	return 0;
} 
