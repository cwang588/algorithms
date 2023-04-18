#include<bits/stdc++.h>
#define int long long 
using namespace std;
const long long mod=1e9+7;
bool isPrime[2000005];
int Prime[2000005],cnt=0;
void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            Prime[++cnt] = i; 
        for(int j = 1; j <= cnt && i*Prime[j] <= n/*²»³¬ÉÏÏÞ*/; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
long long quickpower(long long a,long long b,long long p)
{
	a%=mod;
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
long long calc(long long p,long long n)
{
	long long now=1;
	long long re=1;
	while(now<=n/p)
	{
		now*=p;
		long long tot=n/now;
		long long t=tot;
		long long tt=tot/p;
		t-=tt;
		re=(re*quickpower(now,t,mod))%mod;
	}
	return re;
}
signed main()
{
	long long n,x,ans=1;
	cin>>x>>n;	
	GetPrime(2000000);
	for(int i=1;i<=cnt;++i)
	{
		if(x<Prime[i])break;
		if(x%Prime[i]==0)ans=(ans*calc(Prime[i],n))%mod;
		while(x%Prime[i]==0)x/=Prime[i];
	}
	if(x>1)ans=(ans*calc(x,n))%mod;
	cout<<ans<<endl;
	return 0;
}
