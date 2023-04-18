#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[400005];
int Head[100005],cnt;
long long ans[100005];
int num[100005];
long long value[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool cmp(int x,int y)
{
	return value[x]>value[y];
}
bool usd[100005];
int fa[100005];
int getfa(int x)
{
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y)
{
	fa[x]=y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(Head,0,sizeof(Head));
		memset(ans,0,sizeof(ans));
		memset(usd,0,sizeof(usd));
		memset(value,0,sizeof(value));
		cnt=0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%lld",&value[i]);
		for(int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=n;++i)fa[i]=num[i]=i,ans[i]=value[i];
		sort(num+1,num+1+n,cmp);
		for(int i=1;i<=n;++i)
		{
			int now=num[i];
			usd[now]=true;
			for(int j=Head[now];j;j=e[j].nxt)
			{
				if(!usd[e[j].to])continue;
				int r1=getfa(now),r2=getfa(e[j].to);
				if(r1!=r2)
				{
					Merge(r2,r1);
					ans[now]+=ans[r2]-value[now];
				}
			}
		}
		long long tot=0; 
		for(int i=1;i<=n;++i)if(fa[i]==i)tot+=ans[i];
		printf("%lld\n",tot);
	}
	return 0;
}
