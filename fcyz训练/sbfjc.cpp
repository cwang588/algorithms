#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ls(x) st[x].ch[0]
#define rs(x) st[x].ch[1]
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
inline int read(){
    int w=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        w=(w<<3)+(w<<1)+ch-48;
        ch=getchar();
    }
    return w*f;
}
int n,m,Q,tot,val[1000010],a[1000010],b[1000010],root[1000010],maxx=1000000;
bool debug;
int ans[500010];
struct DSU_ON_TREE{
    struct Node{
        int size,ch[2];
    }st[20000010];
    inline void pushup(int x){
        st[x].size=st[ls(x)].size+st[rs(x)].size;
    }
    inline int change(int p,int l,int r,int pos,int val){
        if(!p) p=++tot;
        if(l==r){
            st[p].size=1;return p;
        }
        int mid=(l+r)>>1;
        if(pos<=mid) ls(p)=change(ls(p),l,mid,pos,val);
        else rs(p)=change(rs(p),mid+1,r,pos,val);
        pushup(p);return p;
    }
    inline int merge(int x,int y,int l,int r){
        if(!x||!y) return x|y;
        if(l==r){
            if(st[x].size||st[y].size) st[x].size=1;
            return x;
        }
        int mid=(l+r)>>1;
        ls(x)=merge(ls(x),ls(y),l,mid);
        rs(x)=merge(rs(x),rs(y),mid+1,r);
        pushup(x);return x;
    }
}DSU;
struct Edge{
    int from,to,next;
}edge[1000010];
int head[500010],cnt;
inline void addedge(int u,int v){
    cnt++;
    edge[cnt].from=u;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
bool vis[500010];
inline void dfs(int u){
    vis[u]=true;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;if(vis[v]) continue;
        dfs(v);root[u]=DSU.merge(root[u],root[v],0,maxx);
    }
    if(DSU.st[root[u]].size)ans[u]=DSU.st[root[u]].size;
}
int main(){
//	freopen("sb10.in","r",stdin);
//	freopen("sb10.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();maxx=max(a[i],maxx);
    }
    for(int i=1;i<n;i++){
        int x=read();int y=read();
        addedge(x,y);addedge(y,x);
    }
    for(int i=1;i<=n;i++){
        root[i]=DSU.change(root[i],0,maxx,a[i],1);
    }
    dfs(1);
    while(m--){
        int x=read();printf("%d\n",ans[x]);
    }
    return 0;
}
