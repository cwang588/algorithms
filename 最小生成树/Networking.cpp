#include<cstdio>
#include<algorithm>
using namespace std;
int fa[100005];
struct edge
{
	int from,to,value;
}e[1000005];
bool cmp(edge x,edge y)
{
	return x.value<y.value;
}
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
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		int m;
		scanf("%d",&m);
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=m;++i)scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].value);
		sort(e+1,e+1+m,cmp);
		int ans=0;
		for(int i=1;i<=m;++i)
		{
			int r1=getfa(e[i].from),r2=getfa(e[i].to);
			if(r1!=r2)
			{
				ans+=e[i].value;
				Merge(e[i].from,e[i].to);
			}
		}
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	return 0;
}
