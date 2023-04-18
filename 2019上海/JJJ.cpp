#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long a[305],dp[150005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		int n;
		long long tot=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%lld",&a[i]),tot+=a[i];
		sort(a+1,a+1+n,cmp);
		if(a[1]*2>tot)
		{
			printf("1\n");
			continue;
		}
		long long ans=0;
		dp[0]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=tot;j>=a[i];--j)
			{
				dp[j]=(dp[j]+dp[j-a[i]])%mod;
				if(j*2>=tot&&(j-a[i])<=tot-j)
					ans=(ans+dp[j-a[i]])%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
