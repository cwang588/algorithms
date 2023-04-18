#include<bits/stdc++.h>
using namespace std;
map<long long,long long>m;
int main()
{
	int n;
	long long mod,x;
	scanf("%d%lld%lld",&n,&mod,&x);
	long long tot=0;
	m[0]=1;
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		long long t;
		scanf("%lld",&t);
		tot=(tot+t)%mod;
		if(tot>=x)ans+=m[tot-x];
		else ans+=m[tot-x+mod];
		++m[tot];
	}
	printf("%lld\n",ans);
	return 0;
}
