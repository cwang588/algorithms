#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long phi(long long n)
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
long long ans[105];
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
int main()
{
//	freopen("db.txt","w",stdout);
	for(int i=1;i<=10;++i)
	{

		ans[i]=ans[i-1]+phi(i)%mod*quickpower(2,phi(i),mod);
		printf("%lld ",ans[i]);
	}
	return 0;
}
