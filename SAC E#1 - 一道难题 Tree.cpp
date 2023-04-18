#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;//inf:���ֵ
int cntt=1,Headd[100005];//cnt:��CNT����Headd[i]:��i�������ڵڼ����� 
int N,M,S,T;//n����m����s:Դ��t:��� 
struct Node
{
    int v;//��ǰ�� 
    int nxt;//���ӵ� 
    long long val;//���� 
}node[400010];//node[i]:��i���ߵ���� 
inline void addedge(int u,int v,long long val)
{
    node[++cntt].v=v;
    node[cntt].val=val;
    node[cntt].nxt=Headd[u];
    Headd[u]=cntt;
}
int dep[100005],gap[100005];//dep[i]��ʾ�ڵ�i����ȣ�gap[i]��ʾ���Ϊi�ĵ������ 
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
    int used=0;
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
struct edge
{
	int from,to,nxt;
	long long value;
}e[200005];
int Head[100005],cnt;
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int root,n;
void dfs(int now,int pre)
{
	bool ky=false;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		ky=true;
		addedge(now,to,e[i].value);
		addedge(to,now,0);
		++M;
		dfs(to,now);
	}
	if(!ky)
	{
		addedge(now,n+1,inf);
		addedge(n+1,now,0);
		++M;
	}
}
int main()
{
    scanf("%d%d",&n,&root);
    for(int i=1;i<n;++i)
    {
    	int x,y;
    	long long z;
    	scanf("%d%d%lld",&x,&y,&z);
    	add(x,y,z);
    	add(y,x,z);
    }
    N=n+1,S=root,T=n+1;
    dfs(root,0);
    printf("%lld\n",ISAP());
    return 0;
}
