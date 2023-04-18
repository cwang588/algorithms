#include<bits/stdc++.h>
using namespace std;
long long p[200005];
const long long mod=998244353,hund=828542813;
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
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	long long tot,now=quickpower(100,n,998244353);
	tot=now;
	long long t=1;
	long long ans=now;
	for(int i=1;i<n;++i)
	{
		t=(t*p[i])%mod;
		now=(now*hund)%mod;
		now=(now*p[i])%mod;
		tot=(tot+now)%mod;
	}
	t=(t*p[n])%mod;
	long long tt=quickpower(t,mod-2,mod);
	tot=(tot*tt)%mod;
	cout<<tot<<endl;
	return 0;
}
