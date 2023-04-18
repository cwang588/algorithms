#include<bits/stdc++.h>
using namespace std;
int fa[1005],sz[1005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int maxn;
void merge(int a,int b)
{
	fa[b]=a;
	sz[a]+=sz[b];
	maxn=max(maxn,sz[a]);
}
struct road
{
	int x,y,t;
	bool operator < (const road a)const
	{
		return t<a.t;
	}
}r[1000005];
int main()
{
	maxn=1;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)sz[i]=1,fa[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].t);
	sort(r+1,r+1+m);
	for(int i=1;i<=m;++i)
	{
		int r1=getfa(r[i].x),r2=getfa(r[i].y);
		if(r1!=r2)merge(r1,r2);
		if(maxn==n)return !printf("%d\n",r[i].t);
	}
	printf("-1\n");
	return 0;
}
