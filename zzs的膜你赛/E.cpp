#include<bits/stdc++.h>
using namespace std;
int Max[100005],Min[100005];
struct edge
{
	int from,to,next;
}e[200005];
int cnt,v[100005],head[100005];
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
	Max[now]=Min[now]=1;
	for(int i=head[now];i;i=e[i].next)
	{
		dfs(e[i].to);
		if(v[now]>v[e[i].to])
			Max[now]=max(Max[now],Max[e[i].to]+1);
		if(v[now]<v[e[i].to])
			Min[now]=max(Min[now],Min[e[i].to]+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int b;
		scanf("%d%d",&v[i],&b);
		if(b)
			add(b,i);
	}
	dfs(1);
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(Max[i]+Min[i]-1,ans);
	printf("%d\n",ans);
	return 0;
}
