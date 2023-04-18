#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
char t[105];
int main()
{
	cin>>(t+1);
	int n=strlen(t+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=10000000;
	for(int i=1;i<=n;++i)
		dp[i][i]=1;
	for(int len=2;len<=n;++len)
		for(int i=1;i+len-1<=n;++i)
		{
			int j=i+len-1;
			for(int k=i;k<j;++k)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			if((t[i]=='('&&t[j]==')')||(t[i]=='['&&t[j]==']'))
				dp[i][j]=min(dp[i][j],j-i==1?0:dp[i+1][j-1]);
		}
	printf("%d",dp[1][n]);
	return 0;
}
