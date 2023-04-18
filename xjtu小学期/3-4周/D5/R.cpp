#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long dp[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	dp[1]=3;
	dp[0]=1;
	for(int i=2;i<=n;++i)
		dp[i]=(dp[i-1]*3%mod+dp[i-2]*36%mod)%mod;
	printf("%lld",dp[n]);
	return 0;
}
