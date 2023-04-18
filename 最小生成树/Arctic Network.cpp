#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int x[505],y[505];
struct edge
{
	int from,to,value;
}e[2000005];
bool cmp(edge x,edge y)
{
	return x.value<y.value;
}
int cnt;
int fa[2005];
int getfa(int x)
{
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
}
int getdis(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
int ans[20005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)fa[i]=i,scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=m;++i)
			for(int j=i+1;j<=m;++j)
			{
				++cnt;
				e[cnt].from=i;
				e[cnt].to=j;
				e[cnt].value=getdis(i,j);
			}
		sort(e+1,e+1+cnt,cmp);
		int num=0;
		for(int i=1;i<=cnt;++i)
		{
			int r1=getfa(e[i].from),r2=getfa(e[i].to);
			if(r1!=r2)
			{
				ans[++num]=e[i].value;
				Merge(e[i].from,e[i].to);
			}
		}
		sort(ans+1,ans+1+num);
		printf("%.2f\n",sqrt(ans[m-n]));
	}
	return 0;
}
