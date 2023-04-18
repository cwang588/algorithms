#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=220000;
int n,i,j,x,y,g[N],v[N<<1],nxt[N<<1],ed;long long ans;
int size[N],f[N],d[N],son[N],top[N];
inline void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
void dfs(int x){
  size[x]=1;
  for(int i=g[x];i;i=nxt[i])if(v[i]!=f[x]){
    f[v[i]]=x,d[v[i]]=d[x]+1;
    dfs(v[i]),size[x]+=size[v[i]];
    if(size[v[i]]>size[son[x]])son[x]=v[i];
  }
}
void dfs2(int x,int y){
  top[x]=y;
  if(son[x])dfs2(son[x],y);
  for(int i=g[x];i;i=nxt[i])if(v[i]!=son[x]&&v[i]!=f[x])dfs2(v[i],v[i]);
}
inline int lca(int x,int y){
  for(;top[x]!=top[y];x=f[top[x]])if(d[top[x]]<d[top[y]])swap(x,y);
  return d[x]<d[y]?d[x]:d[y];
}
int main()
{
  scanf("%d",&n);
  for(i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
  dfs(1);
  dfs2(1,1);
  for(i=1;i<=n;i++)for(j=i+i;j<=n;j+=i){
    ans+=d[i]+d[j]-2*lca(i,j)+1;
  }
  printf("%lld",ans);
}
