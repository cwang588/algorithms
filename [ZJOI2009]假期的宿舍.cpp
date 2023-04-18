#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;//inf:���ֵ
int cntt=1,Headd[505];//cnt:��CNT���߲��ܳ�ʼ��Ϊ0��Headd[i]:��i�������ڵڼ����� 
int N,M,S,T;//n����m����s:Դ��t:��� 
struct Node
{
    int v;//��ǰ�� 
    int nxt;//���ӵ� 
    long long val;//���� 
}node[1010];//node[i]:��i���ߵ���� 
inline void addedge(int u,int v,long long val)
{
    node[++cntt].v=v;
    node[cntt].val=val;
    node[cntt].nxt=Headd[u];
    Headd[u]=cntt;
}
int dep[505],gap[505];//dep[i]��ʾ�ڵ�i����ȣ�gap[i]��ʾ���Ϊi�ĵ������ 
void bfs()//������ 
{
    memset(dep,-1,sizeof(dep));//����ȱ�Ϊ-1(0�ᵼ��gap����) 
    memset(gap,0,sizeof(gap));
    dep[T]=0;//������Ϊ0 
    gap[0]=1;//���Ϊ0�ĵ���1�� 
    queue<int>q; 
    q.push(T);//t����ջ 
    while(!q.empty())
	{
        int u=q.front();
        q.pop();
        for(int i=Headd[u];i;i=node[i].nxt)//Headd[u]:u�����ڵı�,node[i].nxt:u�����ڵıߵ���һ���㣬������������ȥ 
		{
            int v=node[i].v;//vΪ��ǰ�ߵ���һ���� 
            if(dep[v]!=-1)	continue;//dep[v]!=-1�൱��v���ѱ�����||���� 
            q.push(v);
            dep[v]=dep[u]+1;//v�����ȱ�u���1 
            gap[dep[v]]++;
        }//ֱ�����е㶼�������� 
    }
    return;
}//��t��s��һ��bfs��������
long long maxflow;
long long Dfs(int u,long long flow)
{
    if(u==T)
	{
        maxflow+=flow;
        return flow;
    }
    long long used=0;
    for(int i=Headd[u];i;i=node[i].nxt)//Headd[u]:u�����ڵı�,node[i].nxt:u�����ڵıߵ���һ���㣬������������ȥ 
	{
        int d=node[i].v;
        if(node[i].val&&dep[d]+1==dep[u])//��������ߵĲ�������0,��û�жϲ� 
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
int zx[55],homo[55],usd[55][55];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		cntt=1;
		memset(Headd,0,sizeof(Headd)); 
		for(int i=1;i<=n;++i)scanf("%d",&zx[i]);
		for(int i=1;i<=n;++i)scanf("%d",&homo[i]);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)scanf("%d",&usd[i][j]);
			usd[i][i]=1;
		}
		N=2*n+2,S=2*n+1,T=2*n+2,M=0;
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(zx[i])
			{
				addedge(i+n,T,1);
				addedge(T,i+n,0);
				++M;
			}
			if(!zx[i]||!homo[i])
			{
				addedge(S,i,1);
				addedge(i,S,0);
				++M,++cnt;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(zx[i]&&homo[i])continue;
			for(int j=1;j<=n;++j)
			{
				if(usd[i][j])
				{
					addedge(i,j+n,1);
					addedge(j+n,i,0);
					++M;
				}
			} 
		}
		maxflow=0;
    	if(ISAP()==cnt)printf("^_^\n");
    	else printf("T_T\n");
    }
	return 0;
}
