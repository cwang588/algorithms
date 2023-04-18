#include<cstdio>
#define mod 1000000007
using namespace std;
bool usd[1000000009];
int main()
{
	long long n,k,ans=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		long long now=(1+(long long)sqrt(1+8*k))/2;
		if(now*(now-1)/2<k)
			++now;
		int l=now,r=n;
		
	}
	return 0;
}
