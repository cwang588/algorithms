#include<bits/stdc++.h>
using namespace std;
char s[45];
long long a[45][45],dp[45][45];
int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>s[i];
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
        {
            long long tmp=0;
            for(int k=i;k<=j;++k)tmp=tmp*10+s[k]-'0';
            a[i][j]=tmp;
        }
    for(int i=1;i<=n;++i)dp[i][1]=a[1][i];
    for(int i=1;i<=n;++i)
        for(int j=2;j<=k;++j)
            for(int k=1;k<i;++k)
                dp[i][j]=max(dp[i][j],dp[k][j-1]*a[k+1][i]);
    printf("%lld\n",dp[n][k]);
    return 0;
} 

