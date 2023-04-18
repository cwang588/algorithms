#include<bits/stdc++.h>
using namespace std;
struct edge
{
	long long v;
	int from,to,nxt;
}e[400005];
int Head[200005],cnt;
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;	
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long Max,Maxsum;
void dfs(int now,int pre,long long tot)
{
	if(tot>Max)
	{
		Max=tot;
		Maxsum=now;
	}
	for(int i=Head[now];i;i=e[i].nxt)
		if(e[i].to!=pre)
			dfs(e[i].to,now,tot+e[i].v);
}
int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		long long z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
		ans+=z*2;
	}
	dfs(1,0,0);
	Max=0;
	dfs(Maxsum,0,0);
	printf("%lld\n",ans-Max);
	return 0;
} 
