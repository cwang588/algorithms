#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[1000005];
int Head[500005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long ans,tott;
int sz[500005],depth[500005];
void dfs(int now,int pre)
{
	sz[now]=1;
	depth[now]=depth[pre]+1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		sz[now]+=sz[to];
	}
}
int n;
void dfss(int now,int pre,long long tot)
{
	ans=max(ans,tott+1ll*(depth[now])*n-(tot+sz[now]));
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfss(to,now,tot+sz[now]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		tott=ans=cnt=0;
		scanf("%d",&n);
		for(int i=2;i<=n;++i)
		{
			int x;
			scanf("%d",&x);
			add(x,i);
			add(i,x);
		}
		dfs(1,0);
		for(int i=1;i<=n;++i)tott+=sz[i];
		dfss(1,0,0);
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i)Head[i]=0;
	}
	return 0;
}
