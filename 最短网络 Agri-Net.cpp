#include<bits/stdc++.h>
using namespace std;
int dis[105][105];
struct edge
{
	int x,y,z;
	bool operator < (const edge &a)const
	{
		return z<a.z;
	}
}e[100005];
int fa[105];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void merge(int a,int b)
{
	fa[b]=a;
}
int main()
{
	int n;
	scanf("%d",&n);
	int num=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int t;
			scanf("%d",&t);
			++num;
			e[num].x=i;
			e[num].y=j;
			e[num].z=t;
		}
	for(int i=1;i<=n;++i)fa[i]=i;
	sort(e+1,e+1+num);
	int ans=0,tot=0;
	for(int i=1;i<=num;++i)
	{
		int r1=getfa(e[i].x),r2=getfa(e[i].y);
		if(r1!=r2)
		{
			ans+=e[i].z;
			++tot;
			merge(r1,r2);
		}
		if(tot==n-1)return !printf("%d\n",ans);
	}
	return 0;
}
