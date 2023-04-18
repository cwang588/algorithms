#include<bits/stdc++.h>
#define N 100010
#define M 300110
#define lint long long
using namespace std;
int n,m,s,cnt,root1,root2;
int head[M],lc[M],rc[M],tot;
struct edge 
{
    int v,w,nxt; 
}edge[N*20];
void AddEdge(int u,int v,int w) 
{ 
    edge[++tot].v=v;
	edge[tot].w=w;
	edge[tot].nxt=head[u];
	head[u]=tot;
}
void build1(int &p,int l,int r) 
{ 
    if(l==r) 
	{
        p=l; 
        return;
    }
    p=++cnt;
    int mid=(l+r)>>1;
    build1(lc[p],l,mid);
    build1(rc[p],mid + 1, r);
    AddEdge(p,lc[p],0);
    AddEdge(p,rc[p],0);
}
void build2(int &p, int l, int r) 
{
    if(l==r) 
	{ 
        p=l; 
        return;
    }
    p=++cnt;
    int mid=(l+r)>>1;
    build2(lc[p],l,mid);
    build2(rc[p],mid+1,r);
    AddEdge(lc[p],p,0);
    AddEdge(rc[p],p,0);
}
int L,R;
void updata(int p,int l,int r,int u,int w,int type) 
{
    if(L<=l&&r<=R) 
	{
        type==2?AddEdge(u,p,w):AddEdge(p,u,w);
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid) 
		updata(lc[p],l,mid,u,w,type);
    if(mid<R)
		updata(rc[p],mid+1,r,u,w,type);
}
const lint INF=0x3F3F3F3F3F3F3F3F;
lint dist[M];
queue<int> Q;
void SPFA(int s) 
{
    memset(dist,127,sizeof dist);
    dist[s]=0;
	Q.push(s);
    while(!Q.empty()) 
	{
        int u=Q.front(); 
		Q.pop();
        for(int i=head[u];i;i=edge[i].nxt) 
		{
            int v=edge[i].v,w =edge[i].w;
            if (dist[u]+w<dist[v]) 
                dist[v]=dist[u]+w,
            Q.push(v);
        }
    }
}
int main() 
{
    scanf("%d%d%d", &n, &m, &s);
    cnt=n;
    build1(root1,1,n); 
    build2(root2,1,n);
    while(m--) 
	{
        int opt,u,v,w;
        scanf("%d",&opt);
        if(opt==1) 
		{
            scanf("%d%d%d", &u,&v,&w);
            AddEdge(u,v,w);
        }
        else 
		{
            scanf("%d%d%d%d",&u,&L,&R,&w);
            updata(opt==2?root1:root2,1,n,u,w,opt);
        }
    }
    SPFA(s);
    for(int i=1;i<=n;i++) 
        cout<<(dist[i]<INF?dist[i]:-1)<<endl;
    return 0;
}
