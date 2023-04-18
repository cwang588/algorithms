#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
struct edge
{
	int from,to,next;
}e[200005];
long long head[200005];
long long a[200005],b[200005];
long long cnt,num;
long long sum[200005];
bool usd[200005];
bool cmp(long long x,long long y)
{
	return x>y;
}
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
void dfs(int now)
{
	usd[now]=true;
	b[now]=num;
	for(int i=head[now];i;i=e[i].next)
	{
		if(!usd[e[i].to])
			dfs(e[i].to);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		add(i,t);
		add(t,i);
	}
	for(int i=1;i<=n;++i)
		if(!usd[i])
		{
			++num;
			dfs(i);
		}
	for(int i=1;i<=n;++i)
		sum[b[i]]+=a[i];
	sort(sum+1,sum+num+1,cmp);
	long long ans=0;
	for(int i=1;i<=m;++i)
		ans+=sum[i];
	printf("%lld",ans);
	return 0;
}
