#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[1005][1005];
long long fac[1005],invfac[1005];
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
void init()
{
	fac[0]=invfac[0]=fac[1]=invfac[1]=1;
	for(int i=2;i<=1000;++i)fac[i]=fac[i-1]*i%mod,invfac[i]=quickpower(fac[i],mod-2,mod);
}
int main()
{
	int t;
	scanf("%d",&t);
	init();
	dp[1][0]=1;
	for(int i=2;i<=1000;++i)
		for(int j=0;j<=i;++j)
			{
			for(int k=0;k<=10;++k)
			{
				if(i-k-2<0)break;
				dp[i][j]=(dp[i][j]+dp[i-k-1][j-k]*fac[i-2]%mod*invfac[i-k-2]%mod)%mod;
			}
		}
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		printf("%lld\n",dp[n][m]==0?-1:dp[n][m]);
	}
	return 0;
}
