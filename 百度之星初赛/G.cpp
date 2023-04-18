#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005]; 
int Head[100005],cnt;
long long sum[100005],num;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
int n,m;
int fa[100005],sz[100005];
void dfs(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		++sz[now];
		int to=e[i].to;
		if(to==pre)continue;
		fa[to]=now;
		dfs(to,now);
	}
}
int main()
{
	int t;
	scanf("%d",&t);	
	while(t--)
	{
		cnt=num=0;
		memset(Head,0,sizeof(Head));
		memset(fa,0,sizeof(fa));
		memset(sz,0,sizeof(sz));
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		int now=m;
		while(now)
		{
			sum[++num]=sz[now];
			now=fa[now];
		}
		long long ans=0;
	}
	return 0;
}
