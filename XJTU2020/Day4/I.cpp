#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll ans = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long tmp=gcd(a,b);
	}
	return 0;
} 
