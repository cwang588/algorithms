#include<bits/stdc++.h>
using namespace std;
const long long Mod=100000000;
long long eular(long long n)
{
	long long ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i;
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)ans -= ans/n;
    return ans;
}
long long quickpower(long long a,long long b,long long p)
{
	a%=p;
	b%=p;
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
long long query(long long a,long long re,long long mod)
{
	if(mod==1)
		return 0;
	if(re==1)
		return a%mod;
	long long now=eular(mod);
	return quickpower(a,query(a,re-1,now)+now,Mod)%Mod;
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	long long a,k;
	while(cin>>a>>k)
		printf("%lld\n",query(a,k,Mod)%Mod);
	return 0;
}
