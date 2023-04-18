#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
bool isPrime[1000008];
vector<long long>Prime;
ll prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll Mul(ll x, ll y, ll MOD)
{
	return ((x*y-(ll)(((long double)x*y)/MOD)*MOD)%MOD+MOD)%MOD;
}
ll Pow(ll x, ll y, ll MOD)
{
    ll res = 1;
    while(y)
    {
        if(y & 1) res = Mul(res, x, MOD);
        x = Mul(x, x, MOD);
        y >>= 1;
    }
    return res;
}

bool Miller_Rabin(ll x)
{
    ll s = 0, t = x - 1;
    if(x == 2)  return true;
    if(x < 2 || !(x & 1))  return false;
    while(!(t & 1))
    {
        s++;
        t >>= 1;
    }
    for(int i = 0; i < 10 && prime[i] < x; i++)
    {
        ll a = prime[i];
        ll b = Pow(a, t, x);
        for(int j = 1; j <= s; j++)
        {
            ll k = Mul(b, b, x);
            if(k == 1 && b != 1 && b != x-1)
              return false;
            b = k;
        }
        if(b != 1)  return false;
    }
    return true;
}
void GetPrime(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i])
            Prime.push_back(i); 
        for(int j = 0; j < Prime.size() && i*Prime[j] <= n; j++) 
        {
            isPrime[ i*Prime[j] ] = 0;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
int main()
{
	GetPrime(maxn);
	int t;
	scanf("%d",&t);
	for(int num=1;num<=t;++num)
	{
		ll n;
		scanf("%lld",&n);
		printf("Case %d: ",num);
		if(n<12)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(n%2)
		{
			printf("2 2 2 3 ");
			n-=9;
		}
		else
		{
			n-=8;
			printf("2 2 2 2 ");
		}
		for(int i=0;i<Prime.size();++i)
			if(Miller_Rabin(n-Prime[i]))
			{
				printf("%lld %lld\n",Prime[i],n-Prime[i]);
				break;
			}
	}
	return 0; 
}
