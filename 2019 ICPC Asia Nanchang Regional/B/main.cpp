#include <bits/stdc++.h>

using namespace std;
char s[25][25],a[25][25];
bool usd[25][25];
long long ans,m[25];
void dfs(int now,int zt,long long tot)
{
    if(now==n)
    {
        if(judge())ans=min(ans,tot);
        return;
    }
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
            if(s[i][j])
            {
                bool ky=true;
                for(int k=1;k<j;++k)
                {
                    if(a[i][j]&&(zt&mi[j]))
                    {
                        ky=false;
                        break;
                    }
                }
                if(ky)
                {
                    usd[i][j]=true;
                    dfs(now+1,zt^mi[j],);
                    usd[i][j]=false;
                }
            }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ans=-1;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                cin>>s[i][j];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                cin>>a[i][j];
        for(int i=1;i<=n;++i)cin>>m[i];
        dfs(0,0,0);
    }
    return 0;
}
