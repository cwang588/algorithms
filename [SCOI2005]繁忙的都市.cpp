#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int x,y,z;
	bool operator < (const edge &a)const
	{
		return z<a.z;
	}
}e[100005];
int fa[30005];
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
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+1+m);
	for(int i=1;i<=n;++i)fa[i]=i;
	int num=0;
	for(int i=1;i<=m;++i)
	{
		int r1=getfa(e[i].x),r2=getfa(e[i].y);
		if(r1!=r2)
		{
			++num;
			merge(r1,r2);
		}
		if(num==n-1)return !printf("%d %d\n",n-1,e[i].z);
	}
	return 0;
}
