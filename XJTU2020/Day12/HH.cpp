#include<bits/stdc++.h>
using namespace std;
const long long inf=1145142147483647;//inf:最大值 
int cnt=1,head[505];//cnt:第CNT条边head[i]:第i个点属于第几条边 
int n,m,s,t;//n个点m条边s:源点t:汇点 
struct Node
{
    int v;//当前点 
    int next;//连接点 
    long long val;//容量 
}node[100010];//node[i]:第i条边的情况 
inline void addedge(int u,int v,int val)
{
    node[++cnt].v=v;
    node[cnt].val=val;
    node[cnt].next=head[u];
    head[u]=cnt;
}
int dep[505],gap[505];//dep[i]表示节点i的深度，gap[i]表示深度为i的点的数量 
void bfs()//倒着搜 
{
    memset(dep,-1,sizeof(dep));//把深度变为-1(0会导致gap崩坏) 
    memset(gap,0,sizeof(gap));
    dep[t]=0;//汇点深度为0 
    gap[0]=1;//深度为0的点有1个 
    queue<int>q; 
    q.push(t);//t点入栈 
    while(!q.empty())
	{
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=node[i].next)//head[u]:u点所在的边,node[i].next:u点所在的边的下一个点，就这样遍历下去 
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
long long dfs(int u,long long flow)
{
    if(u==t)
	{
        maxflow+=flow;
        return flow;
    }
    long long used=0;
    for(int i=head[u];i;i=node[i].next)//head[u]:u点所在的边,node[i].next:u点所在的边的下一个点，就这样遍历下去 
	{
        int d=node[i].v;
        if(node[i].val&&dep[d]+1==dep[u])//如果这条边的残量大于0,且没有断层 
		{
            long long mi=dfs(d,min(node[i].val,flow-used));
            if(mi){
                node[i].val-=mi;
                node[i^1].val+=mi;
                used+=mi;
            }
            if(used==flow)return used;
        }
    }
    //如果已经到了这里，说明该点出去的所有点都已经流过了
    //并且从前面点传过来的流量还有剩余
    //则此时，要对该点更改dep
    //使得该点与该点出去的点分隔开
    --gap[dep[u]];
    if(gap[dep[u]]==0)dep[s]=n+1;//出现断层，无法到达t了
    dep[u]++;//层++ 
    gap[dep[u]]++;//层数对应个数++
    return used; 
}
long long ISAP()
{
    maxflow=0;
    bfs();
    while(dep[s]<n)	dfs(s,inf);//每走一遍增广路,s的层数会加1,如果一直没有出现断层,最多跑n-dep(刚bfs完时s的深度)条增广路共有n个点 
    return maxflow;
}
void add(int x,int y,long long z)
{
	addedge(x,y,z);
	addedge(y,x,0);
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{ 
		cnt=0;
		maxflow=0;
		memset(head,0,sizeof(head));
		memset(dep,0,sizeof(dep));
		memset(gap,0,sizeof(gap));
		s=n+1,t=n+2;
    	int u,v,a,b,c;
    	long long sum=0;
    	for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&c);
			add(s,u,a+b);
			add(s,v,a+b);
			add(u,t,b+c);
			add(v,t,b+c);
			add(u,v,a+c-2*b);
			add(v,u,a+c-2*b);
			sum+=2*a+2*c+2*b;
		}
	    printf("%lld\n",(sum-ISAP()-1)/2);
    }
	return 0;
}
