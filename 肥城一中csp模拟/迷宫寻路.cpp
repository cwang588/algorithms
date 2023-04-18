#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
	long long v;
}e[200005];
int Head[100005],cnt,size[100005];
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre)
{
	size[now]=1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		dfs(e[i].to,now);
		size[now]+=size[e[i].to];
	}
}
int main()
{
	int n; 
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		long long z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	long long ans=0;
	for(int i=1;i*2<=cnt;++i) 
	{
		int x=e[2*i].from,y=e[2*i].to;
		long long t=min(size[x],size[y]);
		ans+=t*((long long)n-t)*e[2*i].v;
	}
	cout<<ans*2;
	return 0;
}
