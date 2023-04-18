#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[200005],sum[200005];
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
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	a[0]=1,sum[0]=1;
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]*a[i]%mod;
		if(i>=k)
		{
			long long now=quickpower(a[i-k],mod-2,mod);
			sum[i]=(sum[i]*now)%mod;
			ans=max(ans,sum[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
