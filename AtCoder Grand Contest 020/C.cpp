#include<bits/stdc++.h>
using namespace std;
int a[5005];
bitset<5000005>dp;
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	dp.set(0);
	for(int i=1;i<=n;++i)
			dp|=dp<<a[i];
	for(int i=sum/2;;--i)if(dp[i])return !printf("%d\n",sum-i);
	return 0;
}
