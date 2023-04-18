#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt,sz[100005],maxson[100005],fa[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre)
{
	sz[now]=1;
	int Max=0;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		fa[to]=now;
		sz[now]+=sz[to];
		if(sz[to]>Max)
		{
			Max=sz[to];
			maxson[now]=to;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)Head[i]=fa[i]=sz[i]=maxson[i]=0;
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		int maxnum=2147483647,sum=0;
		for(int i=1;i<=n;++i)
		{
			int now=max(n-sz[i],sz[maxson[i]]);
			if(now<maxnum)
			{
				sum=1;
				maxnum=now;
			}
			else if(now==maxnum)++sum;
			else;
		}
		if(sum==1)
		{
			printf("%d %d\n",e[1].from,e[1].to);
			printf("%d %d\n",e[1].from,e[1].to);
		}
		else
		{
			int x=0,y=0;
			for(int i=1;i<=n;++i)
			{
				int now=max(n-sz[i],sz[maxson[i]]);
				if(now==maxnum)
				{
					if(!x)x=i;
					else y=i;
				}
			}
			if(fa[y]==x)swap(x,y);
			printf("%d %d\n",x,maxson[x]);
			printf("%d %d\n",y,maxson[x]);
		}
	}
	return 0;
}
