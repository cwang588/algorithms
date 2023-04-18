#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
string s[100005];
long long dp[100005][2];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>s[i];
		dp[1][0]=1;
		for(int i=2;i<=n;++i)
		{
			if(s[i]==s[i-1])
			{
				dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
				dp[i][1]=0;
			}
			else
			{
				dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
				dp[i][1]=dp[i-1][0];
			}
		}
		printf("%lld\n",(dp[n][0]+dp[n][1])%mod);
	}
	return 0;
}
