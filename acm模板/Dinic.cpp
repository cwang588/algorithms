#include<bits/stdc++.h>
using namespace std;
const long long inf=1145141919810114514;
struct edge
{
	int from,to,nxt;
	long long v;
}e[10005];
int Head[205],cnt=1,dep[205],s,t;
queue<int>q;
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
inline bool BFS(int u)
{
    memset(dep,0,sizeof(dep));
    q.push(u);dep[u]=1;
    while(!q.empty())
	{
        u=q.front();
		q.pop();
        for(int i=Head[u];i;i=e[i].nxt)
		{
            if(e[i].v&&!dep[e[i].to])
			{
                q.push(e[i].to);
                dep[e[i].to]=dep[u]+1;
            }
        }
    }
    return dep[t];
}
inline long long dfs(int u,long long f)
{
    long long ret=0;
    if(u==t) return f;
    for(int i=Head[u],d;i&&f;i=e[i].nxt)
	{
        if(e[i].v&&dep[e[i].to]>dep[u])
		{
            d=dfs(e[i].to,min(f,e[i].v));
            f-=d;ret+=d;e[i].v-=d;e[i^1].v+=d;
        }
    }
    if(!ret)dep[u]=-1;
    return ret;
}
inline long long dinic()
{
    long long ret=0;
    while(BFS(s))ret+=dfs(s,inf);
    return ret;
}
int main()
{
	int n,m;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,0);
	}
	printf("%lld\n",dinic());
	return 0;
}
