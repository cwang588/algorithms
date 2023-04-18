#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int N,S,T;
int cntt=1,Headd[5005];
struct Node
{
    int v;
    int nxt;
    long long val;
}node[1000010]; 
inline void addedge(int u,int v,long long val)
{
    node[++cntt].v=v;
    node[cntt].val=val;
    node[cntt].nxt=Headd[u];
    Headd[u]=cntt;
}
int dep[5005],gap[5005];
void bfs()
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    dep[T]=0;
    gap[0]=1;
    queue<int>q; 
    q.push(T);
    while(!q.empty())
	{
        int u=q.front();
        q.pop();
        for(int i=Headd[u];i;i=node[i].nxt)
		{
            int v=node[i].v;
            if(dep[v]!=-1)	continue;
            q.push(v);
            dep[v]=dep[u]+1;
            gap[dep[v]]++;
        }
    }
    return;
}
long long maxflow;
long long Dfs(int u,long long flow)
{
    if(u==T)
	{
        maxflow+=flow;
        return flow;
    }
    int used=0;
    for(int i=Headd[u];i;i=node[i].nxt)
	{
        int d=node[i].v;
        if(node[i].val&&dep[d]+1==dep[u])
		{
            long long mi=Dfs(d,min(node[i].val,flow-used));
            if(mi){
                node[i].val-=mi;
                node[i^1].val+=mi;
                used+=mi;
            }
            if(used==flow)return used;
        }
    }
    --gap[dep[u]];
    if(gap[dep[u]]==0)dep[S]=N+1;
    dep[u]++;
    gap[dep[u]]++;
    return used; 
}
long long ISAP()
{
    maxflow=0;
    bfs();
    while(dep[S]<N)Dfs(S,inf);
    return maxflow;
}
int dis[105][105],u[1005],v[1005],t[1005];
bool check(int x,int y){
	return t[x]+dis[u[x]][v[x]]+dis[v[x]][u[y]]<=t[y];
}
int main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)dis[i][j]=1e9;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		dis[x][y]=z;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	N=2*q+2,S=2*q+1,T=2*q+2;
	for(int i=1;i<=q;++i)cin>>u[i]>>v[i]>>t[i];
	for(int i=1;i<=q;++i){
		for(int j=1;j<=q;++j){
			if(i==j)continue;
			if(check(i,j)){
				addedge(i,j+q,1);
				addedge(j+q,i,0);
			}	
		}
	}
	for(int i=1;i<=q;++i){
		addedge(S,i,1);
		addedge(i,S,0);
		addedge(i+q,T,1);
		addedge(T,i+q,0);
	}
	ISAP();
	cout<<q-maxflow<<"\n";
	return 0;
}
