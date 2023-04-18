#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
char s[1005][1005];
long long dp[1005][1005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>s[i][j];
    dp[1][1]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(s[i][j]=='R')dp[i][j+1]=(dp[i][j]+dp[i][j+1])%mod;
            else if(s[i][j]=='D')dp[i+1][j]=(dp[i][j]+dp[i+1][j])%mod;
            else
            {
                dp[i][j+1]=(dp[i][j]+dp[i][j+1])%mod;
                dp[i+1][j]=(dp[i][j]+dp[i+1][j])%mod;
            }
        }
    cout<<dp[n][m]<<endl;
    return 0;
}
