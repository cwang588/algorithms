#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=100005;
int n,m,root,p;
struct edge
{
	int from,to,nxt;
}e[N*2];
int cnt,Head[N],fa[N],son[N],dep[N],sz[N],id[N],v[N],top[N],V[N],sum[N<<2],col[N<<2];
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
void push_col(int l,int r,int rt)
{
	int m=(l+r)>>1;
	if(col[rt])
	{
		sum[rt<<1]=(sum[rt<<1]+col[rt]*(m-l+1)%p)%p;
		sum[rt<<1|1]=(sum[rt<<1|1]+col[rt]*(r-m)%p)%p;
		col[rt<<1]=(col[rt<<1]+col[rt])%p;
		col[rt<<1|1]=(col[rt<<1|1]+col[rt])%p;
		col[rt]=0;
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=v[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%p;
	return;
}
void modify(int l,int r,int rt,int nowl,int nowr,int k)
{
	if(l>=nowl&&r<=nowr)
	{
		col[rt]=(col[rt]+k)%p;
		sum[rt]=(sum[rt]+((r-l+1)%p*k)%p)%p;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)modify(lson,nowl,nowr,k);
	if(m<nowr)modify(rson,nowl,nowr,k);
	sum[rt]=(sum[rt<<1]+sum[rt<<1|1])%p;
	return;
}
int query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt];
	push_col(l,r,rt);
	int m=(l+r)>>1;
	int re=0;
	if(m>=nowl)re=(re+query(lson,nowl,nowr))%p;
	if(m<nowr)re=(re+query(rson,nowl,nowr))%p;
	return re;
}
void modifyrange(int x,int y,int k)
{
	k%=p;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		modify(1,n,1,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	modify(1,n,1,id[x],id[y],k);
}
int queryrange(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=(ans+query(1,n,1,id[top[x]],id[x]))%p;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=(ans+query(1,n,1,id[x],id[y]))%p;
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&root,&p);
	for(int i=1;i<=n;++i)scanf("%d",&V[i]);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs1(root,0,1);
	dfs2(root,root);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			modifyrange(x,y,k);
		}
		else if(t==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",queryrange(x,y));
		}
		else if(t==3)
		{
			int x,k;
			scanf("%d%d",&x,&k);
			modify(1,n,1,id[x],id[x]+sz[x]-1,k);
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(1,n,1,id[x],id[x]+sz[x]-1));
		}
	}
	return 0;
}
