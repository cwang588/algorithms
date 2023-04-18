#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[5005][5005];
int a[5005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;++i)scanf("%d",&a[i]);
		dp[1][1]=1;
		for(int i=2;i<=n;++i)
			for(int j=1;j<=i;++j)
			{
				if(a[i-1])dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
				else dp[i][j]=(dp[i][j-1]+dp[i-1][i-1]-dp[i-1][j-1])%mod;
			}
		printf("%lld\n",(dp[n][n]%mod+mod)%mod);
	}
	return 0;
}
