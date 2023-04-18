#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[1005][1005];
char s[10005];
int pre[10005],prenow[350];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		pre[i]=prenow[s[i]];
		prenow[s[i]]=i;
	}
	for(int i=0;i<=n;++i)dp[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j)
		{
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
			if(pre[i]>0)dp[i][j]=(dp[i][j]-dp[pre[i]-1][j-1])%mod;
			dp[i][j]=(dp[i][j]+mod)%mod;
		}
	printf("%lld\n",dp[n][k]);
	return 0;
}
