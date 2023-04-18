#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int dp[1005][1005][11],tot[1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(tot,0,sizeof(tot));
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==1&&m==0)
		{
			printf("1\n");
			continue;
		}
		for(int i=1;i<=n;++i)dp[i][0][0]=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				for(int k=0;k<=10;++k)dp[i][j][0]+=dp[i-1][j][k],dp[i][j][0]%=mod;
				for(int k=1;k<=10;++k)
				{
					long long tmp=(long long)dp[i-1][j-1][k-1]*(i-2)%mod;
					dp[i][j][k]=tmp;
					tot[j]=(tot[j]+dp[i][j][k])%mod;
				}
			}
		long long ans=0;
		for(int i=0;i<=10;++i)ans=(ans+dp[n][m][i])%mod;
		printf("%lld\n",ans==0?-1:ans);
	}
	return 0;
}
