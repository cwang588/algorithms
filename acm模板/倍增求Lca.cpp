//±¶ÔöÇólca 
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[1000005];
int cnt,Head[500005];
int n,m,s;
int lg[500005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int depth[500005],f[500005][25];
void dfs(int now,int pre)
{
	f[now][0]=pre;
	for(int i=1;(1<<i)<=depth[now];++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		depth[e[i].to]=depth[now]+1;
		dfs(e[i].to,now);
	}
}
void init()
{
	for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}
int lca(int x,int y)
{
	if(depth[x]<depth[y])swap(x,y);
	while(depth[x]>depth[y])x=f[x][lg[depth[x]-depth[y]]-1];
	if(x==y)return x;
	for(int k=lg[depth[x]]-1;k>=0;--k)
	{
		if(f[x][k]!=f[y][k])
		{
			x=f[x][k];
			y=f[y][k];
		}
	}
	return f[x][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	depth[s]=0;
	dfs(s,0);
	init();
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
