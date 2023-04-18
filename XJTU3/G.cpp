#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long calc(long long x)
{
	return (((x*(x-1)%mod)*(x-2)%mod)*(x-3)%mod*41666667%mod);
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		long long n,m;
		cin>>n>>m;
		printf("Case %d: %lld\n",i,calc(n+1)*calc(m+1)%mod);
	}
	return 0;
}
