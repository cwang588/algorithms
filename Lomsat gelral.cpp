#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005],col[100005],depth[100005],sz[100005],son[100005],num[100005];
long long Max,sum;
long long ans[100005];
bool usd[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs1(int now,int pre)
{
	depth[now]=depth[pre]+1;
	sz[now]=1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		sz[now]+=sz[to];
		if(sz[to]>sz[son[now]])son[now]=to;
	}
}
void update(int now,int pre,int type)
{
	num[col[now]]+=type;
	if(type==1)
	{
		if(num[col[now]]>Max)
		{
			Max=num[col[now]];
			sum=col[now];
		}
		else if(num[col[now]]==Max)sum+=col[now];
		else;
	}
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
		update(to,now,1); 
	}
	++num[col[now]];
	if(num[col[now]]>Max)
	{
		Max=num[col[now]];
		sum=col[now];
	}
	else if(num[col[now]]==Max)sum+=col[now];
	else;
	ans[now]=sum;
	usd[son[now]]=false;
	if(!keep)
	{
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre||usd[to])continue;
			update(to,now,-1);
		}
		--num[col[now]];
		Max=0;
		sum=0;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&col[i]);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	} 
	dfs1(1,0);
	dfs2(1,0,true);
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;
}
