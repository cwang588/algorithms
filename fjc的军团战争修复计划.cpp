#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int num,col[100005],bh[100005],Head[100005],sz[100005],cnt,a[100005];
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
	sz[now]=1;
	a[++num]=col[now];
	bh[now]=num;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		sz[now]+=sz[to];
	}
}
int n,m; 
struct query
{
	int l,r,id,ans;
}q[100005];
bool cmp1(query x,query y)
{
	return x.r<y.r;
}
int sum[100005];
int lowbit(int x)
{
	return x&(-x);
}
bool cmp2(query x,query y)
{
	return x.id<y.id;
}
void addd(int x,int y)
{
	while(x<=n)
	{
		sum[x]+=y;
		x+=lowbit(x);
	}
}
int qq(int x)
{
	if(!x)return 0;
	int re=0;
	while(x)
	{
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
int fjc[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&col[i]);
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
		int x;
		scanf("%d",&x);
		q[i].l=bh[x];
		q[i].r=bh[x]+sz[x]-1;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp1);
	int p=1;
	for(int i=1;i<=n;++i)
	{
		if(fjc[a[i]])addd(fjc[a[i]],-1);
		addd(i,1);
		fjc[a[i]]=i;
		while(i==q[p].r)
		{
			q[p].ans=qq(i)-qq(q[p].l-1);
			++p;
		}
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;++i)printf("%d\n",q[i].ans);
	return 0;
}
