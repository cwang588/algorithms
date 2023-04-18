#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
	long long ans;
	long long v;
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
int sz[200005],t[200005];
long long tot[200005];
void dfs(int now,int pre)
{
	sz[now]=1;
	tot[now]=(long long)t[now];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(pre==to)continue;
		dfs(to,now);
		sz[now]+=sz[to];
		tot[now]+=tot[to];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	long long tott=0;
	for(int i=1;i<=n;++i)cin>>t[i],tott+=t[i];
	for(int i=1;i<n;++i)
	{
		int a,b;
		long long v;
		cin>>a>>b>>v;
		add(a,b,v);
		add(b,a,v);
	}
	dfs(1,0);
	for(int i=1;i<=cnt;++i)
	{
		long long num1=min(sz[e[i].from],sz[e[i].to]),num2=n-num1,sum1=min(tot[e[i].from],tot[e[i].to]),sum2=tott-sum1;
		e[i].ans=(num1*sum2+num2*sum1)*e[i].v;
	}
	for(int i=1;i<n;++i)cout<<e[2*i].ans*2<<endl;
	return 0;
}
