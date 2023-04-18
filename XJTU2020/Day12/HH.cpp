#include<bits/stdc++.h>
using namespace std;
const long long inf=1145142147483647;//inf:���ֵ 
int cnt=1,head[505];//cnt:��CNT����head[i]:��i�������ڵڼ����� 
int n,m,s,t;//n����m����s:Դ��t:��� 
struct Node
{
    int v;//��ǰ�� 
    int next;//���ӵ� 
    long long val;//���� 
}node[100010];//node[i]:��i���ߵ���� 
inline void addedge(int u,int v,int val)
{
    node[++cnt].v=v;
    node[cnt].val=val;
    node[cnt].next=head[u];
    head[u]=cnt;
}
int dep[505],gap[505];//dep[i]��ʾ�ڵ�i����ȣ�gap[i]��ʾ���Ϊi�ĵ������ 
void bfs()//������ 
{
    memset(dep,-1,sizeof(dep));//����ȱ�Ϊ-1(0�ᵼ��gap����) 
    memset(gap,0,sizeof(gap));
    dep[t]=0;//������Ϊ0 
    gap[0]=1;//���Ϊ0�ĵ���1�� 
    queue<int>q; 
    q.push(t);//t����ջ 
    while(!q.empty())
	{
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=node[i].next)//head[u]:u�����ڵı�,node[i].next:u�����ڵıߵ���һ���㣬������������ȥ 
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
long long dfs(int u,long long flow)
{
    if(u==t)
	{
        maxflow+=flow;
        return flow;
    }
    long long used=0;
    for(int i=head[u];i;i=node[i].next)//head[u]:u�����ڵı�,node[i].next:u�����ڵıߵ���һ���㣬������������ȥ 
	{
        int d=node[i].v;
        if(node[i].val&&dep[d]+1==dep[u])//��������ߵĲ�������0,��û�жϲ� 
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
    //����Ѿ��������˵���õ��ȥ�����е㶼�Ѿ�������
    //���Ҵ�ǰ��㴫��������������ʣ��
    //���ʱ��Ҫ�Ըõ����dep
    //ʹ�øõ���õ��ȥ�ĵ�ָ���
    --gap[dep[u]];
    if(gap[dep[u]]==0)dep[s]=n+1;//���ֶϲ㣬�޷�����t��
    dep[u]++;//��++ 
    gap[dep[u]]++;//������Ӧ����++
    return used; 
}
long long ISAP()
{
    maxflow=0;
    bfs();
    while(dep[s]<n)	dfs(s,inf);//ÿ��һ������·,s�Ĳ������1,���һֱû�г��ֶϲ�,�����n-dep(��bfs��ʱs�����)������·����n���� 
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
