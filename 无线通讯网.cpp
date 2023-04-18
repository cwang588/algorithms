#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
}p[505];
struct edge
{
	int x,y,z;
	bool operator < (const edge &a)const 
	{
		return z<a.z;
	}
}e[550005];
int fa[305];
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
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
		{
			++cnt;
			e[cnt].x=i;
			e[cnt].y=j;
			e[cnt].z=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
		}
	sort(e+1,e+1+cnt);
	int num=0;
	for(int i=1;i<=cnt;++i)
	{
		int r1=getfa(e[i].x),r2=getfa(e[i].y);
		if(r1!=r2)
		{
			++num;
			merge(r1,r2);
		} 
		if(num==n-m)return !printf("%.2lf\n",sqrt(e[i].z));
	}
	return 0;
}
