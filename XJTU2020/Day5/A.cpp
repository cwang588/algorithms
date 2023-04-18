#include<bits/stdc++.h>
using namespace std;
long long dp[105][2];
int main()
{
	int l,k;
	scanf("%d%d",&l,&k);
	dp[0][1]=1;
	for(int i=1;i<=l;++i)
	{
		dp[i][1]=dp[i-1][0];
		dp[i][0]+=dp[i-1][1];
		if(i>=k)dp[i][0]+=dp[i-k][1];
	}
	long long ans=0;
	for(int i=1;i<=l;++i)ans+=dp[i][0];
	printf("%lld\n",ans);
	return 0;
}
