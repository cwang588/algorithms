#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 200010;
vector<int> E[N],G[N],T[N];
int n,m,deg[N],rt,a[N],dep[N],val[N];
int f[N][20],tot;
void BFS()
{
    queue<int> q;
    rt = n+1;
    for(int i=1;i<=n;i++)if(!deg[i]){q.push(i);E[rt].pb(i);G[i].pb(rt);}
    int tot = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        a[++tot] = u;
        for(int v : E[u])if((--deg[v]) == 0)q.push(v);
    }
}
int LCA(int x,int y)
{
    if(dep[x] > dep[y])swap(x,y);
    for(int i=19;i>=0;i--)if(dep[y] > dep[x] && dep[f[y][i]] >= dep[x])y = f[y][i];
    if(x == y)return x;
    for(int i=19;i>=0;i--)if(f[x][i] != f[y][i]) x = f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
    int tt;
	scanf("%d",&tt);
    while(tt--)
	{
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n+1;i++)
		{
            E[i].clear();
			G[i].clear();
			T[i].clear();
            dep[i]=deg[i]=0;
        }
        for(int i=1,u,v;i<=m;i++)
		{
            scanf("%d%d",&u,&v);
            E[v].pb(u);
			G[u].pb(v);
			deg[u]++;
        }
        BFS();
        dep[rt]=1;
        for(int i=1;i<=n;i++)
		{
            int u=a[i],fa=-1;
            for(int v:G[u])fa=(fa==-1?v:LCA(fa,v));
            dep[u]=dep[fa]+1;
            f[u][0]=fa;T[fa].pb(u);
            for(int i=1;i<=19;i++)f[u][i]=f[f[u][i-1]][i-1];
        }
        int q;
		scanf("%d",&q);
        while(q--)
		{
            int u,v;
			scanf("%d%d",&u,&v);
            int lca=LCA(u,v);
            printf("%d\n",dep[u]+dep[v]-dep[lca]-1);
        }
    }
}
