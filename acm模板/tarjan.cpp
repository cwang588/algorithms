//tarjan«Ûlca 
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,next;
}e[1000005];
struct query
{
	int from,to,next;
}q[1000005];
int head[500005],qhead[500005],fa[500005],ans[500005];
int father(int x)
{
	if(fa[x]==x)
		return x;
	fa[x]=father(fa[x]);
	return fa[x];
}
void Merge(int r1,int r2)
{
	fa[r2]=r1;
}
int cnt,qcnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
void qadd(int x,int y)
{
	++qcnt;
	q[qcnt].from=x;
	q[qcnt].to=y;
	q[qcnt].next=qhead[x];	
	qhead[x]=qcnt;
}
bool usd[500005];
void dfs(int now,int pre)
{
	for(int i=head[now];i;i=e[i].next)
	{
		if(e[i].to!=pre)
		{
			dfs(e[i].to,now);
			Merge(now,e[i].to);
			usd[e[i].to]=true;
		}
	}
	for(int i=qhead[now];i;i=q[i].next)
	{
		if(usd[q[i].to])
			ans[(i+1)/2]=father(q[i].to);
	}
}
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);		
	}
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		qadd(x,y); 
		qadd(y,x); 
	}
	for(int i=1;i<=n;++i)
		fa[i]=i;
	usd[s]=true;
	dfs(s,0);
	for(int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}
