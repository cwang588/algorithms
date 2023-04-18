#include<cstdio>
#include<algorithm>
#include<cmath>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=100000+10;
int h[maxn],go[maxn*2],nxt[maxn*2],a[maxn];
int h2[maxn],g2[maxn*2],n2[maxn*2];
int f[maxn][25],g[maxn][25],dep[maxn],dp[maxn],fa[maxn][25],zjy[maxn],d[maxn];
int i,j,k,l,t,n,m,tot,top,ans;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9')
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9')
    {   
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void add(int x,int y)
{
    go[++tot]=y;
    nxt[tot]=h[x];
    h[x]=tot;
}
void add2(int x,int y)
{
    d[y]++;
    g2[++tot]=y;
    n2[tot]=h2[x];
    h2[x]=tot;
}
void dfs(int x,int y)
{
    dep[x]=dep[y]+1;
    f[x][0]=y;
    g[x][0]=a[x];
    int t=h[x];
    while (t)
    {
        if (go[t]!=y) dfs(go[t],x);
        t=nxt[t];
    }
}
void dg(int x)
{
    int t=h2[x];
    while (t)
    {
        fa[g2[t]][0]=x;
        dp[g2[t]]=dp[x]+1;
        dg(g2[t]);
        t=n2[t];
    }
}
int main()
{
    n=read();m=read();
    fo(i,1,n) a[i]=read();
    fo(i,1,n-1)
    {
        j=read();k=read();
        add(j,k);add(k,j);
    }
    dfs(1,0);
    fo(i,1,n) zjy[i]=floor(log(i)/log(2));
    fo(j,1,zjy[n]) 
        fo(i,1,n)
        {
            f[i][j]=f[f[i][j-1]][j-1];
            g[i][j]=max(g[i][j-1],g[f[i][j-1]][j-1]);
        }
    tot=0;
    fo(i,2,n)
    {
        t=f[i][0];
        j=zjy[dep[t]];
        k=0;
        while (j>=0)
        {
            if (g[t][j]<=a[i])  t=f[t][j];
            j--;
        }
        if (a[t]>a[i]) add2(t,i);
    }
    fo(i,1,n)
        if (!d[i])
        {
            dp[i]=1;
            dg(i);
        }
    fo(j,1,zjy[n])
        fo(i,1,n)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    while (m--)
    {
        t=read();k=read();l=read();
        j=zjy[dep[t]];
        while (j>=0)
        {
            if (g[t][j]<=l) t=f[t][j];
            j--;
        }
        if (a[t]<=l||dep[t]<dep[k]) printf("0\n");
        else
        {
            ans=dp[t];
            j=zjy[dp[t]];
            while (j>=0)
            {
                if (dep[fa[t][j]]>=dep[k]) t=fa[t][j];
                j--;
            }
            ans-=dp[t];
            ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
