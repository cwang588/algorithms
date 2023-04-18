#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int N,S,T;
int cntt=1,Headd[65];
struct Node
{
    int v;
    int nxt;
    long long val;
}node[10006]; 
inline void addedge(int u,int v,long long val)
{
    node[++cntt].v=v;
    node[cntt].val=val;
    node[cntt].nxt=Headd[u];
    Headd[u]=cntt;
}
int dep[66],gap[65];
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
int n,a[35][35];
bool check(int m){
	cntt=1;
	memset(Headd,0,sizeof(Headd));
	for(int i=1;i<=n;++i){
		addedge(S,i,1);
		addedge(i,S,0);
		addedge(i+n,T,1);
		addedge(T,i+n,0);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]>=m){
				addedge(i,j+n,1);
				addedge(j+n,i,0);
			}
		}
	}
	ISAP();
	return maxflow==n;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	N=2*n+2,S=2*n+1,T=2*n+2;
	int l=1,r=1000001;
	while(l<r-1){
		int m=(l+r)>>1;
		if(check(m))l=m;
		else r=m;
	}
	cout<<l<<"\n";
	return 0;
}