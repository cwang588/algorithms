#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
vector<int>v;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct edge
{
	int from,to,nxt;
}e[2*N];
struct node
{
	int l,r,sum;
}T[N*40];
int n,Head[N],root[N],cntt,cnt,depth[500005],f[500005][25],lg[N+50],fa[N];
void init()
{
	for(int i=1;i<=N;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])swap(x,y);
	while(depth[x]>depth[y])x=f[x][lg[depth[x]-depth[y]]-1];
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
void add(int x,int y)
{
	++cntt;
	e[cntt].from=x;
	e[cntt].to=y;
	e[cntt].nxt=Head[x];
	Head[x]=cntt;
}
int build(int l,int r,int node)
{
	node=++cnt;
	if(l==r)
	{
		T[node].sum=0;
		return node;
	}
	int m=(l+r)>>1;
	T[node].l=build(l,m,T[node].l);
	T[node].r=build(m+1,r,T[node].r);
	T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	return node;
}
int modify(int l,int r,int node,int pos)
{
	T[++cnt]=T[node];
	node=cnt;
	if(l==r)
	{
		++T[node].sum;
		return node;
	}
	int m=(l+r)>>1;
	if(m>=pos)T[node].l=modify(l,m,T[node].l,pos);
	else T[node].r=modify(m+1,r,T[node].r,pos);
	T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	return node;
}
void dfs(int now,int pre)
{
	fa[now]=pre;
	f[now][0]=pre;
	for(int i=1;(1<<i)<=depth[now];++i)f[now][i]=f[f[now][i-1]][i-1];
	root[now]=modify(1,n,root[pre],getid(a[now]));
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		depth[e[i].to]=depth[now]+1;
		dfs(to,now);
	}
}
int query(int l,int r,int nodex,int nodey,int nodelca,int nodelcafa,int k)
{
	if(l==r)return l;
	int m=(l+r)>>1;
	int re=T[T[nodex].l].sum+T[T[nodey].l].sum-T[T[nodelca].l].sum-T[T[nodelcafa].l].sum;
	if(k<=re)return query(l,m,T[nodex].l,T[nodey].l,T[nodelca].l,T[nodelcafa].l,k);
	else return query(m+1,r,T[nodex].r,T[nodey].r,T[nodelca].r,T[nodelcafa].r,k-re);
}
int main()
{
	int m,lastans=0;
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	root[0]=build(1,n,0);
	dfs(1,0);
	for(int i=1;i<=m;++i)
	{
		int U,V,k;
		scanf("%d%d%d",&U,&V,&k);
		U^=lastans;
		int zx=lca(U,V);
		lastans=v[query(1,n,root[U],root[V],root[zx],root[fa[zx]],k)-1];
		printf("%d\n",lastans);
	}
	return 0;
}
