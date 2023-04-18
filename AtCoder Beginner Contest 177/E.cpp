#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int m[1000005];
bool isPrime[10000005];
long long Prime[10000005],cnt=0;
void GetPrime(int n)
{
    for(int i=1;i<=n;++i)isPrime[i]=1;
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
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	long long tmp=a[1];
	for(int i=2;i<=n;++i)tmp=gcd(tmp,a[i]);
	if(tmp>1)return !printf("not coprime\n");
	GetPrime(5000005);
	int Max=0;
	for(int i=1;i<=n;++i)
	{
		long long now=a[i];
	//	++m[a[i]];
		for(int j=1;Prime[j]*Prime[j]<=now;++j)
		{
			if(now%Prime[j]==0)
			{
				++m[Prime[j]];
				while(now%Prime[j]==0&&now)now/=Prime[j];
			}
		}
		if(now)++m[now];
	}
	for(int i=2;i<=1000000;++i)Max=max(Max,m[i]);
	if(Max<=1)printf("pairwise coprime\n");
	else if(Max<n)printf("setwise coprime\n");
	else printf("not coprime\n");
	return 0;
}
