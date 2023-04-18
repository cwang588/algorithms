#include<bits/stdc++.h>
using namespace std;
const long long mod=10007;
long long inv[10005];
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
	long long a,b,c,e,f,g,k;
	cin>>a>>b>>c>>k>>e>>f>>g;
	long long ans=1;
	ans=quickpower(a,e,mod);		
	ans=ans*quickpower(b,f,mod)%mod;		
	ans=ans*quickpower(c,g,mod)%mod;
	inv[1]=1;
	for(int i=2;i<=k;++i)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=k;++i)
		ans=ans*i%mod;
	for(int i=1;i<=e;++i)
		ans=ans*inv[i]%mod;
	for(int i=1;i<=f;++i)
		ans=ans*inv[i]%mod;
	for(int i=1;i<=g;++i)
		ans=ans*inv[i]%mod;
	cout<<ans;
	return 0;
}
