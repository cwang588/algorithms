#include<cstdio>
using namespace std;
#define ll long long
#define maxn 2000005
int pre[maxn];
int t,n,m,u,v;
struct node
{
    int pos,same;
} x,y;
node fond(int x)
{
    node ans;
    if(pre[x]==0)
    {
        ans.same=1;
        ans.pos=x;
        return ans;
    }
    else if(pre[x]>0)
    {
        ans=fond(pre[x]);
        if(ans.same)pre[x]=ans.pos;
        else pre[x]=-ans.pos;
        return ans;
    }
    else
    {
        ans=fond(-pre[x]);
        if(ans.same)pre[x]=-ans.pos;
        else pre[x]=ans.pos;
        ans.same=!ans.same;
        return ans;
    }
}
int main()
{
    freopen("meciul.in","r",stdin);
    freopen("meciul.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            pre[i]=0;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            x=fond(u);
            y=fond(v);
            if(x.pos==y.pos)
            {
                if(x.same==y.same)
                    printf("NO\n");
                else
                    printf("YES\n");
                continue;
            }
            if(x.same==y.same)
                pre[x.pos]=-y.pos;
            else
                pre[x.pos]=y.pos;
            printf("YES\n");
        }
    }
    return 0;
}
