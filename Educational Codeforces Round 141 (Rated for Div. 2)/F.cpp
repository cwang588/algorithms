#include<bits/stdc++.h>
using namespace std;
int a[3005],b[3005];
bool usda[3005],usdb[3005];
int cola[3005],colb[3005],cnta,cntb;
const int inf=2147483647;//inf:最大值
int cntt=1,Headd[7005];//cnt:第CNT条边Headd[i]:第i个点属于第几条边 
int N,S,T;//n个点m条边s:源点t:汇点 
struct Node
{
    int v;//当前点 
    int nxt;//连接点 
    long long val;//容量 
    int id;
}node[100010];//node[i]:第i条边的情况 
inline void addedge(int u,int v,long long val,int id)
{
    node[++cntt].v=v;
    node[cntt].val=val;
    node[cntt].nxt=Headd[u];
	node[cntt].id=id;
    Headd[u]=cntt;
}
int dep[7005],gap[7005];//dep[i]表示节点i的深度，gap[i]表示深度为i的点的数量 
void bfs()//倒着搜 
{
    memset(dep,-1,sizeof(dep));//把深度变为-1(0会导致gap崩坏) 
    memset(gap,0,sizeof(gap));
    dep[T]=0;//汇点深度为0 
    gap[0]=1;//深度为0的点有1个 
    queue<int>q; 
    q.push(T);//t点入栈 
    while(!q.empty())
	{
        int u=q.front();
        q.pop();
        for(int i=Headd[u];i;i=node[i].nxt)//Headd[u]:u点所在的边,node[i].nxt:u点所在的边的下一个点，就这样遍历下去 
		{
            int v=node[i].v;//v为当前边的下一个点 
            if(dep[v]!=-1)	continue;//dep[v]!=-1相当于v点已被遍历||不管 
            q.push(v);
            dep[v]=dep[u]+1;//v点的深度比u点大1 
            gap[dep[v]]++;
        }//直到所有点都被遍历过 
    }
    return;
}//从t到s跑一遍bfs，标记深度
long long maxflow;
long long Dfs(int u,long long flow)
{
    if(u==T)
	{
        maxflow+=flow;
        return flow;
    }
    int used=0;
    for(int i=Headd[u];i;i=node[i].nxt)//Headd[u]:u点所在的边,node[i].nxt:u点所在的边的下一个点，就这样遍历下去 
	{
        int d=node[i].v;
        if(node[i].val&&dep[d]+1==dep[u])//如果这条边的残量大于0,且没有断层 
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
bool usd[3005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		if(usda[i])continue;
		cola[i]=++cnta;
		usda[i]=true;
		int now=a[i];
		while(now!=i){
			usda[now]=true;
			cola[now]=cnta;
			now=a[now];
		}
	}
	for(int i=1;i<=n;++i){
		if(usdb[i])continue;
		colb[i]=++cntb;
		usdb[i]=true;
		int now=b[i];
		while(now!=i){
			usdb[now]=true;
			colb[now]=cntb;
			now=b[now];
		}
	}
	N=2*n+2,S=2*n+1,T=2*n+2;
	for(int i=1;i<=n;++i){
		addedge(S,i,1,0);
		addedge(i,S,0,0);
		addedge(cola[i],colb[i]+n,1,i);
		addedge(colb[i]+n,cola[i],0,0);
		addedge(i+n,T,1,0);
		addedge(T,i+n,0,0);
	}
	ISAP();
	cout<<n-maxflow<<"\n";
	for(int i=2;i<=cntt;i+=2){
		if(!node[i].id)continue;
		if(node[i].val==0)usd[node[i].id]=true;
	}
	for(int i=1;i<=n;++i)if(!usd[i])cout<<i<<" ";
	return 0;
}