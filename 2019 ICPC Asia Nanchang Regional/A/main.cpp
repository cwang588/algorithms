#include <bits/stdc++.h>
using namespace std;
int pos[1000005],fa[1000005],node[2000005],depth[1000005],sz[1000005];
bool death[1000005];
struct cz
{
    int T;
    int type;
    int x,y;
    int id;
    int ans;
}c[1000005];
int getfa(int x)
{
    return x==fa[x]?x:getfa(fa[x]);
}
void Merge(int x,int y)
{
    int fx=getfa(x),fy=getfa(y);
    if(fx==fy)return;
    if(depth[fx]>depth[fy])swap(fx,fy);
    fa[fx]=fy;
    sz[fy]+=sz[fx];
    if(depth[fx]==depth[fx])++depth[fy];
}
bool cmp1(cz a,cz b)
{
    if(a.T!=b.T)return a.T<b.T;
    return a.id<b.id;
}
bool cmp2(cz a,cz b)
{
    return a.id<b.id;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)fa[i]=i,pos[i]=i,depth[i]=1;
    int cnt=n;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&c[i].type,&c[i].T);
        if(c[i].type==1||c[i].type==3||c[i].type==4)
            scanf("%d%d",&c[i].x,&c[i].y);
        else
            scanf("%d",&c[i].x);
        c[i].id=i;
    }
    sort(c+1,c+1+m,cmp1);
    for(int i=1;i<=m;++i)
    {
        if(c[i].type==1)
        {
            if(!death[c[i].x]&&!death[c[i].y])
                Merge(pos[c[i].x],pos[c[i].y]);
        }
        else if(c[i].type==2)
        {
            --sz[getfa(pos[c[i].x])];
            death[c[i].x]=true;
        }
        else if(c[i].type==3)
        {
            if(!death[c[i].x])
            {
                --sz[getfa(pos[c[i].x])];
                ++cnt;
                pos[c[i].x]=cnt;
                sz[cnt]=depth[cnt]=1;
                Merge(pos[c[i].x],pos[c[i].y]);
            }
        }
        else if(c[i].type==4)
        {
            if(death[c[i].x]||death[c[i].y])c[i].ans=0;
            else
            {
                if(getfa(pos[c[i].x])==getfa(pos[c[i].y]))c[i].ans=1;
                else c[i].ans=0;
            }
        }
        else
        {
            if(death[c[i].x])c[i].ans=0;
            else
            {
                int fx=getfa(c[i].x);
                c[i].ans=sz[fx];
            }
        }
    }
    sort(c+1,c+1+m,cmp2);
    for(int i=1;i<=m;++i)
    {
        if(c[i].type==4)
        {
            if(c[i].ans)printf("Yes\n");
            else printf("No\n");
        }
        else if(c[i].type==5)printf("%d\n",c[i].ans);
        else;
    }
    return 0;
}
