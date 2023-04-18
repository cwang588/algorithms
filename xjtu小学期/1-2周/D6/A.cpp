#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[1000006],b[1000006]; 
long long quickpower(int a,int b,int p)
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
	int n,q;
	scanf("%d%d",&n,&q); 
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		b[i]=quickpower(a[i],mod-2,mod);
	}
	a[0]=b[0]=1;
	for(int i=1;i<=n;++i)
	{
		a[i]=a[i-1]*a[i]%mod;
		b[i]=b[i-1]*b[i]%mod;
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",a[r]*b[l-1]%mod);
	}
	return 0;
}
