#include<cstdio>
#define mod 998244353
using namespace std;
int main()
{
	long long l,r;
	scanf("%lld%lld",&l,&r);
	long long ans1=0,ans2=0;
	for(long long a=1,b;a<=l-1;a=b+1)
	{
		b=(l-1)/((l-1)/a);
		ans1=(ans1+(b-a+1)%mod*(((l-1)/a)%mod)%mod)%mod;
	}
	for(long long a=1,b;a<=r;a=b+1)
	{
		b=r/(r/a);
		ans2=(ans2+(b-a+1)%mod*((r/a)%mod)%mod)%mod;
	}	
	long long ans=(ans2-ans1+mod)%mod;
	
	printf("%lld",ans);
	return 0;
}
