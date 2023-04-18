#include<cstdio>
#include<algorithm>
using namespace std;
struct edge
{
	int from,to,next;
}e[5005];
struct ans
{
	int a,b;
}Ans[5005];
int num;
int head[1005],dfn[1005],low[1005];
int cnt;
void add(int a,int b)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].next=head[e[cnt].from];
	head[e[cnt].from]=cnt;
} 
bool vis[1005];
int sum;
int fa[5005];
bool cmp(ans x,ans y)
{
	if(x.a!=y.a)
		return x.a<y.a;
	return x.b<y.b;
}
void dfs(int now)
{
	dfn[now]=low[now]=++sum;
	vis[now]=true;
	for(int i=head[now];i;i=e[i].next)
	{
		if(!vis[e[i].to])
		{
			fa[e[i].to]=now;
			dfs(e[i].to);
			low[now]=min(low[now],low[e[i].to]);
		}
		if(dfn[e[i].to]&&e[i].to!=fa[now])
			low[now]=min(low[now],dfn[e[i].to]);
	}	
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
	//	low[i]=2147483647;
	}
	dfs(1);
	for(int i=1;i<=2*m;++i)
	{
		int u=e[i].from,v=e[i].to;
		if(fa[u]==v&&dfn[v]<low[u]||fa[v]==u&&dfn[u]<low[v])
		{
			++num;
			Ans[num].a=min(u,v);
			Ans[num].b=max(u,v);
		}
	}
	sort(Ans+1,Ans+1+num,cmp);
	for(int i=1;2*i<=num;++i)
		printf("%d %d\n",Ans[2*i-1].a,Ans[2*i-1].b);
	return 0;
} 
