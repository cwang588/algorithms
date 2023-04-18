#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
	int from,to,value;
}e[2000005];
int cnt,fa[200005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	int r1=getfa(x),r2=getfa(y);
	fa[r1]=r2;
}
int x[20005],y[20005];
int getdis(int i,int j)
{
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
bool cmp(edge a,edge b)
{
	return a.value<b.value;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)fa[i]=i,scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			++cnt;
			e[cnt].from=i;
			e[cnt].to=j;
			e[cnt].value=getdis(i,j);
		}
	sort(e+1,e+1+cnt,cmp);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		Merge(t1,t2);
	}
	for(int i=1;i<=cnt;++i)
	{
		int r1=getfa(e[i].from),r2=getfa(e[i].to);
		if(r1!=r2)
		{
			Merge(e[i].from,e[i].to);
			printf("%d %d\n",e[i].from,e[i].to);
		}
	}
	return 0;
}
