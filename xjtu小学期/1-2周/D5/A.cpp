#include<bits/stdc++.h>
using namespace std;
const long long p=1000000007;
int a[10005];
long long dp[100005];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	dp[1]=1;
	for(int i=1;i<=k;++i)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;++i)
		for(int j=1;j<=k;++j)
			if(i>=a[j]+1)
				dp[i]=(dp[i]+dp[i-a[j]])%p;
	printf("%lld",dp[n]);
	return 0;
}
