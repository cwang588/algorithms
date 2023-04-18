#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int dp[1005][1005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
			cin>>a[i][j];
	}
	dp[1][1]=a[1][1];
	//dp[n][m]=max(dp[n-1][m-1],dp[n-1][m])+a[n][m];
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}


i=1;
a=(++i);
i=2;a=2;

a=(i++);
i=2;a=1;
