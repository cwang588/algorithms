#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
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
	int t;
	scanf("%d",&t);
	long long tmp=quickpower(100,mod-2,mod);
	while(t--)
	{
		long long m,p,q;
		scanf("%lld%lld%lld",&m,&p,&q);
		p=p*tmp%mod;
		q=q*tmp%mod;
		long long ans=m;
		ans=(ans*quickpower(p,mod-2,mod)%mod+mod-1)%mod;
		ans=ans*q%mod;
		ans=m%mod-ans;
		if(ans<0)ans+=mod;
		printf("%lld\n",ans);
	}
	return 0;
}
