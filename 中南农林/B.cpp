#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[100005];
int mo[]={0,1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		dp[0]=1;
		for(int i=1;i<=13;++i)
			for(int j=1;j<=n;++j)
				if(j>=mo[i])
					dp[j]=(dp[j]+dp[j-mo[i]])%mod;
		printf("%d\n",dp[n]);
	}
	return 0;
} 
