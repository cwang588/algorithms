#include<cstdio>
using namespace std;
long long gcd(long long a,long long b)
{
	if(a<b)
		return gcd(b,a);
	return b?gcd(b,a%b):a;
}
long long mi(int a,int mod)
{
	long long ans=1,t=10;
	while(a)
	{
		if(a&1)
			ans=(ans*t)%mod;
		t=(t*t)%mod;
		a>>=1;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,m,l,r,f;
		scanf("%lld%lld%lld%lld",&m,&n,&l,&r);
		long long lj=gcd(n,m);
		n/=lj;
		m/=lj;
		long long pre=mi(l-1,n)*m%n;
		for(long long i=l;i<=r;++i)
		{
			pre=(pre%n)*10;
			printf("%lld",pre/n);
		}
		printf("\n");
	}
	return 0;
}
