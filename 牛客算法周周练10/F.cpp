#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
	long long num;
}e[200005];
int Head[100005],sz[100005],cnt;
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
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		sz[now]+=sz[to];
	}
}
bool cmp(edge x,edge y)
{
	return x.num>y.num;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=cnt;++i)
	{
		int x=e[i].from,y=e[i].to;
		if(sz[x]<sz[y])swap(x,y);
		e[i].num=(long long)(sz[y])*(long long)(n-sz[y]);
	}
	sort(e+1,e+1+cnt,cmp);
	long long ans=0;
	for(int i=1;i<n;++i)ans+=(long long)i*e[2*i].num;
	printf("%lld\n",ans);
	return 0;
} 
