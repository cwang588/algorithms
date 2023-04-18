#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int from,to,value;
}e[100005];
int cnt;
int fa[100005];
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
bool cmp(edge a,edge b)
{
	return a.value<b.value;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			int dis;
			scanf("%d",&dis);
			if(i!=j)
			{
				++cnt;
				e[cnt].from=i;
				e[cnt].to=j;
				e[cnt].value=dis;
			}
		}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Merge(x,y);
	}
	int ans=0;
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;++i)
	{
		int r1=getfa(e[i].from),r2=getfa(e[i].to);
		if(r1!=r2)
		{
			ans+=e[i].value;
			Merge(e[i].from,e[i].to);
		}
	}
	printf("%d\n",ans);
	return 0;
}
