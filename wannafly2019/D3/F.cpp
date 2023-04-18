#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
long long dp[105][10005];
int main()
{
	long long n,m,h;
	while(cin>>n>>m>>h)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<=m;++i)
			for(int j=0;j<=n;++j)
				for(int k=0;k<=h&&j+k<=n;++k)
					dp[i][j+k]=(dp[i][j+k]+dp[i-1][j])%mod;
		long long ans=0;
		for(int i=0;i<=n;++i)
			ans=(ans+dp[m][i])%mod;
		if(n>m*h)
			ans-=(h+1);
		else
			ans-=(n/m)+1;
		while(ans<0)
			ans+=mod;
		cout<<ans<<endl;
	}
	
	return 0;
}
