#include<cstdio>
using namespace std;
bool usd[10005];
int fa[10005];
int find(int x)
{
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(int a,int b)
{
	fa[b]=a;
}
int main()
{
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=10000;++i)
		fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		int num;
		scanf("%d",&num);
		int t,tt;
		scanf("%d",&t);
		tt=find(t);
		if(!usd[t])
		{
			++tot;
			usd[t]=true;
		}
		for(int i=2;i<=num;++i)
		{
			int x;
			scanf("%d",&x);
			if(!usd[x])
			{
				++tot;
				usd[x]=true;
			}
			int ttt=find(x);
			if(ttt!=tt)
				unionn(tt,ttt);
		}
	}
	printf("%d ",tot);
	int ans=0;
	for(int i=1;i<=10000;++i)
		if(usd[i]&&fa[i]==i)
			++ans;
	printf("%d\n",ans);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)==find(y))
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
