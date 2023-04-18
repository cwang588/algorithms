#include<cstdio>
using namespace std;
struct edge
{
	int from,to,next;
}e[50005];
int cnt;
int head[10005],dfn[10005],low[10005];
bool vis[10005],usd[10005];
int stack[10005];
int wz,index;
void dfs(int now)
{
	dfn[now]=low[now]=++index;
	
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		++cnt;
		scanf("%d%d",&e[cnt].from,&e[cnt].to);
		e[cnt].next=head[e[cnt].from];
		head[e[cnt].from]=cnt;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
			dfs(1);
	return 0;
}
