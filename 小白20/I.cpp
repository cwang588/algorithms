#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,m;
int total=0;
int inde=0;
int head[500010];
int num[500010],low[500010],tot;
struct edge
{
    int from;
    int to;
    int next;
}inpu[600010];
void add_edge(int a,int b)
{
    total++;
    inpu[total].from=a;
    inpu[total].to=b;
    inpu[total].next=head[a];
    head[a]=total;
}
void dfs(int now,int father)
{
    inde++;
    num[now]=inde;
    low[now]=inde;
    for(int e=head[now];e!=0;e=inpu[e].next)
    {
        if(num[inpu[e].to]==0)
        {
            dfs(inpu[e].to,now);
            low[now]=min(low[now],low[inpu[e].to]);
            if(low[inpu[e].to]>num[now])
                ++tot;
                
        }
        else if(inpu[e].to!=father)
            low[now]=min(low[now],num[inpu[e].to]);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add_edge(a,b); 
        add_edge(b,a);
    }
    dfs(1,1); 
    printf("%d",m-tot);
    return 0;
}
