#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
	long long value;
}e[500005];
int Head[500005],cnt;
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
} 
int fa[500005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){fa[x]=y;}
bool cmp(edge a,edge b)
{
	return a.value>b.value;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
	}
	sort(e+1,e+1+m,cmp);
	long long ans=0;
	int num=0;
	for(int i=1;i<=cnt;++i)
	{
		int r1=getfa(e[i].from),r2=getfa(e[i].to);
		if(r1!=r2)
		{
			ans+=e[i].value;
			Merge(r1,r2);
			++num;
		}
		if(num==n-1)break;
	}
	printf("%lld\n",ans);
	return 0;
} 
