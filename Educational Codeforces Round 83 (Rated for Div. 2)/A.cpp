#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[2000005],inv[2000005];
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
long long calc(int n,int m)
{
	long long re1=0,re2=0;
	re1=((re1+a[m]*inv[m-n+1]%mod)%mod+mod)%mod;
	long long re=re1;
	re=re*quickpower(n-1,mod-2,mod)%mod;
	return re;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==2)return !printf("0\n");
	a[0]=1;
	for(int i=1;i<=m;++i)a[i]=a[i-1]*i%mod;
	inv[m]=quickpower(a[m],mod-2,mod);
	for(int i=m;i>=1;--i)inv[i-1]=inv[i]*i%mod;
	long long ans=0;
	for(int i=2;i<n;++i)
		ans=(ans+inv[i-2]*inv[n-i-1]%mod)%mod;
	ans=ans*calc(n,m)%mod;
	printf("%lld\n",ans);
	return 0;
}
