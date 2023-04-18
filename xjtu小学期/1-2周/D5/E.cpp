#include<cstdio>
#include<algorithm>
using namespace std;
int B[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int P[16]={44,43,42,41,34,33,32,31,24,23,22,21,14,13,12,11};
int h[2][65536];
bool vis[2][65536];
int g[2][65536];
int fa[2][65536];
int p[2][65536]; 
bool d[2][65536];
int head[2],tail[2]={1,1};
int start,target,s,key;
void print0(int n)
{
    if (n==start) return ;
    print0(fa[0][n]);
    int a=p[0][n],b=p[0][n]-1-3*d[0][n];
    printf("%d%d\n",P[a],P[b]);
}
void print1(int n)
{
    if (n==target) return ;
    int a=p[1][n],b=p[1][n]-1-3*d[1][n];
    printf("%d%d\n",P[a],P[b]);
    print1(fa[1][n]);
}
void record(int n)
{
    printf("%d\n",g[0][n]+g[1][n]);
    print0(n);
    print1(n);
}
void BFS(int x)
{
    head[x]++;
    int num=h[x][head[x]];
    int f,b,n;
    for (int k=15;k>=0;k--)
    {
        if (k%4!=0)
        {
            f=num&B[k];
            b=num&B[k-1];
            n=num+(f>>1)-f+(b<<1)-b;
            if (vis[x][n]==0)
            {
                tail[x]++;
                h[x][tail[x]]=n;
                vis[x][n]=1;
                g[x][n]=g[x][num]+1;
                fa[x][n]=num;
                p[x][n]=k;
                d[x][n]=0;
            } 
        }
        if (vis[0][n]&&vis[1][n]) 
        {
            record(n);
            key=1;
            return;
        }
        if (k>=4)
        {
            f=num&B[k];
            b=num&B[k-4];
            n=num+(f>>4)-f+(b<<4)-b;
            if (vis[x][n]==0)
            {
                tail[x]++;
                h[x][tail[x]]=n;
                vis[x][n]=1;
                g[x][n]=g[x][num]+1;
                fa[x][n]=num;
                p[x][n]=k;
                d[x][n]=1;
            } 
        }
        if (vis[0][n]&&vis[1][n]) 
        {
            record(n);
            key=1;
            return;
        }
    }
}
int main()
{
    for (int i=15;i>=0;i--)
    {
        scanf("%1d",&s);
        start+=s<<i;
    }
    for (int i=15;i>=0;i--)
    {
        scanf("%1d",&s);
        target+=s<<i;
    }
    h[0][1]=start;h[1][1]=target;
    vis[0][start]=1;vis[1][target]=1;
    while (head[0]<tail[0]&&head[1]<tail[1])
    {
        BFS(0);
        if (key) break;
    }
   	return 0;
}
