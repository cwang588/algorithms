#include<bits/stdc++.h>
using namespace std;
map<long long,long long>m;
long long a[200005];
long long dp[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)
	{
		dp[i]=a[i]+m[a[i]-i];
		m[(long long)(a[i]-i)]=max(dp[i],m[a[i]-i]);
	}
	long long ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}
