#include<bits/stdc++.h>
using namespace std;
int fa[200005];
struct edge
{
	int from,to,v;
}e[200005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	fa[x]=y;
}
bool cmp(edge a,edge b)
{
	if(a.v!=b.v)return a.v<b.v;
	return a.from<b.from;
}
int main()
{
	int n,m;	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].v);
		if(e[i].from>e[i].to)swap(e[i].from,e[i].to);
	}
	sort(e+1,e+1+m,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;++i)
	{
		int x=e[i].from,y=e[i].to;
		int r1=getfa(x),r2=getfa(y);
		if(r1==r2)continue;
		++cnt;
		Merge(r1,r2);
		if(x==1)++ans;
	}
	printf("%d\n",ans);
	return 0;
}
