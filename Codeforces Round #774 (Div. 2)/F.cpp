#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;//inf:最大值
int cntt=1,Headd[505];//cnt:第CNT条边Headd[i]:第i个点属于第几条边 
int N,M,S,T;//n个点m条边s:源点t:汇点 
struct Node
{
    int u,v;//当前点 
    int nxt;//连接点 
    long long val;//容量 
}node[50001];//node[i]:第i条边的情况 
inline void addedge(int u,int v,long long val)
{
    node[++cntt].v=v;
    node[cntt].u=u;
    node[cntt].val=val;
    node[cntt].nxt=Headd[u];
    Headd[u]=cntt;
}
int dep[505],gap[505];//dep[i]表示节点i的深度，gap[i]表示深度为i的点的数量 
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
int num[105][105];
int tmpnow[1005],tmpp[1005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++i){
    		int tmp;
    		cin>>tmp;
    		++num[i][tmp];
		}
	}
	N=2*n+2,S=2*n+1,T=2*n+2;
	cout<<n*n-n<<"\n";
	for(int i=1;i<=n;++i){
		cntt=1;
		memset(Headd,0,sizeof(Headd));
		for(int j=1;j<=n;++j){
			addedge(S,j,1);
			addedge(j,S,0);
			addedge(j+n,T,1);
			addedge(T,j+n,0);
		}
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(num[j][k]){
					addedge(j,k+n,1);
					addedge(k+n,j,0);
				}
			}
		}
		int tmp=ISAP();
		assert(tmp==n);
		for(int j=2;j<=cntt;j+=2){
			if(node[j].u>=1&&node[j].u<=n&&node[j].val==0)tmpnow[node[j].u]=node[j].v;
		}
		for(int j=1;j<n;++j){
			for(int k=1;k<=n;++k){
				if(tmpnow[k]==k){
					--cnt[k];
					for(int o=1;o<=n;++o){
						if(cnt[o]){
							tmpnow[k]=o;
							break;
						}
					}
				}
			}
			for(int k=1;k<=n;++k)cout<<tmpnow[k]<<" ";
			cout<<"\n";
			for(int )
		}
	}
    return 0;
}