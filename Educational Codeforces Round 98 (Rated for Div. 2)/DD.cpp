#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[200050],mi[200005];
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
int main(){
	int n;
	scanf("%d",&n);
	a[1]=a[2]=1;
	mi[0]=1;
	for(int i=3;i<=n;++i)a[i]=(a[i-1]+a[i-2])%mod;
	for(int i=1;i<=n;++i)mi[i]=mi[i-1]*2%mod;
	printf("%I64d\n",a[n]*quickpower(mi[n],mod-2,mod)%mod);
	return 0;
}
