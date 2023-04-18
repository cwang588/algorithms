#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int main()
{
	long long n,m;
	cin>>n>>m;
	long long ans=0;
	ans+=((2*(n-1)%mod)*(m-2)%mod)*m%mod;
	ans+=((2*(n-2)%mod)*(m-1)%mod)*m%mod;
	ans+=((2*(m-1)%mod)*(n-2)%mod)*n%mod;
	ans+=((2*(m-2)%mod)*(n-1)%mod)*n%mod;
	ans-=(4*(n-2)%mod)*(m-1)%mod;
	ans-=(4*(m-2)%mod)*(n-1)%mod;
	while(ans<0)ans+=mod;
	printf("%lld\n",ans%mod);
	return 0;
}
