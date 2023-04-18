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
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		long long ans=0;
		ans=(ans+quickpower(4,n,mod))%mod;				
		ans=(ans+quickpower(3,n,mod)*2)%mod;				
	//	ans=(ans+n+1)%mod;				
		long long tmp=quickpower(499122177,n,mod);
		ans=ans*tmp%mod;
		printf("%lld\n",(ans+1)%mod);
	}
	return 0;
} 
